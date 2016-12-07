# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	cgnslib
DISTVERSION=	3.2.1
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	science
MASTER_SITES=	SF/cgns/${PORTNAME}_${PORTVERSION:R}/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	CFD General Notation System library code

LICENSE=	AS-IS
LICENSE_NAME=	AS-IS
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	HDF5 SZIP TESTS TOOLS
HDF5_DESC=	Enable HDF5 interface
TESTS_DESC=	Enable test programs
TOOLS_DESC=	Build the CGNSTools package
SZIP_DESC=	SZIP support in HDF5

OPTIONS_DEFAULT=HDF5 TESTS TOOLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHDF5}
LIB_DEPENDS+=	libhdf5.so:science/hdf5
CMAKE_ARGS+=	-DCGNS_ENABLE_HDF5:BOOL=TRUE -DHDF5_NEED_ZLIB:BOOL=TRUE	\
		-DHDF5_INCLUDE_PATH:PATH="${LOCALBASE}/include"
PLIST_SUB=	HDF5=""
. if ${PORT_OPTIONS:MSZIP}
CMAKE_ARGS+=	-DHDF5_NEED_SZIP:BOOL=OFF
. endif
.else
CMAKE_ARGS+=	-DCGNS_ENABLE_HDF5:BOOL=OFF
PLIST_SUB=	HDF5="@comment "
.endif

.if ${PORT_OPTIONS:MTESTS}
USES+=		fortran
CMAKE_ARGS+=	-DCGNS_ENABLE_TESTS:BOOL=TRUE -DCGNS_ENABLE_FORTRAN:BOOL=TRUE
TESTSBIN=	cgwrite cgread test_partial
.endif

.if ${PORT_OPTIONS:MTOOLS}
USES+=		tk
USE_GL=		gl glu
USE_XORG=	xmu
CMAKE_ARGS+=	-DCGNS_BUILD_CGNSTOOLS:BOOL=TRUE			\
		-DTCL_INCLUDE_PATH:STRING="${TCL_INCLUDEDIR}"	\
		-DTK_INCLUDE_PATH:STRING="${TK_INCLUDEDIR}"
PLIST_SUB=	TOOLS=""
.else
PLIST_SUB=	TOOLS="@comment "
.endif

LIBVER=		${PORTVERSION:R}

.if ${PORT_OPTIONS:MTESTS}
regression-test:
. for pg in ${TESTSBIN}
	@(cd ${BUILD_WRKSRC}/src/tests; ./${pg})
. endfor
.endif

post-install:
	${LN} -sf libcgns.so.${LIBVER} ${STAGEDIR}${PREFIX}/lib/libcgns.so.${LIBVER:R}

.include <bsd.port.mk>
