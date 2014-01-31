# Created by: David Barksdale <amatus@gnu.org>
# $FreeBSD$

PORTNAME=	libmicrohttpd
PORTVERSION=	0.9.33
CATEGORIES=	www
MASTER_SITES=	GNU

MAINTAINER=	gaod@hychen.org
COMMENT=	C library for embedding HTTP server functionality

LICENSE=	LGPL21

OPTIONS_DEFINE=	GNUTLS

GNU_CONFIGURE=	yes
MAKE_ARGS+=	pkgconfigdir=${PREFIX}/libdata/pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
			libgnutls.so:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-libgcrypt-prefix=${LOCALBASE} --with-gnutls=${LOCALBASE} --enable-https=yes
.endif

INFO=		libmicrohttpd libmicrohttpd-tutorial

PLIST_FILES=	include/microhttpd.h \
		lib/libmicrohttpd.a \
		lib/libmicrohttpd.la \
		lib/libmicrohttpd.so \
		lib/libmicrohttpd.so.32 \
		libdata/pkgconfig/libmicrohttpd.pc \
		man/man3/libmicrohttpd.3.gz

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl|-lc|' ${WRKSRC}/src/examples/Makefile.in

post-build:
	@${STRIP_CMD} ${WRKSRC}/src/microhttpd/.libs/libmicrohttpd.so.32

.include <bsd.port.mk>
