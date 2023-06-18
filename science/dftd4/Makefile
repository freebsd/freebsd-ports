PORTNAME=	dftd4
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5.0
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Atomic-charge dependent london dispersion correction computation
WWW=		https://www.chemie.uni-bonn.de/pctc/mulliken-center/software/dftd4

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	Cannot open module file 'ieee_arithmetic.mod' for reading at (1): No such file or directory

BUILD_DEPENDS=	mstore>0:science/mstore
LIB_DEPENDS=	libmctc-lib.so:science/mctc-lib \
		libmulticharge.so:science/multicharge \
		libopenblas.so:math/openblas

USES=		cmake:testing fortran
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.options.mk>
.if (${ARCH} == powerpc64le || ${ARCH} == powerpc64 || ${ARCH} == powerpc) && ${OSVERSION} < 1301510 # support added in e09d209d1a74a3caca95dea303db9bc605fce1a7
BROKEN_powerpc64=	Cannot open module file 'ieee_arithmetic.mod' for reading at (1): No such file or directory
BROKEN_powerpc64le=	Cannot open module file 'ieee_arithmetic.mod' for reading at (1): No such file or directory
.endif

post-patch: # see https://github.com/toml-f/toml-f/issues/51
	@${REINPLACE_CMD} -e 's|$${CMAKE_Fortran_COMPILER_ID}-$${CMAKE_Fortran_COMPILER_VERSION}||' ${WRKSRC}/config/CMakeLists.txt

.include <bsd.port.mk>
