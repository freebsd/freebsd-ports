PORTNAME=	ngtcp2
PORTVERSION=	1.15.0
CATEGORIES=	net
MASTER_SITES=	https://github.com/ngtcp2/ngtcp2/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	lib
PKGNAMESUFFIX=	-wolfssl

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of QUIC protocol (wolfssl backend)
WWW=		https://nghttp2.org/ngtcp2/ \
		https://github.com/ngtcp2/ngtcp2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libngtcp2>=${PORTVERSION}<${PORTVERSION}_99:net/libngtcp2
LIB_DEPENDS=	libwolfssl.so:security/wolfssl
RUN_DEPENDS=	libngtcp2>=${PORTVERSION}<${PORTVERSION}_99:net/libngtcp2

USES=		libtool pathfix pkgconfig tar:xz

CONFIGURE_ARGS=	--enable-lib-only \
		--with-jemalloc \
		--with-wolfssl \
		--without-boringssl \
		--without-gnutls \
		--without-libbrotlidec \
		--without-libbrotlienc \
		--without-libev \
		--without-libnghttp3 \
		--without-openssl
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
INSTALL_WRKSRC=	${WRKSRC}/crypto/wolfssl
USE_LDCONFIG=	yes

.include <bsd.port.mk>
