# New ports collection makefile for:	bb
# Version required:     0.9
# Date created:         So  17 Nov 1996 16:59:23 MET
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.3 1996/11/26 09:15:36 asami Exp $
#

DISTNAME=	bb
PKGNAME=	bb-0.9
CATEGORIES=	net
MASTER_SITES=	http://www.iti.qc.ca/iti/users/sean/bb-dnld/
EXTRACT_SUFX=   -src.tgz

MAINTAINER=	andreas@klemm.gtn.com

BUILD_DEPENDS=	${PREFIX}/sbin/httpd:${PORTSDIR}/www/apache
RUN_DEPENDS=	lyx:${PORTSDIR}/print/lyx

post-configure:
	( cd ${WRKSRC}/doc; /bin/sh bbconfig freebsd )
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/${DISTNAME}/bin
	@${MKDIR} ${PREFIX}/${DISTNAME}/doc
	@${MKDIR} ${PREFIX}/${DISTNAME}/etc
	@${MKDIR} ${PREFIX}/${DISTNAME}/web
	@${MKDIR} ${PREFIX}/${DISTNAME}/www/gifs
	@${MKDIR} ${PREFIX}/${DISTNAME}/www/logs
	@${MKDIR} ${PREFIX}/${DISTNAME}/www/notes
	${INSTALL_DATA} ${WRKSRC}/README \
				${PREFIX}/${DISTNAME}/README
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bb \
				${PREFIX}/${DISTNAME}/bin/bb
	${INSTALL_SCRIPT} ${WRKSRC}/bin/bb-local.sh \
				${PREFIX}/${DISTNAME}/bin/bb-local.sh
	${INSTALL_SCRIPT} ${WRKSRC}/bin/bb-network.sh \
				${PREFIX}/${DISTNAME}/bin/bb-network.sh
	${INSTALL_SCRIPT} ${WRKSRC}/bin/bb-page.sh \
				${PREFIX}/${DISTNAME}/bin/bb-page.sh
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bbd \
				${PREFIX}/${DISTNAME}/bin/bbd
	${INSTALL_PROGRAM} ${WRKSRC}/bin/touchtime \
				${PREFIX}/${DISTNAME}/bin/touchtime
	${INSTALL_DATA} ${WRKSRC}/doc/README \
				${PREFIX}/${DISTNAME}/doc/README
	${INSTALL_DATA} ${WRKSRC}/doc/STRUCTURE \
				${PREFIX}/${DISTNAME}/doc/STRUCTURE
	${INSTALL_SCRIPT} ${WRKSRC}/doc/bbclient \
				${PREFIX}/${DISTNAME}/doc/bbclient
	${INSTALL_SCRIPT} ${WRKSRC}/doc/bbconfig \
				${PREFIX}/${DISTNAME}/doc/bbconfig
	${INSTALL_DATA} ${WRKSRC}/etc/bb-hosts \
				${PREFIX}/${DISTNAME}/etc/bb-hosts
	${INSTALL_SCRIPT} ${WRKSRC}/etc/bbdef.sh \
				${PREFIX}/${DISTNAME}/etc/bbdef.sh
	${INSTALL_SCRIPT} ${WRKSRC}/etc/bbinc.sh \
				${PREFIX}/${DISTNAME}/etc/bbinc.sh
	${INSTALL_DATA} ${WRKSRC}/etc/bbsys.freebsd \
				${PREFIX}/${DISTNAME}/etc/bbsys.freebsd
	${INSTALL_DATA} ${WRKSRC}/etc/bbsys.hpux \
				${PREFIX}/${DISTNAME}/etc/bbsys.hpux
	${INSTALL_DATA} ${WRKSRC}/etc/bbsys.linux \
				${PREFIX}/${DISTNAME}/etc/bbsys.linux
	${INSTALL_DATA} ${WRKSRC}/etc/bbsys.local \
				${PREFIX}/${DISTNAME}/etc/bbsys.local
	${INSTALL_SCRIPT} ${WRKSRC}/etc/bbsys.sh \
				${PREFIX}/${DISTNAME}/etc/bbsys.sh
	${INSTALL_DATA} ${WRKSRC}/etc/bbsys.solaris \
				${PREFIX}/${DISTNAME}/etc/bbsys.solaris
	${INSTALL_DATA} ${WRKSRC}/etc/bbsys.sunos \
				${PREFIX}/${DISTNAME}/etc/bbsys.sunos
	${INSTALL_SCRIPT} ${WRKSRC}/runbb.sh \
				${PREFIX}/${DISTNAME}/runbb.sh
	${INSTALL_SCRIPT} ${WRKSRC}/web/mkbb.bkg \
				${PREFIX}/${DISTNAME}/web/mkbb.bkg
	${INSTALL_SCRIPT} ${WRKSRC}/web/mkbb.cols \
				${PREFIX}/${DISTNAME}/web/mkbb.cols
	${INSTALL_SCRIPT} ${WRKSRC}/web/mkbb.sh \
				${PREFIX}/${DISTNAME}/web/mkbb.sh
	${INSTALL_SCRIPT} ${WRKSRC}/web/mkbb2.sh \
				${PREFIX}/${DISTNAME}/web/mkbb2.sh
	${INSTALL_DATA} ${WRKSRC}/www/bb-help.html \
				${PREFIX}/${DISTNAME}/www/bb-help.html
	${INSTALL_DATA} ${WRKSRC}/www/bb-info.html \
				${PREFIX}/${DISTNAME}/www/bb-info.html
	${INSTALL_DATA} ${WRKSRC}/www/bb-page.html \
				${PREFIX}/${DISTNAME}/www/bb-page.html
	${INSTALL_DATA} ${WRKSRC}/www/gifs/bb-diag.gif \
				${PREFIX}/${DISTNAME}/www/gifs/bb-diag.gif
	${INSTALL_DATA} ${WRKSRC}/www/gifs/bb.gif \
				${PREFIX}/${DISTNAME}/www/gifs/bb.gif
	${INSTALL_DATA} ${WRKSRC}/www/gifs/bkg-green.gif \
				${PREFIX}/${DISTNAME}/www/gifs/bkg-green.gif
	${INSTALL_DATA} ${WRKSRC}/www/gifs/bkg-purple.gif \
				${PREFIX}/${DISTNAME}/www/gifs/bkg-purple.gif
	${INSTALL_DATA} ${WRKSRC}/www/gifs/bkg-red.gif \
				${PREFIX}/${DISTNAME}/www/gifs/bkg-red.gif
	${INSTALL_DATA} ${WRKSRC}/www/gifs/bkg-yellow.gif \
				${PREFIX}/${DISTNAME}/www/gifs/bkg-yellow.gif
	${INSTALL_DATA} ${WRKSRC}/www/gifs/blue.gif \
				${PREFIX}/${DISTNAME}/www/gifs/blue.gif
	${INSTALL_DATA} ${WRKSRC}/www/gifs/buthelp.gif \
				${PREFIX}/${DISTNAME}/www/gifs/buthelp.gif
	${INSTALL_DATA} ${WRKSRC}/www/gifs/butinfo.gif \
				${PREFIX}/${DISTNAME}/www/gifs/butinfo.gif
	${INSTALL_DATA} ${WRKSRC}/www/gifs/butpage.gif \
				${PREFIX}/${DISTNAME}/www/gifs/butpage.gif
	${INSTALL_DATA} ${WRKSRC}/www/gifs/butview.gif \
				${PREFIX}/${DISTNAME}/www/gifs/butview.gif
	${INSTALL_DATA} ${WRKSRC}/www/gifs/green.gif \
				${PREFIX}/${DISTNAME}/www/gifs/green.gif
	${INSTALL_DATA} ${WRKSRC}/www/gifs/purple.gif \
				${PREFIX}/${DISTNAME}/www/gifs/purple.gif
	${INSTALL_DATA} ${WRKSRC}/www/gifs/red.gif \
				${PREFIX}/${DISTNAME}/www/gifs/red.gif
	${INSTALL_DATA} ${WRKSRC}/www/gifs/yellow.gif \
				${PREFIX}/${DISTNAME}/www/gifs/yellow.gif
	${INSTALL_DATA} ${WRKSRC}/www/logs/later \
				${PREFIX}/${DISTNAME}/www/logs/later
	@${RM} -f ${PREFIX}/www/data/bb
	@ln -s ../../${DISTNAME}/www ${PREFIX}/www/data/bb
	@echo ""
	@echo "================================================================"
	@echo "==== Configuration Notes:                                    ==="
	@echo "================================================================"
	@echo ""
	@echo "a) your hosts 'full qualified domain name' and IP-address"
	@echo "b) 'watched' hosts 'full qualified domain name' and IP-address"
	@echo "go here -> ${PREFIX}/${DISTNAME}/etc/bb-hosts"
	@echo ""
	@echo "c) configure -> ${PREFIX}/${DISTNAME}/etc/bbdef.sh"
	@echo "d) configure -> ${PREFIX}/${DISTNAME}/etc/bbinc.sh"
	@echo ""
	@echo "e) You need to have a running WWW server (apache)"
	@echo ""
	@echo "After that, you can startup the big brother service by typing"
	@echo "        ${PREFIX}/${DISTNAME}/runbb.sh &"
	@echo ""
	@echo "and watching your systems status by viewing this URL with"
	@echo "Netscape or another WWW browser"
	@echo "        http://localhost/bb/bb.html"
	@echo ""
	@echo "Look here for a life sample:"
	@echo "        http://www.menet.umn.edu/~clolson/bb/bb.html"
	@echo ""
	@echo "Have fun doing it remotely - Andreas ///"

.include <bsd.port.mk>
