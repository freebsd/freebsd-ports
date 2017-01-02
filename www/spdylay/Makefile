# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spdylay
PORTVERSION=	1.4.0
CATEGORIES=	www net
MASTER_SITES=	https://github.com/tatsuhiro-t/${PORTNAME}/releases/download/v${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SPDY protocol version 2, 3 and 3.1 implementation in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libevent2>=2.0.8:devel/libevent2
LIB_DEPENDS=	libevent_openssl.so:devel/libevent2

BROKEN_powerpc64=	does not build
BROKEN_sparc64=		does not build: fails to link

CONFIGURE_ARGS=	--enable-examples \
		--enable-src
CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl" \
		ZLIB_CFLAGS="-I${INCLUDEDIR}" \
		ZLIB_LIBS="-L${LIBDIR} -lz"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++11
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USES=		compiler:c++11-lang libtool pathfix pkgconfig ssl tar:xz

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|^Requires.private: zlib$$|Libs.private: -L${LIBDIR} -lz|' ${WRKSRC}/lib/libspdylay.pc.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/examples/spdycli ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/shrpx.conf.sample ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
