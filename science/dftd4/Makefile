PORTNAME=	dftd4
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.0-31
DISTVERSIONSUFFIX=	-g476e6be
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Atomic-charge dependent london dispersion correction computation
WWW=		https://dftd4.readthedocs.io/en/latest/ \
		https://github.com/dftd4/dftd4

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	cannot open module file 'ieee_arithmetic.mod' for reading at (1): No such file or directory

BUILD_DEPENDS=	mstore>0:science/mstore
LIB_DEPENDS=	libmctc-lib.so:science/mctc-lib \
		libmulticharge.so:science/multicharge \
		libopenblas.so:math/openblas

USES=		cmake:testing fortran
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

post-patch: # see https://github.com/toml-f/toml-f/issues/51
	@${REINPLACE_CMD} -e 's|$${CMAKE_Fortran_COMPILER_ID}-$${CMAKE_Fortran_COMPILER_VERSION}||' ${WRKSRC}/config/CMakeLists.txt

.include <bsd.port.mk>
