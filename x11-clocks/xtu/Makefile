# New ports collection makefile for:	xtu
# Date created:		17 Apr 1999
# Whom:			runge@rostock.zgdv.de
#
# $FreeBSD$
#

PORTNAME=	xtu
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	x11-clocks
MASTER_SITES=	http://core.de/~coto/projects/xtu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transparent analog clock for X11

USE_IMAKE=	yes
USE_XORG=	x11 xpm xext
CPPFLAGS=	-DUSE_XPM
LDFLAGS=	-lXpm -lX11 -lXext
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAN1=		xtu.1
PLIST_FILES=	bin/xtu

.include <bsd.port.mk>
