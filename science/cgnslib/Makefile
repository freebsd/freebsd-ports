# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	cgnslib
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	science

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	CFD General Notation System library code

LICENSE=	AS-IS
LICENSE_NAME=	AS-IS
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	CGNS
GH_PROJECT=	CGNS
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		HDF5 TESTS TOOLS
OPTIONS_DEFAULT=	HDF5 TESTS TOOLS
OPTIONS_SUB=		yes

HDF5_DESC=		Enable HDF5 interface
TESTS_DESC=		Enable test programs
TOOLS_DESC=		Build the CGNSTools package
SZIP_DESC=		SZIP support in HDF5

HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5 libsz.so:science/szip
HDF5_CMAKE_BOOL=	CGNS_ENABLE_HDF5
HDF5_CMAKE_ON=		-DHDF5_INCLUDE_PATH:PATH="${LOCALBASE}/include"

TESTS_USES=		fortran
TESTS_CMAKE_BOOL=	ENABLE_TESTS CGNS_ENABLE_FORTRAN

TOOLS_USES=		gl localbase tk
TOOLS_USE=		GL=gl,glu XORG=x11,xmu
TOOLS_CMAKE_BOOL=	CGNS_BUILD_CGNSTOOLS
TOOLS_CMAKE_ON=		-DTCL_INCLUDE_PATH:STRING="${TCL_INCLUDEDIR}" \
			-DTK_INCLUDE_PATH:STRING="${TK_INCLUDEDIR}"

do-test-TESTS-on:
.for pg in cgwrite cgread test_partial
	@(cd ${BUILD_WRKSRC}/src/tests; ./${pg})
.endfor

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libcgns.so.${DISTVERSION:R} \
		${STAGEDIR}${PREFIX}/lib/libcgns.so.${DISTVERSION:R:R}

.include <bsd.port.mk>
