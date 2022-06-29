# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	nghttp2
PORTVERSION=	1.48.0
CATEGORIES=	www net
MASTER_SITES=	https://github.com/nghttp2/nghttp2/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/2.0 C Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libnghttp2>=${PORTVERSION}:www/libnghttp2
LIB_DEPENDS=	libnghttp2.so:www/libnghttp2

USES=		compiler:c++14-lang cpe gmake libtool localbase pathfix pkgconfig ssl tar:xz

CONFIGURE_ARGS=	--disable-python-bindings --with-jemalloc
CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++14
USE_RC_SUBR=	nghttpx

OPTIONS_DEFINE=	APP ASIO DOCS EXAMPLES HPACK
OPTIONS_DEFAULT=APP HPACK
OPTIONS_SUB=	yes
APP_DESC=	Build h2load, nghttp, nghttpd and nghttpx

APP_BUILD_DEPENDS=	c-ares>=1.7.5:dns/c-ares \
			libev>=4.11:devel/libev
APP_CONFIGURE_ENABLE=	app
APP_CONFIGURE_OFF=	--without-libxml2
APP_LIB_DEPENDS=	libcares.so:dns/c-ares \
			libev.so:devel/libev
APP_USE=		GNOME=libxml2
APP_USES=		gnome
ASIO_BUILD_DEPENDS=	boost-libs>=1.54.0:devel/boost-libs
ASIO_CONFIGURE_OFF=	--with-boost=no
ASIO_CONFIGURE_ON=	--enable-asio-lib --with-boost-asio --with-boost-system --with-boost-thread
ASIO_LIB_DEPENDS=	libboost_thread.so:devel/boost-libs
ASIO_USE=		LDCONFIG=yes
EXAMPLES_CONFIGURE_ENABLE=	examples
EXAMPLES_BUILD_DEPENDS=	libevent>=2.0.8:devel/libevent
EXAMPLES_LIB_DEPENDS=	libevent_openssl.so:devel/libevent
HPACK_BUILD_DEPENDS=	jansson>=2.5:devel/jansson
HPACK_CONFIGURE_ENABLE=	hpack-tools
HPACK_LIB_DEPENDS=	libjansson.so:devel/jansson

# lib/libnghttp2.* are not available until configure phase
post-configure:
	@${MKDIR} ${WRKSRC}/lib/.libs/
	@${CP} ${LOCALBASE}/lib/libnghttp2.so* ${WRKSRC}/lib/.libs/
	@cd ${WRKSRC}/lib/.libs/ && ${AR} x ${LOCALBASE}/lib/libnghttp2.a

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/nghttpx/
	${INSTALL_DATA} ${FILESDIR}/nghttpx.conf.sample ${STAGEDIR}${PREFIX}/etc/nghttpx/nghttpx.conf.sample

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/*.c* ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/examples/ && ${INSTALL_PROGRAM} client deflate libevent-client libevent-server ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
