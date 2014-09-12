# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nghttp2
PORTVERSION=	0.6.0
CATEGORIES=	www net
MASTER_SITES=	https://github.com/tatsuhiro-t/${PORTNAME}/releases/download/v${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/2.0 C Library

LICENSE=	MIT

LIB_DEPENDS=	libevent_openssl.so:${PORTSDIR}/devel/libevent2 \
		libspdylay.so:${PORTSDIR}/www/spdylay

OPTIONS_DEFINE=	HPACK
OPTIONS_SUB=	yes

CONFIGURE_ARGS=	--disable-python-bindings \
		--enable-app \
		--enable-examples \
		--with-spdylay
CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl" \
		ZLIB_CFLAGS="-I${INCLUDEDIR}" \
		ZLIB_LIBS="-L${LIBDIR} -lz"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++11
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USES=		compiler:c++11-lang libtool pathfix pkgconfig tar:xz

PORTDOCS=	*

HPACK_CONFIGURE_ARGS=	--enable-hpack-tools
HPACK_LIB_DEPENDS=	libjansson.so:${PORTSDIR}/devel/jansson

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000 && !defined(WITH_OPENSSL_PORT)
IGNORE=		nghttp2 requires OpenSSL 1.0.1+
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
CONFIGURE_ARGS+=--with-jemalloc
.endif

post-patch:
	@${REINPLACE_CMD} -e '/JEMALLOC_LIBS/ s|-ljemalloc||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/ENONET/d' ${WRKSRC}/src/shrpx_listen_handler.cc

.include <bsd.port.post.mk>
