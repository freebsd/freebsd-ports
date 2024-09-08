PORTNAME=	nghttp3
DISTVERSION=	1.5.0
CATEGORIES=	www net
MASTER_SITES=	https://github.com/ngtcp2/${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	lib

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/3 C Library
WWW=		https://nghttp2.org/nghttp3/ \
		https://github.com/ngtcp2/nghttp3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake pathfix tar:xz
USE_LDCONFIG=	yes

TEST_TARGET=	check

CMAKE_ON=	ENABLE_LIB_ONLY

.include <bsd.port.mk>
