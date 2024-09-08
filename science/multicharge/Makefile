PORTNAME=	multicharge
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Electronegativity equilibration model for atomic partial charges
WWW=		https://github.com/grimme-lab/mstore

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
	@${REINPLACE_CMD} -e 's|$${CMAKE_Fortran_COMPILER_ID}-$${CMAKE_Fortran_COMPILER_VERSION}||' ${WRKSRC}/config/CMakeLists.txt

.include <bsd.port.mk>
