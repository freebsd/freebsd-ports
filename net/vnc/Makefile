# New ports collection makefile for:	vnc
# Date created:		24 February 1998
# Whom:			msmith
#
# $FreeBSD$
#

PORTNAME=	vnc
PORTVERSION=	3.3.5
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.realvnc.com/dist/
DISTNAME=	${PORTNAME}-${PORTVERSION}-unixsrc

MAINTAINER=	mchopra@engmail.uwaterloo.ca

GNU_CONFIGURE=	yes
USE_PERL5_RUN=	yes
USE_REINPLACE=	yes
USE_XLIB=	yes

MAN1=		Xvnc.1 \
		vncviewer.1 \
		vncpasswd.1 \
		vncconnect.1 \
		vncserver.1

post-build:
	@cd ${WRKSRC}/Xvnc && make World

do-install:
	${REINPLACE_CMD} -e 's|/usr/local/vnc/classes|${PREFIX}/share/vnc/classes|g' \
		-e 's|^\#!/usr/bin/perl|\#!${PERL}|g' ${WRKSRC}/vncserver
	${INSTALL_PROGRAM} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc ${PREFIX}/bin/Xvnc
	${INSTALL_PROGRAM} ${WRKSRC}/vncviewer/vncviewer ${PREFIX}/bin/vncviewer
	${INSTALL_PROGRAM} ${WRKSRC}/vncpasswd/vncpasswd ${PREFIX}/bin/vncpasswd
	${INSTALL_PROGRAM} ${WRKSRC}/vncconnect/vncconnect ${PREFIX}/bin/vncconnect
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver ${PREFIX}/bin/vncserver
	${INSTALL_MAN} ${WRKSRC}/Xvnc/programs/Xserver/Xvnc.man ${PREFIX}/man/man1/Xvnc.1
	${INSTALL_MAN} ${WRKSRC}/vncviewer/vncviewer.man ${PREFIX}/man/man1/vncviewer.1
	${INSTALL_MAN} ${WRKSRC}/vncpasswd/vncpasswd.man ${PREFIX}/man/man1/vncpasswd.1
	${INSTALL_MAN} ${WRKSRC}/vncconnect/vncconnect.man ${PREFIX}/man/man1/vncconnect.1
	${INSTALL_MAN} ${WRKSRC}/vncserver.man ${PREFIX}/man/man1/vncserver.1
# Go install Java classes
	${MKDIR} ${PREFIX}/share/vnc
	${CP} -R ${WRKSRC}/classes ${PREFIX}/share/vnc

.include <bsd.port.mk>
