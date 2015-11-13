# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	gnudatalanguage
DISTVERSION=	0.9.5
PORTREVISION=	7
CATEGORIES=	science lang
MASTER_SITES=	SF/${PORTNAME}/gdl/${DISTVERSION}
.if defined(BUILD_PYTHON_MODULE)
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
.endif
DISTNAME=	gdl-${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT?=	GDL, a free IDL compatible incremental compiler

LICENSE=	GPLv2

LIB_DEPENDS+=	libplplot.so:${PORTSDIR}/math/plplot	\
		libpng.so:${PORTSDIR}/graphics/png	\
		libps.so:${PORTSDIR}/print/pslib	\
		libgsl.so:${PORTSDIR}/math/gsl

USE_WX=		2.8
WX_UNICODE=	yes
USE_XORG=	x11 sm ice xext
USES=		cmake:outsource compiler:gcc-c++11-lib dos2unix ncurses pkgconfig readline

# Disable ncurses and readline from ports
# Disable ImageMagick (does'nt work with plplot because dynamic drivers
#	are enabled by default)
# TODO: add a slave port for mpich
CMAKE_ARGS=	-DREADLINEDIR:STRING="/usr"		\
		-DNCURSESDIR:STRING="/usr"		\
		-DMPICH:BOOL=NO				\
		-DMAGICK:BOOL=NO
CPPFLAGS+=	${CFLAGS} -fno-inline
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

SLAVEDIRS=	science/py-gnudatalanguage

OPTIONS_DEFINE=	EIGEN EXAMPLES FFTW GRAPHICSMAGICK GRIB HDF5 LIBPROJ4 MPICH2 NETCDF PYTHON UDUNITS
OPTIONS_DEFAULT=EIGEN EXAMPLES FFTW GRAPHICSMAGICK GRIB HDF5 LIBPROJ4 NETCDF PYTHON UDUNITS

EIGEN_DESC=	Eigen3 support (boost performance)
EIGEN_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen3.pc:${PORTSDIR}/math/eigen3
EIGEN_CMAKE_ON=		-DEIGEN3:BOOL=YES
EIGEN_CMAKE_OFF=	-DEIGEN3:BOOL=NO

FFTW_LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3		\
			libfftw3f.so:${PORTSDIR}/math/fftw3-float
FFTW_CMAKE_ON=		-DFFTW:BOOL=YES
FFTW_CMAKE_OFF=		-DFFTW:BOOL=NO

GRAPHICSMAGICK_LIB_DEPENDS=	libGraphicsMagick.so:${PORTSDIR}/graphics/GraphicsMagick
GRAPHICSMAGICK_CMAKE_ON=	-DGRAPHICSMAGICK:BOOL=YES
GRAPHICSMAGICK_CMAKE_OFF=	-DGRAPHICSMAGICK:BOOL=NO

GRIB_DESC=		Support GRIB messages
GRIB_LIB_DEPENDS=	libgrib_api.so:${PORTSDIR}/science/grib_api
GRIB_CMAKE_ON=		-DGRIB:BOOL=YES
GRIB_CMAKE_OFF=		-DGRIB:BOOL=NO

HDF5_LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5
HDF5_CMAKE_ON=		-DHDF5:BOOL=YES
HDF5_CMAKE_OFF=		-DHDF5:BOOL=NO -DHDF:BOOL=NO

LIBPROJ4_DESC=		Support cartographic processes
LIBPROJ4_LIB_DEPENDS=	libproj4.so:${PORTSDIR}/math/libproj4
LIBPROJ4_CMAKE_ON=	-DLIBPROJ4:BOOL=YES
LIBPROJ4_CMAKE_OFF=	-DLIBPROJ4:BOOL=NO

MPICH2_LIB_DEPENDS=	libmpich.so.8:${PORTSDIR}/net/mpich2
MPICH2_CMAKE_ON=	-DMPICH:BOOL=YES
MPICH2_CMAKE_OFF=	-DMPICH:BOOL=NO

NETCDF_LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf
NETCDF_CMAKE_ON=	-DNETCDF:BOOL=YES -DHDF:BOOL=NO
NETCDF_CMAKE_OFF=	-DNETCDF:BOOL=NO

PYTHON_USES=		python
PYTHON_BUILD_DEPENDS=	${PYNUMPY}
PYTHON_RUN_DEPENDS=	${PYNUMPY} \
			${PYTHON_PKGNAMEPREFIX}matplotlib>0:${PORTSDIR}/math/py-matplotlib
PYTHON_CMAKE_ON=	-DPYTHON:BOOL=YES -DPYTHONVERSION:STRING="${PYTHON_VER}"
PYTHON_CMAKE_OFF=	-DPYTHON:BOOL=NO

UDUNITS_LIB_DEPENDS=	libudunits2.so:${PORTSDIR}/science/udunits
UDUNITS_CMAKE_ON=	-DUDUNITS:BOOL=YES
UDUNITS_CMAKE_OFF=	-DUDUNITS:BOOL=NO

.if defined(BUILD_PYTHON_MODULE)
CATEGORIES+=	python
CMAKE_ARGS+=	-DPYTHON_MODULE:BOOL=YES -DOPENMP:BOOL=NO
PLIST=		pkg-plist.pymod
.else
CMAKE_ARGS+=	-DPYTHON_MODULE:BOOL=NO
.endif

.if defined(BUILD_PYTHON_MODULE)
do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/src/libgdl.so ${STAGEDIR}${PYTHON_SITELIBDIR}/GDL.so
.endif

.if !defined(BUILD_PYTHON_MODULE)
post-stage:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/testsuite
	(cd ${WRKSRC}/testsuite && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/testsuite/)
.endif

.if defined(MAINTAINER_MODE)
regression-test:	install
. if defined(BUILD_PYTHON_MODULE)
	@${ECHO_CMD} 'import GDL' > ${WRKDIR}/testgdl.py
	@${ECHO_CMD} 'print GDL.function("sin",(1,))' >> ${WRKDIR}/testgdl.py
	${PYTHON_CMD} ${WRKDIR}/testgdl.py
. else
	@${ECHO_CMD} ".RUN ${EXAMPLESDIR}/testsuite/test_suite.pro"	\
		> ${WRKDIR}/testgdl
	@${ECHO_CMD} "exit" >> ${WRKDIR}/testgdl
	${PREFIX}/bin/gdl < ${WRKDIR}/testgdl
. endif
.endif

.include <bsd.port.mk>
