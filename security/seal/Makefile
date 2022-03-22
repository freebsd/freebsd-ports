PORTNAME=	seal
DISTVERSION=	4.0.0
CATEGORIES=	security

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Microsoft Simple Encrypted Arithmetic Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	Microsoft
GH_PROJECT=	SEAL
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	SEAL_USE_MSGSL SEAL_USE_ZLIB SEAL_USE_ZSTD # project clones repositories instead of using exrernal packages, see https://github.com/microsoft/SEAL/issues/329
CMAKE_TESTING_ON=	SEAL_BUILD_TESTS
CMAKE_TESTING_TARGET=	gtest

PLIST_SUB+=	VERSION=${DISTVERSION} VER=${DISTVERSION:R}

post-test: # run tests
	@cd ${BUILD_WRKSRC} && bin/sealtest

.include <bsd.port.mk>
