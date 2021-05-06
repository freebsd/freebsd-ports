PORTNAME=	seal
DISTVERSION=	3.6.4
CATEGORIES=	security

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Microsoft Simple Encrypted Arithmetic Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	Microsoft
GH_PROJECT=	SEAL
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	SEAL_USE_MSGSL SEAL_USE_ZLIB SEAL_USE_ZSTD # project clones repositories instead of using exrernal packages, see https://github.com/microsoft/SEAL/issues/329

PLIST_SUB+=	FILE_VER=${DISTVERSION:R}

.include <bsd.port.mk>
