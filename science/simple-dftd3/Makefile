PORTNAME=	simple-dftd3
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reimplementation of the DFT-D3 program
WWW=		https://github.com/awvwgk/simple-dftd3

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	cannot open module file 'ieee_arithmetic.mod' for reading at (1): No such file or directory

BUILD_DEPENDS=	mstore>0:science/mstore
LIB_DEPENDS=	libmctc-lib.so:science/mctc-lib \
		libopenblas.so:math/openblas \
		libtoml-f.so:textproc/toml-f

USES=		cmake:testing fortran
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dftd3

CMAKE_ON=	BUILD_SHARED_LIBS

post-patch: # see https://github.com/toml-f/toml-f/issues/51
	@${REINPLACE_CMD} -e 's|$${CMAKE_Fortran_COMPILER_ID}-$${CMAKE_Fortran_COMPILER_VERSION}||' ${WRKSRC}/config/CMakeLists.txt

.include <bsd.port.mk>
