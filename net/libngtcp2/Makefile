PORTNAME=	ngtcp2
DISTVERSION=	1.2.0
CATEGORIES=	net
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	lib

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of QUIC protocol
WWW=		https://nghttp2.org/ngtcp2/ \
		https://github.com/ngtcp2/ngtcp2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++14-lang pathfix tar:xz
USE_LDCONFIG=	yes

# Always disabled due to lack of QUIC support which is in 3.2
CMAKE_OFF=	ENABLE_OPENSSL
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_CUnit \
		CMAKE_DISABLE_FIND_PACKAGE_Libev \
		CMAKE_DISABLE_FIND_PACKAGE_Libnghttp3

.include <bsd.port.mk>
