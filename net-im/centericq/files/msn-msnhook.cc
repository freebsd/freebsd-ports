--- src/hooks/msnhook.cc.orig	Sat Jan 17 17:01:03 2004
+++ src/hooks/msnhook.cc	Sat Jan 17 17:05:45 2004
@@ -0,0 +1,801 @@
+/*
+*
+* centericq MSN protocol handling class
+* $Id: msnhook.cc,v 1.67 2003/09/30 11:38:43 konst Exp $
+*
+* Copyright (C) 2001 by Konstantin Klyagin <konst@konst.org.ua>
+*
+* This program is free software; you can redistribute it and/or modify
+* it under the terms of the GNU General Public License as published by
+* the Free Software Foundation; either version 2 of the License, or (at
+* your option) any later version.
+*
+* This program is distributed in the hope that it will be useful, but
+* WITHOUT ANY WARRANTY; without even the implied warranty of
+* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+* General Public License for more details.
+*
+* You should have received a copy of the GNU General Public License
+* along with this program; if not, write to the Free Software
+* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
+* USA
+*
+*/
+
+#include "icqcommon.h"
+
+#ifdef BUILD_MSN
+
+#include "msnhook.h"
+#include "icqconf.h"
+#include "icqface.h"
+#include "icqcontacts.h"
+#include "accountmanager.h"
+#include "eventmanager.h"
+#include "imlogger.h"
+#include "connwrap.h"
+
+#include "msn_bittybits.h"
+
+#include <unistd.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <netdb.h>
+#include <arpa/inet.h>
+
+msnhook mhook;
+
+static string nicknormalize(const string &nick) {
+    if(nick.find("@") == -1) return nick + "@hotmail.com";
+    return nick;
+}
+
+static string nicktodisp(const string &nick) {
+    int pos;
+    string r = nick;
+
+    if((pos = r.find("@")) != -1)
+    if(r.substr(pos+1) == "hotmail.com")
+	r.erase(pos);
+
+    return r;
+}
+
+struct st2imr {
+    char *name;
+    imstatus st;
+};
+
+const st2imr st2im[] = {
+    { "FLN", offline },
+    { "NLN", available },
+    { "HDN", invisible },
+    { "BSY", dontdisturb },
+    { "PHN", occupied },
+    { "AWY", away },
+    { "BRB", away },
+    { "LUN", notavail },
+    { "IDL", away },
+    { 0, offline }
+};
+
+static imstatus msn2imstatus(const string &sname) {
+    for(const st2imr *sa = st2im; sa->name; sa++)
+	if(sname == sa->name)
+	    return sa->st;
+
+    return offline;
+}
+
+static const char *stat2name(imstatus st) {
+    for(const st2imr *sa = st2im; sa->name; sa++)
+	if(st == sa->st)
+	    return sa->name;
+
+    return "NLN";
+}
+
+// ----------------------------------------------------------------------------
+
+msnhook::msnhook(): abstracthook(msn) {
+    ourstatus = offline;
+    fonline = false;
+
+//    fcapabs.insert(hookcapab::synclist); // removed from 4.9.10
+    fcapabs.insert(hookcapab::changedetails);
+    fcapabs.insert(hookcapab::directadd);
+//    fcapabs.insert(hookcapab::files);
+}
+
+msnhook::~msnhook() {
+}
+
+void msnhook::init() {
+    manualstatus = conf.getstatus(msn);
+}
+
+void msnhook::connect() {
+    icqconf::imaccount account = conf.getourid(msn);
+
+    face.log(_("+ [msn] connecting to the server"));
+
+    flogged = false;
+    fonline = true;
+
+    msn_init(&conn, nicknormalize(account.nickname).c_str(), account.password.c_str());
+    msn_connect(&conn, account.server.c_str(), account.port);
+
+    fonline = true;
+    flogged = true;
+}
+
+void msnhook::disconnect() {
+    msn_clean_up(&conn);
+}
+
+void msnhook::exectimers() {
+}
+
+void msnhook::main() {
+    vector<int>::const_iterator i;
+    fd_set rs, ws;
+    struct timeval tv;
+    int hsock;
+
+    FD_ZERO(&rs);
+    FD_ZERO(&ws);
+
+    tv.tv_sec = tv.tv_usec = 0;
+    hsock = 0;
+
+    for(i = rfds.begin(); i != rfds.end(); ++i) {
+	FD_SET(*i, &rs);
+	hsock = max(hsock, *i);
+    }
+
+    for(i = wfds.begin(); i != wfds.end(); ++i) {
+	FD_SET(*i, &ws);
+	hsock = max(hsock, *i);
+    }
+
+    if(select(hsock+1, &rs, &ws, 0, &tv) > 0) {
+	for(i = rfds.begin(); i != rfds.end(); ++i)
+	    if(FD_ISSET(*i, &rs)) {
+		msn_handle_incoming(*i, 1, 0);
+		return;
+	    }
+
+	for(i = wfds.begin(); i != wfds.end(); ++i)
+	    if(FD_ISSET(*i, &ws)) {
+		msn_handle_incoming(*i, 0, 1);
+		return;
+	    }
+    }
+}
+
+void msnhook::getsockets(fd_set &rf, fd_set &wf, fd_set &efds, int &hsocket) const {
+    vector<int>::const_iterator i;
+
+    for(i = rfds.begin(); i != rfds.end(); ++i) {
+	hsocket = max(hsocket, *i);
+	FD_SET(*i, &rf);
+    }
+
+    for(i = wfds.begin(); i != wfds.end(); ++i) {
+	hsocket = max(hsocket, *i);
+	FD_SET(*i, &wf);
+    }
+}
+
+bool msnhook::isoursocket(fd_set &rf, fd_set &wf, fd_set &efds) const {
+    vector<int>::const_iterator i;
+
+    for(i = rfds.begin(); i != rfds.end(); ++i)
+	if(FD_ISSET(*i, &rf))
+	    return true;
+
+    for(i = wfds.begin(); i != wfds.end(); ++i)
+	if(FD_ISSET(*i, &wf))
+	    return true;
+
+    return false;
+}
+
+bool msnhook::online() const {
+    return fonline;
+}
+
+bool msnhook::logged() const {
+    return fonline && flogged;
+}
+
+bool msnhook::isconnecting() const {
+    return fonline && !flogged;
+}
+
+bool msnhook::enabled() const {
+    return true;
+}
+
+bool msnhook::send(const imevent &ev) {
+    string text;
+
+    if(ev.gettype() == imevent::message) {
+	const immessage *m = static_cast<const immessage *>(&ev);
+	if(m) text = m->gettext();
+
+    } else if(ev.gettype() == imevent::url) {
+	const imurl *m = static_cast<const imurl *>(&ev);
+	if(m) text = m->geturl() + "\n\n" + m->getdescription();
+
+    } else if(ev.gettype() == imevent::file) {
+	const imfile *m = static_cast<const imfile *>(&ev);
+	vector<imfile::record> files = m->getfiles();
+	vector<imfile::record>::const_iterator ir;
+
+	for(ir = files.begin(); ir != files.end(); ++ir) {
+	    imfile::record r;
+	    invitation_ftp *p;
+
+	    r.fname = ir->fname;
+	    r.size = ir->size;
+
+	    imfile fr(ev.getcontact(), imevent::outgoing, "", vector<imfile::record>(1, r));
+
+	    if(p = msn_filetrans_send(&conn, ir->fname.c_str()))
+		transferinfo[fr].first = p;
+	}
+
+	return true;
+    }
+
+    icqcontact *c = clist.get(ev.getcontact());
+    text = siconv(text, conf.getrussian(msn) ? "koi8-u" : conf.getdefcharset(), "utf-8");
+
+    if(c)
+    if(c->getstatus() != offline || !c->inlist()) {
+	msn_send_IM(&conn, nicknormalize(ev.getcontact().nickname).c_str(), text.c_str());
+	return true;
+    }
+
+    return false;
+}
+
+void msnhook::sendnewuser(const imcontact &ic) {
+    if(logged()) {
+	icqcontact *c;
+	imcontact icc(nicktodisp(ic.nickname), msn);
+
+	if(icc.nickname != ic.nickname)
+	if(c = clist.get(ic)) {
+	    c->setdesc(icc);
+	    c->setnick(icc.nickname);
+	    c->setdispnick(icc.nickname);
+	}
+
+	msn_add_to_list(&conn, "FL", nicknormalize(ic.nickname).c_str());
+    }
+
+    requestinfo(ic);
+}
+
+void msnhook::setautostatus(imstatus st) {
+    if(st != offline) {
+	if(getstatus() == offline) {
+	    connect();
+	} else {
+	    logger.putourstatus(msn, ourstatus, st);
+	    msn_set_state(&conn, stat2name(ourstatus = st));
+	}
+    } else {
+	if(getstatus() != offline) {
+	    disconnect();
+	}
+    }
+}
+
+imstatus msnhook::getstatus() const {
+    return online() ? ourstatus : offline;
+}
+
+void msnhook::removeuser(const imcontact &ic) {
+    removeuser(ic, true);
+}
+
+void msnhook::removeuser(const imcontact &ic, bool report) {
+    if(online()) {
+	if(report)
+	    face.log(_("+ [msn] removing %s from the contacts"), ic.nickname.c_str());
+
+	msn_del_from_list(&conn, "FL", nicknormalize(ic.nickname).c_str());
+    }
+}
+
+void msnhook::requestinfo(const imcontact &ic) {
+    icqcontact *c = clist.get(ic);
+
+    if(!c) {
+	c = clist.get(contactroot);
+	c->clear();
+    }
+
+    icqcontact::moreinfo m = c->getmoreinfo();
+    icqcontact::basicinfo b = c->getbasicinfo();
+
+    b.email = nicknormalize(ic.nickname);
+    m.homepage = "http://members.msn.com/" + b.email;
+
+    if(ic.nickname == conf.getourid(msn).nickname)
+	c->setnick(friendlynicks[ic.nickname]);
+
+    c->setmoreinfo(m);
+    c->setbasicinfo(b);
+}
+
+void msnhook::lookup(const imsearchparams &params, verticalmenu &dest) {
+    if(params.reverse) {
+	vector<pair<string, string> >::const_iterator i = slst["RL"].begin();
+
+	while(i != slst["RL"].end()) {
+	    icqcontact *c = new icqcontact(imcontact(nicktodisp(i->first), msn));
+	    c->setnick(i->second);
+
+	    dest.additem(conf.getcolor(cp_clist_msn), c, (string) " " + i->first);
+	    ++i;
+	}
+	face.findready();
+
+	face.log(_("+ [msn] reverse users listing finished, %d found"),
+	    slst["RL"].size());
+
+	dest.redraw();
+    }
+}
+
+vector<icqcontact *> msnhook::getneedsync() {
+    int i;
+    vector<icqcontact *> r;
+    bool found;
+
+    for(i = 0; i < clist.count; i++) {
+	icqcontact *c = (icqcontact *) clist.at(i);
+
+	if(c->getdesc().pname == msn) {
+	    vector<pair<string, string> >::const_iterator fi = slst["FL"].begin();
+
+	    for(found = false; fi != slst["FL"].end() && !found; ++fi)
+		found = c->getdesc().nickname == fi->first;
+
+	    if(!found)
+		r.push_back(c);
+	}
+    }
+
+    return r;
+}
+
+void msnhook::sendupdateuserinfo(const icqcontact &c) {
+    msn_set_friendlyname(&conn, c.getnick().c_str());
+}
+
+void msnhook::checkfriendly(icqcontact *c, const string friendlynick, bool forcefetch) {
+    string oldnick = c->getnick();
+    string newnick = siconv(unmime(friendlynick), "utf-8", conf.getrussian(msn) ? "koi8-u" : conf.getdefcharset());
+
+    c->setnick(newnick);
+
+    if(forcefetch || (oldnick != newnick && c->getdispnick() != oldnick) || oldnick.empty()) {
+	c->setdispnick(newnick);
+	face.relaxedupdate();
+    }
+}
+
+void msnhook::checkinlist(imcontact ic) {
+    icqcontact *c = clist.get(ic);
+    vector<icqcontact *> notremote = getneedsync();
+
+    if(c)
+    if(c->inlist())
+    if(find(notremote.begin(), notremote.end(), c) != notremote.end())
+	mhook.sendnewuser(ic);
+}
+
+bool msnhook::knowntransfer(const imfile &fr) const {
+    return transferinfo.find(fr) != transferinfo.end();
+}
+
+void msnhook::replytransfer(const imfile &fr, bool accept, const string &localpath) {
+    if(accept) {
+	transferinfo[fr].second = localpath;
+
+	if(transferinfo[fr].second.substr(transferinfo[fr].second.size()-1) != "/")
+	    transferinfo[fr].second += "/";
+
+	transferinfo[fr].second += justfname(fr.getfiles().begin()->fname);
+	msn_filetrans_accept(transferinfo[fr].first, transferinfo[fr].second.c_str());
+
+    } else {
+	msn_filetrans_reject(transferinfo[fr].first);
+	transferinfo.erase(fr);
+
+    }
+}
+
+void msnhook::aborttransfer(const imfile &fr) {
+    msn_filetrans_reject(transferinfo[fr].first);
+
+    face.transferupdate(fr.getfiles().begin()->fname, fr,
+	icqface::tsCancel, 0, 0);
+
+    transferinfo.erase(fr);
+}
+
+bool msnhook::getfevent(invitation_ftp *fhandle, imfile &fr) {
+    map<imfile, pair<invitation_ftp *, string> >::const_iterator i = transferinfo.begin();
+
+    while(i != transferinfo.end()) {
+	if(i->second.first == fhandle) {
+	    fr = i->first;
+	    return true;
+	}
+	++i;
+    }
+
+    return false;
+}
+
+// ----------------------------------------------------------------------------
+
+static void log(const string &s) {
+#ifdef DEBUG
+    face.log(s);
+#endif
+}
+
+int ext_debug( char *str )
+{
+    log( str );
+    return 0;
+}
+
+void ext_register_sock(int s, int reading, int writing) {
+    log("ext_register_sock");
+    if(reading) mhook.rfds.push_back(s);
+    if(writing) mhook.wfds.push_back(s);
+}
+
+void ext_unregister_sock(int s) {
+    log("ext_unregister_sock");
+    vector<int>::iterator i;
+
+    i = find(mhook.rfds.begin(), mhook.rfds.end(), s);
+    if(i != mhook.rfds.end()) mhook.rfds.erase(i);
+
+    i = find(mhook.wfds.begin(), mhook.wfds.end(), s);
+    if(i != mhook.wfds.end()) mhook.wfds.erase(i);
+}
+
+void ext_got_friendlyname(msnconn * conn, const char * friendlyname) {
+    log("ext_got_friendlyname");
+
+    if(friendlyname)
+    if(strlen(friendlyname))
+	mhook.friendlynicks[conf.getourid(msn).nickname] = friendlyname;
+}
+
+void ext_got_info(msnconn *conn, syncinfo *info) {
+    log("ext_got_info");
+
+    userdata *ud;
+    llist *lst, *pl;
+    imcontact ic;
+
+    for(lst = info->fl; lst; lst = lst->next) {
+	ud = (userdata *) lst->data;
+
+	mhook.slst["FL"].push_back(make_pair(ud->username, ud->friendlyname));
+
+	ic = imcontact(nicktodisp(ud->username), msn);
+	icqcontact *c = clist.get(ic);
+	if(!c) c = clist.addnew(ic, false);
+
+	icqcontact::basicinfo bi = c->getbasicinfo();
+	icqcontact::workinfo wi = c->getworkinfo();
+
+	for(pl = ud->phone; pl; pl = pl->next) {
+	    phonedata *pd = (phonedata *) pl->data;
+	    string title = pd->title ? pd->title : "";
+
+	    if(pd->number)
+	    if(strlen(pd->number)) {
+		if(title == "PHH") bi.phone = pd->number; else
+		if(title == "PHW") wi.phone = pd->number; else
+		if(title == "PHM") bi.cellular = pd->number;
+	    }
+	}
+
+	c->setbasicinfo(bi);
+	c->setworkinfo(wi);
+    }
+
+    for(lst = info->rl; lst; lst = lst->next) {
+	ud = (userdata *) lst->data;
+	mhook.slst["RL"].push_back(make_pair(ud->username, ud->friendlyname));
+    }
+
+    mhook.setautostatus(mhook.ourstatus);
+}
+
+void ext_latest_serial(msnconn * conn, int serial) {
+    log("ext_latest_serial");
+}
+
+void ext_got_GTC(msnconn * conn, char c) {
+    log("ext_got_GTC");
+}
+
+void ext_got_BLP(msnconn * conn, char c) {
+    log("ext_got_BLP");
+}
+
+void ext_new_RL_entry(msnconn *conn, const char *username, const char *friendlyname) {
+    log("ext_new_RL_entry");
+    msn_add_to_list(&mhook.conn, "AL", username);
+
+    imcontact ic(nicktodisp(username), msn);
+    mhook.checkinlist(ic);
+    em.store(imnotification(ic, _("The user has added you to his/her contact list")));
+}
+
+void ext_new_list_entry(msnconn *conn, const char *lst, const char *username) {
+    log("ext_new_list_entry");
+    mhook.slst[lst].push_back(make_pair(username, string()));
+}
+
+void ext_del_list_entry(msnconn *conn, const char *lst, const char *username) {
+    log("ext_del_list_entry");
+
+    vector<pair<string, string> >::iterator i = mhook.slst[lst].begin();
+    while(i != mhook.slst[lst].end()) {
+	if(i->first == username) {
+	    mhook.slst[lst].erase(i);
+	    i = mhook.slst[lst].begin();
+	} else {
+	    ++i;
+	}
+    }
+}
+
+void ext_show_error(msnconn * conn, const char * msg) {
+    log("ext_show_error");
+    log(msg);
+}
+
+void ext_buddy_set(msnconn * conn, const char * buddy, const char * friendlyname, const char * status) {
+    log("ext_buddy_set");
+    imcontact ic(nicktodisp(buddy), msn);
+    icqcontact *c = clist.get(ic);
+    bool forcefetch;
+
+    if(forcefetch = !c)
+	c = clist.addnew(ic, false);
+
+    if(friendlyname)
+	mhook.checkfriendly(c, friendlyname, forcefetch);
+
+    logger.putonline(ic, c->getstatus(), msn2imstatus(status));
+    c->setstatus(msn2imstatus(status));
+}
+
+void ext_buddy_offline(msnconn * conn, const char * buddy) {
+    log("ext_buddy_offline");
+    ext_buddy_set(conn, buddy, 0, "FLN");
+}
+
+void ext_got_SB(msnconn * conn, void * tag) {
+    log("ext_got_SB");
+}
+
+void ext_user_joined(msnconn *conn, const char *username, const char *friendlyname, int is_initial) {
+    log("ext_user_joined");
+}
+
+void ext_user_left(msnconn *conn, const char *username) {
+    log("ext_user_left");
+}
+
+void ext_got_IM(msnconn *conn, const char *username, const char *friendlyname, message *msg) {
+    log("ext_got_IM");
+    imcontact ic(nicktodisp(username), msn);
+
+    mhook.checkinlist(ic);
+
+    string text = siconv(msg->body, "utf-8", conf.getrussian(msn) ? "koi8-u" : conf.getdefcharset());
+    em.store(immessage(ic, imevent::incoming, text));
+}
+
+void ext_IM_failed(msnconn *conn) {
+    log("ext_IM_failed");
+}
+
+void ext_typing_user(msnconn *conn, const char *username, const char *friendlyname) {
+    log("ext_typing_user");
+    icqcontact *c = clist.get(imcontact(nicktodisp(username), msn));
+    if(c) c->setlasttyping(timer_current);
+}
+
+void ext_initial_email(msnconn *conn, int unread_inbox, int unread_folders) {
+    log("ext_initial_email");
+
+    face.log(_("+ [msn] unread e-mail: %d in inbox, %d in folders"),
+	unread_inbox, unread_folders);
+}
+
+void ext_new_mail_arrived(msnconn *conn, const char *from, const char *subject) {
+    log("ext_new_mail_arrived");
+
+    face.log(_("+ [msn] e-mail from %s, %s"), from, subject);
+    clist.get(contactroot)->playsound(imevent::email);
+}
+
+void ext_filetrans_invite(msnconn *conn, const char *username, const char *friendlyname, invitation_ftp *inv) {
+    log("ext_filetrans_invite");
+
+    if(!mhook.fcapabs.count(hookcapab::files))
+	return;
+
+    imfile::record r;
+    r.fname = inv->filename;
+    r.size = inv->filesize;
+
+    imcontact ic(nicktodisp(username), msn);
+    mhook.checkinlist(ic);
+
+    imfile fr(ic, imevent::incoming, "", vector<imfile::record>(1, r));
+
+    mhook.transferinfo[fr].first = inv;
+    em.store(fr);
+
+    face.transferupdate(inv->filename, fr, icqface::tsInit, inv->filesize, 0);
+}
+
+void ext_filetrans_progress(invitation_ftp *inv, const char *status, unsigned long sent, unsigned long total) {
+    log("ext_filetrans_progress");
+    imfile fr;
+
+    if(mhook.getfevent(inv, fr)) {
+	face.transferupdate(fr.getfiles().begin()->fname, fr,
+	    icqface::tsProgress, total, sent);
+    }
+}
+
+void ext_filetrans_failed(invitation_ftp *inv, int error, const char *message) {
+    log("ext_filetrans_failed");
+    imfile fr;
+
+    if(mhook.getfevent(inv, fr)) {
+	face.transferupdate(fr.getfiles().begin()->fname, fr, icqface::tsError, 0, 0);
+	mhook.transferinfo.erase(fr);
+    }
+}
+
+void ext_filetrans_success(invitation_ftp *inv) {
+    log("ext_filetrans_success");
+    imfile fr;
+
+    if(mhook.getfevent(inv, fr)) {
+	face.transferupdate(fr.getfiles().begin()->fname, fr, icqface::tsFinish, 0, 0);
+	mhook.transferinfo.erase(fr);
+    }
+}
+
+void ext_new_connection(msnconn *conn) {
+    log("ext_new_connection");
+    if(conn->type == CONN_NS) {
+	msn_sync_lists(conn, 0);
+	logger.putourstatus(msn, offline, mhook.ourstatus = mhook.manualstatus);
+	mhook.flogged = true;
+	face.log(_("+ [msn] logged in"));
+	face.update();
+    }
+}
+
+void ext_closing_connection(msnconn *conn) {
+    log("ext_closing_connection");
+    if(conn->type == CONN_NS) {
+	mhook.rfds.clear();
+	mhook.wfds.clear();
+	logger.putourstatus(msn, mhook.getstatus(), mhook.ourstatus = offline);
+	clist.setoffline(msn);
+	mhook.fonline = false;
+	mhook.slst.clear();
+	face.log(_("+ [msn] disconnected"));
+	face.update();
+    }
+}
+
+void ext_changed_state(msnconn *conn, const char *state) {
+    log("ext_changed_state");
+}
+
+int ext_do_connect_socket(const char *hostname, int port, int ssl) {
+    struct sockaddr_in sa;
+    struct hostent *hp;
+    int a, s;
+    string msgerr = _("+ [msn] cannot connect: ");
+
+    hp = gethostbyname(hostname);
+    if(!hp) {
+	face.log(msgerr + _("could not resolve hostname"));
+	errno = ECONNREFUSED;
+	return -1;
+    }
+
+    memset(&sa, 0, sizeof(sa));
+    memcpy((char *) &sa.sin_addr, hp->h_addr, hp->h_length);
+    sa.sin_family = hp->h_addrtype;
+    sa.sin_port = htons((u_short) port);
+
+    if((s = socket(hp->h_addrtype, SOCK_STREAM, 0)) < 0)
+	return -1;
+
+    if(cw_connect(s, (struct sockaddr *) &sa, sizeof(sa), ssl) < 0) {
+	face.log(msgerr + _("verify the hostname and port"));
+	close(s);
+	return -1;
+    }
+
+    return s;
+}
+
+int ext_connect_socket_ssl(const char *hostname, int port) {
+        log("ext_connect_socket_ssl");
+        return ext_do_connect_socket(hostname, port, 1);
+}
+
+int ext_connect_socket(const char *hostname, int port) {
+        log("ext_connect_socket");
+        return ext_do_connect_socket(hostname, port, 0);
+}
+
+int ext_server_socket(int port) {
+    log("ext_server_socket");
+    int s;
+    struct sockaddr_in addr;
+
+    if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)
+	return -1;
+
+    memset(&addr, 0, sizeof(addr));
+    addr.sin_family = AF_INET;
+    addr.sin_port = htons(port);
+
+    if(bind(s, (sockaddr *) &addr, sizeof(addr)) < 0 || listen(s, 1) < 0) {
+	close(s);
+	return -1;
+    }
+
+    return s;
+}
+
+char *ext_get_IP() {
+    log("ext_get_IP");
+    struct hostent *hn;
+    char buf2[1024];
+
+    gethostname(buf2, 1024);
+    hn = gethostbyname(buf2);
+
+    return inet_ntoa(*((struct in_addr*) hn->h_addr));
+}
+
+void ext_protocol_log(const char *buf, int readev, int writeev) {
+    if(readev) {
+	log(string("[IN] ") + buf);
+    } else if(writeev) {
+	log(string("[OUT] ") + buf);
+    }
+}
+
+#endif
