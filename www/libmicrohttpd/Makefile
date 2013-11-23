# Created by: David Barksdale <amatus@gnu.org>
# $FreeBSD$

PORTNAME=	libmicrohttpd
PORTVERSION=	0.9.31
CATEGORIES=	www
MASTER_SITES=	GNU

MAINTAINER=	gaod@hychen.org
COMMENT=	C library for embedding HTTP server functionality

LICENSE=	LGPL21

OPTIONS_DEFINE=	GNUTLS

GNU_CONFIGURE=	yes
MAKE_ARGS+=	pkgconfigdir=${PREFIX}/libdata/pkgconfig
USE_LDCONFIG=	yes

GNUTLS_LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
			libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_CONFIGURE_ARGS=	--with-gnutls=${LOCALBASE} --enable-https

INFO=		libmicrohttpd libmicrohttpd-tutorial

PLIST_FILES=	include/microhttpd.h \
		lib/libmicrohttpd.a \
		lib/libmicrohttpd.la \
		lib/libmicrohttpd.so \
		lib/libmicrohttpd.so.30 \
		libdata/pkgconfig/libmicrohttpd.pc \
		man/man3/libmicrohttpd.3.gz

post-build:
	@${STRIP_CMD} ${WRKSRC}/src/microhttpd/.libs/libmicrohttpd.so.30

.include <bsd.port.mk>
