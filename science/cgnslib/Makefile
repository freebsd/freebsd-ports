# New ports collection makefile for:	cgnslib
# Date created:		Sat 24 oct 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	cgnslib
DISTVERSION=	3.1.3-4
CATEGORIES=	science
MASTER_SITES=	SF/cgns/${PORTNAME}_${PORTVERSION:R:R}/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	CFD General Notation System library code

LICENSE=	AS-IS
LICENSE_NAME=	AS-IS
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_CMAKE=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
USE_LDCONFIG=	yes

.if !defined(WITHOUT_HDF5)
LIB_DEPENDS+=	hdf5.7:${PORTSDIR}/science/hdf5-18
CMAKE_ARGS+=	-DENABLE_HDF5:BOOL=TRUE -DHDF5_NEED_ZLIB:BOOL=TRUE	\
		-DHDF5_INCLUDE_PATH:PATH="${LOCALBASE}/include"
PLIST_SUB=	HDF5=""
. if !defined(WITHOUT_SZIP)
CMAKE_ARGS+=	-DHDF5_NEED_SZIP:BOOL=OFF
. endif
.else
CMAKE_ARGS+=	-DENABLE_HDF5:BOOL=OFF
PLIST_SUB=	HDF5="@comment "
.endif

.if !defined(WITHOUT_TESTS)
USE_FORTRAN=	yes
CMAKE_ARGS+=	-DENABLE_TESTS:BOOL=TRUE -DENABLE_FORTRAN:BOOL=TRUE
TESTSBIN=	cgwrite cgread test_partial
.endif

.if !defined(WITHOUT_TOOLS)
USE_TK=		yes
USE_GL=		gl glu
USE_XORG=	xmu
CMAKE_ARGS+=	-DBUILD_CGNSTOOLS:BOOL=TRUE			\
		-DTCL_INCLUDE_PATH:STRING="${TCL_INCLUDEDIR}"	\
		-DTK_INCLUDE_PATH:STRING="${TK_INCLUDEDIR}"
PLIST_SUB=	TOOLS=""
.else
PLIST_SUB=	TOOLS="@comment "
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:R}
LIBVER=		${PORTVERSION:R:R}

OPTIONS=	HDF5	"Enable or disable HDF5 interface"	on	\
		TESTS	"Enable test programs"			on	\
		TOOLS	"Build the CGNSTools package"		on	\
		SZIP	"SZIP support in HDF5"			off

.if !defined(WITHOUT_TESTS)
regression-test:
. for pg in ${TESTSBIN}
	@(cd ${BUILD_WRKSRC}/src/tests; ./${pg})
. endfor
.endif

post-install:
	${LN} -sf ${PREFIX}/lib/libcgns.so.${LIBVER} ${PREFIX}/lib/libcgns.so.${LIBVER:R}

.include <bsd.port.mk>
