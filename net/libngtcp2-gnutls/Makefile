PORTNAME=	ngtcp2
PORTVERSION=	1.15.0
CATEGORIES=	net
MASTER_SITES=	https://github.com/ngtcp2/ngtcp2/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	lib
PKGNAMESUFFIX=	-gnutls

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of QUIC protocol (gnutls backend)
WWW=		https://nghttp2.org/ngtcp2/ \
		https://github.com/ngtcp2/ngtcp2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libngtcp2>=${PORTVERSION}<${PORTVERSION}_99:net/libngtcp2
LIB_DEPENDS=	libgnutls.so:security/gnutls
RUN_DEPENDS=	libngtcp2>=${PORTVERSION}<${PORTVERSION}_99:net/libngtcp2

USES=		libtool pathfix pkgconfig tar:xz

CONFIGURE_ARGS=	--enable-lib-only \
		--with-gnutls \
		--with-jemalloc \
		--without-boringssl \
		--without-libbrotlidec \
		--without-libbrotlienc \
		--without-libev \
		--without-libnghttp3 \
		--without-openssl \
		--without-wolfssl
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
INSTALL_WRKSRC=	${WRKSRC}/crypto/gnutls
USE_LDCONFIG=	yes

.include <bsd.port.mk>
