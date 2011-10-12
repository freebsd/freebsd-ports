# New ports collection makefile for:	libmicrohttpd
# Date created:		12 February 2008
# Whom:			David Barksdale <amatus@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	libmicrohttpd
PORTVERSION=	0.9.15
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gaod@hychen.org
COMMENT=	C library for embedding HTTP server functionality

LICENSE=	LGPL21

OPTIONS=	GNUTLS "Build with gnutls to support ssl" off
.include <bsd.port.options.mk>

.if ${OSVERSION} < 702000
IGNORE=	strdup is not available in this OS release
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt \
		gnutls.47:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--with-gnutls=${LOCALBASE} --enable-https
.endif

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS+=	pkgconfigdir=${PREFIX}/libdata/pkgconfig

MAN3=		libmicrohttpd.3
INFO=		microhttpd microhttpd-tutorial

PLIST_FILES=	lib/libmicrohttpd.so.23 \
		lib/libmicrohttpd.la \
		lib/libmicrohttpd.so \
		lib/libmicrohttpd.a \
		libdata/pkgconfig/libmicrohttpd.pc \
		include/microhttpd.h

.include <bsd.port.mk>
