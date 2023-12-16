PORTNAME=	tblite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Light-weight tight-binding framework
WWW=		https://github.com/tblite/tblite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	mstore>0:science/mstore # unclear if this is really needed
LIB_DEPENDS=	libdftd4.so:science/dftd4 \
		libmctc-lib.so:science/mctc-lib \
		libmulticharge.so:science/multicharge \
		libopenblas.so:math/openblas \
		libs-dftd3.so:science/simple-dftd3 \
		libtoml-f.so:textproc/toml-f

USES=		cmake:testing fortran
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

post-patch: # see https://github.com/toml-f/toml-f/issues/51
	@${REINPLACE_CMD} -e 's|$${CMAKE_Fortran_COMPILER_ID}-$${CMAKE_Fortran_COMPILER_VERSION}||' ${WRKSRC}/config/CMakeLists.txt

.include <bsd.port.mk>
