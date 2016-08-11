# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nghttp2
PORTVERSION=	1.11.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/2.0 C Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libev>=4.15:devel/libev \
		libevent2>=2.0.8:devel/libevent2 \
		spdylay>=1.3.0:www/spdylay
LIB_DEPENDS=	libev.so:devel/libev \
		libevent_openssl.so:devel/libevent2 \
		libspdylay.so:www/spdylay

OPTIONS_DEFINE=	ASIO DOCS HPACK
OPTIONS_DEFAULT=HPACK
OPTIONS_SUB=	yes

USE_GITHUB=	yes

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
PATHFIX_MAKEFILEIN=	Makefile.am
USE_CXXSTD=	c++11
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USES=		autoreconf compiler:c++11-lib gmake libtool localbase pathfix pkgconfig

PORTDATA=	fetch-ocsp-response
PORTDOCS=	*

ASIO_BUILD_DEPENDS=	boost-libs>=1.54.0:devel/boost-libs
ASIO_CONFIGURE_OFF=	--with-boost=no
ASIO_CONFIGURE_ON=	--enable-asio-lib --with-boost-asio --with-boost-system --with-boost-thread
ASIO_LIB_DEPENDS=	libboost_thread.so:devel/boost-libs
ASIO_RUN_DEPENDS=	boost-libs>=1.54.0:devel/boost-libs
HPACK_CONFIGURE_ENABLE=	hpack-tools
HPACK_LIB_DEPENDS=	libjansson.so:devel/jansson

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 1000000
CPPFLAGS+=	-D_GLIBCXX_USE_C99
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
CONFIGURE_ARGS+=--with-jemalloc
.endif

.include <bsd.port.post.mk>
