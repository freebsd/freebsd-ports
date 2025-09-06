PORTNAME=	cgnslib
PORTVERSION=	4.5.0
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	science

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	CFD General Notation System library code
WWW=		https://cgns.github.io/

LICENSE=	AS-IS
LICENSE_NAME=	AS-IS
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	CGNS
GH_PROJECT=	CGNS

USES=		cmake
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

#CMAKE_ARGS=	-DOpenGL_GL_PREFERENCE:STRING="GLVND"
CMAKE_ARGS=	-DOpenGL_GL_PREFERENCE:STRING="LEGACY"
FFLAGS=		-fPIC
TEST_TARGET=	test

OPTIONS_DEFINE=		FORTRAN HDF5 TESTS TOOLS
OPTIONS_DEFAULT=	FORTRAN HDF5 TESTS TOOLS
OPTIONS_SUB=		yes

HDF5_DESC=		Enable HDF5 interface
TESTS_DESC=		Enable test programs
TOOLS_DESC=		Build the CGNSTools package

FORTRAN_USES=		fortran
FORTRAN_CMAKE_BOOL=	CGNS_ENABLE_FORTRAN

HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5	\
			libsz.so:science/libaec
HDF5_CMAKE_BOOL=	CGNS_ENABLE_HDF5
HDF5_CMAKE_ON=		-DHDF5_INCLUDE_PATH:PATH="${LOCALBASE}/include"

TESTS_CMAKE_BOOL=	CGNS_ENABLE_TESTS

TOOLS_USES=		gl localbase tk xorg
TOOLS_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig	\
			libfreetype.so:print/freetype2
TOOLS_USE=		GL=egl,gl,glu	\
			XORG=ice,sm,x11,xau,xcomposite,xcursor,xdamage,xdmcp,xext,xfixes,xft,xi,xinerama,xkbfile,xmu,xpm,xrandr,xrender,xres,xscrnsaver,xt,xtst,xv,xxf86vm
TOOLS_CMAKE_BOOL=	CGNS_BUILD_CGNSTOOLS
TOOLS_CMAKE_ON=		-DTCL_INCLUDE_PATH:STRING="${TCL_INCLUDEDIR}" \
			-DTK_INCLUDE_PATH:STRING="${TK_INCLUDEDIR}"

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.if ${FORTRAN_DEFAULT} != flang
FFLAGS+=	-std=legacy
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|tk-private/||' ${WRKSRC}/src/cgnstools/tkogl/tkogl.c

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libcgns.so.${PORTVERSION:R} \
		${STAGEDIR}${PREFIX}/lib/libcgns.so.${PORTVERSION:R:R}

do-test:
	cd ${TEST_WRKSRC} && \
	${SETENV} ${TEST_ENV} ctest -C ${CMAKE_BUILD_TYPE}

.include <bsd.port.mk>
