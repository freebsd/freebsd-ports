# New ports collection makefile for:	libmicrohttpd
# Date created:		12 February 2008
# Whom:			David Barksdale <amatus@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	libmicrohttpd
PORTVERSION=	0.4.2
CATEGORIES=	www
MASTER_SITES=	http://gnunet.org/libmicrohttpd/download/

MAINTAINER=	amatus@gnu.org
COMMENT=	C library for embedding HTTP server functionality

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/libmicrohttpd.so.6 \
		lib/libmicrohttpd.la \
		lib/libmicrohttpd.so \
		lib/libmicrohttpd.a \
		libdata/pkgconfig/libmicrohttpd.pc \
		include/microhttpd.h \
		info/microhttpd.info

MAN3=		libmicrohttpd.3

.include <bsd.port.mk>
