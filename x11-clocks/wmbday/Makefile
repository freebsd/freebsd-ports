# New ports collection makefile for:	wmbday
# Date created:				2004-01-06
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$

PORTNAME=	wmbday
PORTVERSION=	0.2a
CATEGORIES=	x11-clocks
MASTER_SITES=	http://buzzinhornetz.ath.cx/wmbday/files/

MAINTAINER=	q@galgenberg.net
COMMENT=	Window Maker dock app that will remind you of birthdays

BUILD_DEPENDS=	${X11BASE}/bin/xmessage:${X_CLIENTS_PORT}

HAS_CONFIGURE=	yes
USE_XLIB=	yes

MAN1=		wmbday.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmbday ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/wmbday.1 ${PREFIX}/man/man1
.endif

.include <bsd.port.mk>
