# New ports collection makefile for:	libmicrohttpd
# Date created:		12 February 2008
# Whom:			David Barksdale <amatus@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	libmicrohttpd
PORTVERSION=	0.9.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libmicrohttpd

MAINTAINER=	gaod@hychen.org
COMMENT=	C library for embedding HTTP server functionality

LICENSE=	LGPL21
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS+=	pkgconfigdir=${PREFIX}/libdata/pkgconfig

MAN3=		libmicrohttpd.3
INFO=		microhttpd microhttpd-tutorial

PLIST_FILES=	lib/libmicrohttpd.so.12 \
		lib/libmicrohttpd.la \
		lib/libmicrohttpd.so \
		lib/libmicrohttpd.a \
		libdata/pkgconfig/libmicrohttpd.pc \
		include/microhttpd.h

.include <bsd.port.mk>
