# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spdylay
PORTVERSION=	1.3.2
CATEGORIES=	www net
MASTER_SITES=	https://github.com/tatsuhiro-t/${PORTNAME}/releases/download/v${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SPDY protocol version 2, 3 and 3.1 implementation in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libevent2>=2.0.8:devel/libevent2
LIB_DEPENDS=	libevent_openssl.so:devel/libevent2
RUN_DEPENDS=	libevent2>=2.0.8:devel/libevent2

BROKEN_powerpc64=	does not build

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
USE_OPENSSL=	yes
USES=		compiler:c++11-lang libtool pathfix pkgconfig tar:xz

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000 && ${SSL_DEFAULT} == base
IGNORE=		spdylay requires OpenSSL 1.0.1+
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^Requires.private: zlib$$|Libs.private: -L${LIBDIR} -lz|' ${WRKSRC}/lib/libspdylay.pc.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/examples/spdycli ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/shrpx.conf.sample ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.post.mk>
