PORTNAME=	ngtcp2
PORTVERSION=	1.22.1
CATEGORIES=	net
MASTER_SITES=	https://github.com/ngtcp2/ngtcp2/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	lib
PKGNAMESUFFIX=	-boringssl

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of QUIC protocol (BoringSSL backend)
WWW=		https://nghttp2.org/ngtcp2/ \
		https://github.com/ngtcp2/ngtcp2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	boringssl>=0:security/boringssl \
		libngtcp2>=${PORTVERSION}<${PORTVERSION}_99:net/libngtcp2
RUN_DEPENDS=	libngtcp2>=${PORTVERSION}<${PORTVERSION}_99:net/libngtcp2

USES=		libtool pkgconfig tar:xz

CONFIGURE_ARGS=	--enable-lib-only \
		--with-boringssl \
		--with-jemalloc \
		--without-gnutls \
		--without-libbrotlidec \
		--without-libbrotlienc \
		--without-libev \
		--without-libnghttp3 \
		--without-openssl \
		--without-wolfssl
CONFIGURE_ENV=	BORINGSSL_CFLAGS="-I${LOCALBASE}/include" \
		BORINGSSL_LIBS="-L${LOCALBASE}/lib -lssl"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
INSTALL_WRKSRC=	${WRKSRC}/crypto/boringssl

.include <bsd.port.mk>
