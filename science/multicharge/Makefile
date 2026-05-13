PORTNAME=	multicharge
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	science # chemistry

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	dab74514e5af03aba9eb8a84a9f1028fe31756f4.patch:-p1 # https://github.com/grimme-lab/multicharge/pull/61

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

CMAKE_ON=	BUILD_SHARED_LIBS

post-patch: # see https://github.com/toml-f/toml-f/issues/51
	@${REINPLACE_CMD} -e 's|$${CMAKE_Fortran_COMPILER_ID}-$${CMAKE_Fortran_COMPILER_VERSION}||' \
		${WRKSRC}/config/CMakeLists.txt

# tests as of 0.5.0: 100% tests passed, 0 tests failed out of 3

.include <bsd.port.mk>
