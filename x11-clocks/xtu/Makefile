# New ports collection makefile for:	xtu
# Date created:		17 Apr 1999
# Whom:			runge@rostock.zgdv.de
#
# $FreeBSD$
#

PORTNAME=	xtu
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	x11-clocks
MASTER_SITES=	http://core.de/~coto/projects/xtu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transparent analog clock for X11

USE_IMAKE=	yes
WANT_GNOME=	yes
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
NO_INSTALL_MANPAGES=	yes
PLIST_FILES=	bin/xtu

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mimlib}!=""
USE_GNOME=	imlib
CPPFLAGS=	-DUSE_IMLIB `${IMLIB_CONFIG} --cflags`
LDFLAGS=	`${IMLIB_CONFIG} --libs`
.else
USE_XPM=	yes
CPPFLAGS=	-DUSE_XPM
LDFLAGS=	-lXpm -lX11 -lXext
.endif

.include <bsd.port.post.mk>
