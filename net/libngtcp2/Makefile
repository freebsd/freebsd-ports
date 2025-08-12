PORTNAME=	ngtcp2
PORTVERSION=	1.14.0
CATEGORIES=	net
MASTER_SITES=	https://github.com/ngtcp2/ngtcp2/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	lib

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of QUIC protocol
WWW=		https://nghttp2.org/ngtcp2/ \
		https://github.com/ngtcp2/ngtcp2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix pkgconfig tar:xz

CONFIGURE_ARGS=	--enable-lib-only \
		--with-jemalloc \
		--without-boringssl \
		--without-gnutls \
		--without-libbrotlidec \
		--without-libbrotlienc \
		--without-libev \
		--without-libnghttp3 \
		--without-openssl \
		--without-wolfssl
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

SLAVEDIRS=	net/libngtcp2-gnutls net/libngtcp2-wolfssl

post-install:
	cd ${WRKSRC}/crypto/includes/ngtcp2/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/ngtcp2

.include <bsd.port.mk>
