# New ports collection makefile for:	tridiavnc
# Date created:		14 June 2001
# Whom:			dwcjr
#
# $FreeBSD$
#

PORTNAME=	tridiavnc
PORTVERSION=	1.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.developvnc.org/logged-in/downloadnow/
MASTER_SITE_SUBDIR=dwcjr
DISTNAME=	DevVNC_unix
EXTRACT_SUFX=	.tgz

MAINTAINER=	dwcjr@freebsd.org

USE_PERL5=	yes
WRKSRC=		${WRKDIR}/unix/vnc_unixsrc
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

# We have to frob a few things, and we want our own permissions, so it's easier
# to do the install ourselves.
post-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${INSTALL_PROGRAM} ${WRKSRC}/vncconnect/vncconnect ${PREFIX}/bin/vncconnect
	${SED}  -e s%/usr/local/vnc/classes%${PREFIX}/share/vnc/classes% \
		-e s%^\#!/usr/bin/perl%\#!${PERL}% \
		< ${WRKSRC}/vncserver \
		> ${WRKSRC}/vncserver.local
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver.local ${PREFIX}/bin/vncserver
# Go install Java classes
	${MKDIR} ${PREFIX}/share/vnc
	${CP} -R ${WRKSRC}/classes ${PREFIX}/share/vnc
.include <bsd.port.mk>
