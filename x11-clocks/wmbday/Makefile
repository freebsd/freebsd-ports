# New ports collection makefile for:	wmbday
# Date created:				2004-01-06
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$

PORTNAME=	wmbday
PORTVERSION=	0.3
CATEGORIES=	x11-clocks
MASTER_SITES=	http://buzzinhornetz.ath.cx/wmbday/files/

MAINTAINER=	q@galgenberg.net
COMMENT=	Window Maker dock app that will remind you of birthdays

BUILD_DEPENDS=	${X11BASE}/bin/xmessage:${X_CLIENTS_PORT}

HAS_CONFIGURE=	yes
USE_X_PREFIX=	yes
MAKEFILE=	BSDmakefile

MAN1=		wmbday.1
MANCOMPRESSED=	yes

post-extract:
	@${CP} ${FILESDIR}/BSDmakefile ${WRKSRC}

.include <bsd.port.mk>
