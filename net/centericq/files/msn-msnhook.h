--- src/hooks/msnhook.h.orig	Mon Nov  3 20:25:39 2003
+++ src/hooks/msnhook.h	Mon Nov  3 20:24:23 2003
@@ -0,0 +1,89 @@
+#ifndef __MSNHOOK_H__
+#define __MSNHOOK_H__
+
+#include "abstracthook.h"
+
+#ifdef BUILD_MSN
+
+#include "msn_core.h"
+
+class msnhook : public abstracthook {
+
+    friend void ext_register_sock(int s, int reading, int writing);
+    friend void ext_unregister_sock(int s);
+    friend void ext_new_connection(msnconn *conn);
+    friend void ext_closing_connection(msnconn * conn);
+    friend void ext_buddy_set(msnconn *conn, const char *buddy, const char *friendlyname, const char *status);
+    friend void ext_got_info(msnconn *conn, syncinfo *info);
+    friend void ext_got_friendlyname(msnconn *conn, const char *friendlyname);
+    friend void ext_new_RL_entry(msnconn *conn, const char *username, const char *friendlyname);
+    friend void ext_new_list_entry(msnconn *conn, const char *lst, const char *username);
+    friend void ext_del_list_entry(msnconn *conn, const char *lst, const char *username);
+    friend void ext_got_IM(msnconn *conn, const char *username, const char *friendlyname, message *msg);
+    friend void ext_filetrans_invite(msnconn *conn, const char *username, const char *friendlyname, invitation_ftp *inv);
+    friend void ext_typing_user(msnconn *conn, const char *username, const char *friendlyname);
+    friend void ext_filetrans_progress(invitation_ftp *inv, const char *status, unsigned long sent, unsigned long total);
+    friend void ext_filetrans_failed(invitation_ftp *inv, int error, const char *message);
+    friend void ext_filetrans_success(invitation_ftp *inv);
+
+    protected:
+	imstatus ourstatus;
+	bool fonline, flogged;
+	msnconn conn;
+
+	vector<int> rfds, wfds;
+	map<string, string> friendlynicks;
+	map<string, vector<pair<string, string> > > slst;
+	map<imfile, pair<invitation_ftp *, string> > transferinfo;
+
+	void checkfriendly(icqcontact *c, const string friendlynick,
+	    bool forcefetch = false);
+
+	void checkinlist(imcontact ic);
+
+	void removeuser(const imcontact &ic, bool report);
+	bool getfevent(invitation_ftp *fhandle, imfile &fr);
+
+    public:
+	msnhook();
+	~msnhook();
+
+	void init();
+
+	void connect();
+	void disconnect();
+	void exectimers();
+	void main();
+
+	void getsockets(fd_set &rf, fd_set &wf, fd_set &ef, int &hsocket) const;
+	bool isoursocket(fd_set &rf, fd_set &wf, fd_set &ef) const;
+
+	bool online() const;
+	bool logged() const;
+	bool isconnecting() const;
+	bool enabled() const;
+
+	bool send(const imevent &ev);
+
+	void sendnewuser(const imcontact &c);
+	void removeuser(const imcontact &ic);
+	void requestinfo(const imcontact &ic);
+
+	void sendupdateuserinfo(const icqcontact &c);
+
+	void setautostatus(imstatus st);
+	imstatus getstatus() const;
+
+	void lookup(const imsearchparams &params, verticalmenu &dest);
+	vector<icqcontact *> getneedsync();
+
+	bool knowntransfer(const imfile &fr) const;
+	void replytransfer(const imfile &fr, bool accept, const string &localpath = string());
+	void aborttransfer(const imfile &fr);
+};
+
+extern msnhook mhook;
+
+#endif
+
+#endif
