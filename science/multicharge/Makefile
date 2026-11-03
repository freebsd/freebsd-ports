PORTNAME=	multicharge
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Electronegativity equilibration model for atomic partial charges
WWW=		https://github.com/grimme-lab/multicharge/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mstore>0:science/mstore
LIB_DEPENDS=	libmctc-lib.so:science/mctc-lib \
		libopenblas.so:math/openblas

USES=		cmake:testing fortran
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	grimme-lab

CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	MULTICHARGE_WITH_TESTS

post-patch: # see https://github.com/toml-f/toml-f/issues/51
	@${REINPLACE_CMD} -e 's|$${CMAKE_Fortran_COMPILER_ID}-$${CMAKE_Fortran_COMPILER_VERSION}||' \
		${WRKSRC}/config/CMakeLists.txt

# tests as of 0.5.0: 100% tests passed, 0 tests failed out of 3
# tests as of 0.6.0: 75% tests passed, 1 tests failed out of 4 (the failure is due to precision errors)

.include <bsd.port.mk>
