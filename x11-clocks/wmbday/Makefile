# Created by: Ulrich Spoerlein <uspoerlein@gmail.com>
# $FreeBSD$

PORTNAME=	wmbday
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	x11-clocks
MASTER_SITES=	http://buzzinhornetz.ath.cx/wmbday/files/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	uqs

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	Window Maker dock app that will remind you of birthdays

BUILD_DEPENDS=	xmessage:${PORTSDIR}/x11/xmessage

HAS_CONFIGURE=	yes
MAKEFILE=	BSDmakefile
MAKE_ENV+=	${CONFIGURE_ENV} X11BASE=${LOCALBASE}

.include <bsd.port.mk>
