# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spdylay
PORTVERSION=	1.1.0
CATEGORIES=	www net
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SPDY protocol version 2 and 3 implementation in C

LICENSE=	MIT

OPTIONS_DEFINE=	SHRPX
OPTIONS_SUB=	yes
SHRPX_DESC=	Build shrpx (HTTP reverse proxy), requires OpenSSL 1.0.1+

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl" \
		ZLIB_CFLAGS="-I${INCLUDEDIR}" \
		ZLIB_LIBS="-L${LIBDIR} -lz"
GNU_CONFIGURE=	yes
USE_CXXSTD=	c++11
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_XZ=		yes
USES=		compiler:c++11-lang pathfix pkgconfig

PORTDOCS=	README.rst

.include <bsd.port.pre.mk>

# Only build shrpx on FreeBSD 10 and above
.if ${PORT_OPTIONS:MSHRPX} && ${OSVERSION} < 1000000 && !defined(WITH_OPENSSL_PORT)
IGNORE=		shrpx requires libevent_openssl.so (devel/libevent2) built with OpenSSL 1.0.1+
.endif

# spdylay requires OpenSSL 1.0.1+
.if ${OSVERSION} < 1000000
WITH_OPENSSL_PORT=	yes
.endif

.if ${PORT_OPTIONS:MSHRPX}
LIB_DEPENDS+=	libevent_openssl.so:${PORTSDIR}/devel/libevent2
CONFIGURE_ARGS+=--enable-examples
CONFIGURE_ENV+=	LIBEVENT_OPENSSL_CFLAGS="-I${LOCALBASE}" \
		LIBEVENT_OPENSSL_LIBS="-L${LOCALBASE}/lib/event2 -levent_openssl"
.endif

post-build:
	@${STRIP_CMD} ${WRKSRC}/lib/.libs/libspdylay.so.6

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/spdycli ${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MSHRPX}
	@${INSTALL_DATA} ${WRKSRC}/shrpx.conf.sample ${STAGEDIR}${PREFIX}/etc/
.endif

.include <bsd.port.post.mk>
