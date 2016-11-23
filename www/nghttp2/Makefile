# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nghttp2
PORTVERSION=	1.16.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	www net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/2.0 C Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	APP ASIO DOCS HPACK SPDY
OPTIONS_DEFAULT=APP HPACK SPDY
OPTIONS_SUB=	yes
APP_DESC=	Build h2load, nghttp, nghttpd and nghttpx
SPDY_DESC=	Enable SPDY in h2load and nghttpx
SPDY_IMPLIES=	APP

CONFIGURE_ARGS=	--disable-python-bindings \
		--disable-examples
CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl" \
		ZLIB_CFLAGS="-I${INCLUDEDIR}" \
		ZLIB_LIBS="-L${LIBDIR} -lz"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes
USE_RC_SUBR=	nghttpx
USES=		autoreconf compiler:c++11-lib gmake libtool localbase pathfix pkgconfig ssl

PORTDATA=	fetch-ocsp-response
PORTDOCS=	*

USE_GITHUB=	yes

APP_BUILD_DEPENDS=	libev>=4.15:devel/libev
APP_CONFIGURE_OFF=	--without-libxml2
APP_CONFIGURE_ENABLE=	app
APP_LIB_DEPENDS=	libev.so:devel/libev
APP_USE=		GNOME=libxml2
ASIO_BUILD_DEPENDS=	boost-libs>=1.54.0:devel/boost-libs
ASIO_CONFIGURE_OFF=	--with-boost=no
ASIO_CONFIGURE_ON=	--enable-asio-lib --with-boost-asio --with-boost-system --with-boost-thread
ASIO_LIB_DEPENDS=	libboost_thread.so:devel/boost-libs
ASIO_RUN_DEPENDS=	boost-libs>=1.54.0:devel/boost-libs
HPACK_CONFIGURE_ENABLE=	hpack-tools
HPACK_LIB_DEPENDS=	libjansson.so:devel/jansson
SPDY_BUILD_DEPENDS=	spdylay>=1.3.0:www/spdylay
SPDY_CONFIGURE_WITH=	spdylay
SPDY_LIB_DEPENDS=	libspdylay.so:www/spdylay

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 1000000
CPPFLAGS+=	-D_GLIBCXX_USE_C99
.endif

# Disable thread_local support for hosts without __cxa_thread_atexit()
# See PR/192320 for details
.if (${OSVERSION} < 1003506) || ((${OSVERSION} >= 1100000) && (${OSVERSION} < 1100122)) || (${OSVERSION} == 1100500)
post-configure:
	@${REINPLACE_CMD} -e '/HAVE_THREAD_LOCAL/d' ${WRKSRC}/config.h
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
CONFIGURE_ARGS+=--with-jemalloc
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/nghttpx
	${INSTALL_DATA} ${FILESDIR}/nghttpx.conf.sample ${STAGEDIR}${PREFIX}/etc/nghttpx/nghttpx.conf.sample

.include <bsd.port.post.mk>
