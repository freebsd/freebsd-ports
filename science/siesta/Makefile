PORTNAME=	siesta
DISTVERSION=	5.4.2
PORTREVISION=	1
CATEGORIES=	science # chemistry
MASTER_SITES=	https://gitlab.com/siesta-project/${PORTNAME}/-/releases/${DISTVERSION}/downloads/
DISTFILES=	${PORTNAME}-${DISTVERSION}.tar.gz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program to perform efficient electronic structure calculations
WWW=		https://siesta-project.org/siesta/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	lack of IEEE754 support in gcc causes "Cannot find an intrinsic module named 'ieee_arithmetic'", see bug#255890

LIB_DEPENDS=	libopenblas.so:math/openblas \
		libreadline.so:devel/readline

USES=		cmake:noninja,testing fortran:gfortran gmake localbase:ldflags pkgconfig

PLIST_FILES=	bin/${PORTNAME}

USE_GITHUB=	nodefault
GH_TUPLE=	ElectronicStructureLibrary:flook:v0.8.4:flook/External/Lua-Engine/flook \
		dftd3:simple-dftd3:f147b265d8b53dcf1666d7b0aba579ec02233fe8:s_dftd3/External/DFTD3/s-dftd3 \
		grimme-lab:mctc-lib:v0.3.1:mctc_lib/External/DFTD3/mctc-lib \
		grimme-lab:mstore:v0.2.0:mstore/External/DFTD3/mstore \
		toml-f:toml-f:v0.2.4:toml_f/External/DFTD3/toml-f \
		fortran-lang:test-drive:v0.4.0:test_drive/External/DFTD3/test-drive

USE_GITLAB=	nodefault
GL_TUPLE=	siesta-project/libraries:libfdf:206a3d6c4628e584743bd5cd483d0e2e66e95b7c:libfdf/External/libfdf \
		siesta-project/libraries:xmlf90:963fe5d11487233d43ac59dd0c1340a7b2cc3dc5:xmlf90/External/xmlf90 \
		siesta-project/libraries:libpsml:b7049e4de25333fe8bd2dbf9a3495ef0f77ba168:libpsml/External/libpsml \
		siesta-project/libraries:libgridxc:022d2a6371eed0db272ac6922289921f62f30c21:libgridxc/External/libgridxc

BINARY_ALIAS=	gfortran=gfortran${GCC_DEFAULT} gcc=gcc${GCC_DEFAULT}

CMAKE_ARGS=	-DSIESTA_WITH_MPI=OFF \
		-DSIESTA_WITH_ELSI=OFF \
		-DSIESTA_WITH_WANNIER90=OFF \
		-DSIESTA_WITH_NETCDF=OFF \
		-DSIESTA_WITH_LIBXC=OFF \
		-DSIESTA_WITH_FFTW=OFF \
		-Dlibfdf_FIND_METHOD=source \
		-Dxmlf90_FIND_METHOD=source \
		-Dlibpsml_FIND_METHOD=source \
		-Dlibgridxc_FIND_METHOD=source \
		-Ds-dftd3_FIND_METHOD=source \
		-Dmctc-lib_FIND_METHOD=source \
		-Dmstore_FIND_METHOD=source \
		-Dtoml-f_FIND_METHOD=source \
		-Dtest-drive_FIND_METHOD=source
CMAKE_OFF=	SIESTA_TESTS \
		SIESTA_WITH_HOST_OPTIMIZATION
CMAKE_TESTING_ON=	SIESTA_TESTS

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Type mismatch between actual argument at (1) and actual argument at (2) (COMPLEX(8)/REAL(8)).
FFLAGS+=	-fallow-argument-mismatch
CMAKE_ARGS+=	-DCMAKE_Fortran_FLAGS="${FFLAGS} -O2 -fPIC -ftree-vectorize"
.endif

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/Src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
