# New ports collection makefile for:	bb
# Version required:     1.04H
# Date created:         So  17 Nov 1996 16:59:23 MET
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.29 1998/09/22 17:22:12 asami Exp $
#

DISTNAME=	bb-1.08a
CATEGORIES=	net
MASTER_SITES=	http://maclawran.ca/~sean/bb-dnld/ \
		http://freefall.freebsd.org/~andreas/download/

MAINTAINER=	andreas@FreeBSD.ORG

# The FreeBSD Ports Team has permission to include this in our CDROM
# from the author, but others who wish to do likewise will have to
# contact Sean MacGuire <sean@iti.qc.ca>.

WRKSRC=		${WRKDIR}/bb

pre-configure:
	@echo "==================================================="
	@echo "You need to install a WWW Server to use this port"
	@echo "For example: - apache13 or "
	@echo "             - apache13-modssl
	@echo "port."
	@echo "==================================================="

post-configure:
	( cd ${WRKSRC}/doc; ${SH} bbconfig freebsd )
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/www/cgi-bin
	@${MKDIR} ${PREFIX}/www/data
	@${MKDIR} ${PREFIX}/bb/bin
	@${MKDIR} ${PREFIX}/bb/etc
	@${MKDIR} ${PREFIX}/bb/web
	@${MKDIR} ${PREFIX}/bb/www/gifs
	@${MKDIR} ${PREFIX}/bb/www/logs
	@${MKDIR} ${PREFIX}/bb/www/notes
	@${MKDIR} ${PREFIX}/bb/tmp
	@${MKDIR} ${PREFIX}/share/doc/bb
	@${TOUCH} ${PREFIX}/bb/tmp/.keep_me
	${INSTALL_SCRIPT} ${WRKSRC}/runbb.sh \
				${PREFIX}/bb
	${INSTALL_DATA} ${WRKSRC}/README \
				${PREFIX}/bb/README
.for file in	bb-local.sh bb-network.sh bb-page.sh sendmsg
	${INSTALL_SCRIPT} ${WRKSRC}/bin/$(file) \
		${PREFIX}/bb/bin
.endfor
.for file in	bb bbd bbnet touchtime
	${INSTALL_PROGRAM} ${WRKSRC}/bin/$(file) \
		${PREFIX}/bb/bin
.endfor
.for file in	FAQ README README.SMS STRUCTURE bbclient bbconfig
	${INSTALL_DATA} ${WRKSRC}/doc/$(file) \
		${PREFIX}/share/doc/bb
.endfor
.for file in	bb-hosts bbdef.sh bbinc.sh bbsys.aix bbsys.freebsd bbsys.hpux \
		bbsys.hpux9 bbsys.irix bbsys.linux bbsys.local bbsys.netbsd \
		bbsys.osf bbsys.redhat bbsys.sco bbsys.sco3 bbsys.sh \
		bbsys.solaris bbsys.sunos bbsys.ultrix bbsys.unixware \
		numeric.scr security.INFO sms.scr
	${INSTALL_DATA} ${WRKSRC}/etc/$(file) \
		${PREFIX}/bb/etc
.endfor
.for file in	mkbb.bkg mkbb.cols mkbb.comp mkbb.sh mkbb2.sh
	${INSTALL_SCRIPT} ${WRKSRC}/web/$(file) \
		${PREFIX}/bb/web
.endfor
.for file in	bb-faq.html bb-help.html bb-info.html bb-page.html
	${INSTALL_DATA} ${WRKSRC}/www/$(file) \
		${PREFIX}/bb/www
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/www/bb-pager.sh \
				${PREFIX}/www/cgi-bin/bb-pager.sh
.for file in	bb-diag.gif bb.gif bb2.gif bbbut.gif bkg-green.gif \
		bkg-purple.gif bkg-red.gif bkg-yellow.gif blue.gif \
		buthelp.gif butinfo.gif butpage.gif butview.gif clear.gif \
		green.gif nb-bbbut.gif nb-red.gif nb-yellow.gif purple.gif \
		red.gif yellow.gif
	${INSTALL_DATA} ${WRKSRC}/www/gifs/$(file) \
		${PREFIX}/bb/www/gifs
.endfor
	${INSTALL_DATA} ${WRKSRC}/www/logs/later \
				${PREFIX}/bb/www/logs/later
.for file in	README footer iti-s01 iti-s01.html iti-s01.iti.qc.ca \
		iti-s01.iti.qc.ca.html router-000.htm
	${INSTALL_DATA} ${WRKSRC}/www/notes/$(file) \
		${PREFIX}/bb/www/notes
.endfor
	@${LN} -fs ${PREFIX}/bb/www ${PREFIX}/www/data/bb
	@${LN} -fs bb.html ${PREFIX}/bb/www/index.html
	@echo ""
	@echo "================================================================"
	@echo "==== Configuration Notes:                                    ==="
	@echo "================================================================"
	@echo ""
	@echo "a) your hosts 'full qualified domain name' and IP-address"
	@echo "b) 'watched' hosts 'full qualified domain name' and IP-address"
	@echo "go here -> ${PREFIX}/bb/etc/bb-hosts"
	@echo ""
	@echo "c) configure -> ${PREFIX}/bb/etc/bbdef.sh"
	@echo "d) configure -> ${PREFIX}/bb/etc/bbinc.sh"
	@echo ""
	@echo "e) You need to have a running WWW server (apache)"
	@echo "f) You need kermit or qpage for pager functionality"
	@echo ""
	@echo "After that, you can startup the big brother service by typing"
	@echo "        ${PREFIX}/bb/runbb.sh &"
	@echo ""
	@echo "and watching your systems status by viewing this URL with"
	@echo "Netscape or another WWW browser"
	@echo "        http://localhost/bb"
	@echo ""
	@echo "Look here for a life sample:"
	@echo "        http://maclawran.ca/bb/bb.html"
	@echo ""

.include <bsd.port.mk>
