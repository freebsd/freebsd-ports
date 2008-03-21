# New ports collection makefile for:	wmbday
# Date created:				2004-01-06
# Whom:					Ulrich Spoerlein <q@gmail.com>
#
# $FreeBSD$

PORTNAME=	wmbday
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	x11-clocks
MASTER_SITES=	http://buzzinhornetz.ath.cx/wmbday/files/

MAINTAINER=	uspoerlein@gmail.com
COMMENT=	Window Maker dock app that will remind you of birthdays

BUILD_DEPENDS=	${X11BASE}/bin/xmessage:${X_CLIENTS_PORT}

HAS_CONFIGURE=	yes
MAKEFILE=	BSDmakefile
MAKE_ENV+=	${CONFIGURE_ENV}

MAN1=		wmbday.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
