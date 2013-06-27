# Created by: David Barksdale <amatus@gnu.org>
# $FreeBSD$

PORTNAME=	libmicrohttpd
PORTVERSION=	0.9.27
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gaod@hychen.org
COMMENT=	C library for embedding HTTP server functionality

LICENSE=	LGPL21

OPTIONS_DEFINE=	GNUTLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt \
		gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--with-gnutls=${LOCALBASE} --enable-https
.endif

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS+=	pkgconfigdir=${PREFIX}/libdata/pkgconfig

MAN3=		libmicrohttpd.3
INFO=		libmicrohttpd libmicrohttpd-tutorial

PLIST_FILES=	lib/libmicrohttpd.so.27 \
		lib/libmicrohttpd.la \
		lib/libmicrohttpd.so \
		lib/libmicrohttpd.a \
		libdata/pkgconfig/libmicrohttpd.pc \
		include/microhttpd.h

.include <bsd.port.mk>
