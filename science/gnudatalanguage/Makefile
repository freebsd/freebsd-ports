# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	gnudatalanguage
DISTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	science lang
MASTER_SITES=	SF/${PORTNAME}/gdl/${DISTVERSION}
.if defined(BUILD_PYTHON_MODULE)
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
.endif
DISTNAME=	gdl-${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT?=	GDL, a free IDL compatible incremental compiler

LICENSE=	GPLv2

#NO_STAGE=	yes

#---------------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_GRAPHICSMAGICK:	remove GraphicsMagick support
# - WITHOUT_HDF5:		remove HDF5 support
# - WITHOUT_NETCDF:		remove netCDF support
# - WITHOUT_HDF:		remove HDF 4 suppport (conflict with netCDF)
# - WITHOUT_PYTHON:		don't build the interface to python
# - WITHOUT_FFTW3:		remove FFTW (faster fft routine than GSL)
# - WITHOUT_EIGEN		remove Eigen support (boost performance)
# - WITHOUT_UDUNITS		remove unit conversion in IMSL_CONSTANT
#
#---------------------------------------------------------------------------

LIB_DEPENDS+=	libplplotd.so:${PORTSDIR}/math/plplot	\
		libps.so:${PORTSDIR}/print/pslib	\
		libgsl.so:${PORTSDIR}/math/gsl

USE_DOS2UNIX=	src/plotting_xyouts.cpp

USE_GCC=	yes
USE_WX=		2.8
USE_XORG=	x11
USES=		pkgconfig cmake

# Disable ncurses and readline from ports
# Disable ImageMagick (does'nt work with plplot because dynamic drivers
#	are enabled by default)
# TODO: add a slave port for mpich - ATM just deactivate its support.
CMAKE_ARGS=	-DREADLINEDIR:STRING="/usr"		\
		-DNCURSESDIR:STRING="/usr"		\
		-DMPICH:BOOL=NO				\
		-DMAGICK:BOOL=NO
CPPFLAGS+=	${CFLAGS} -fno-inline ${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib

SLAVEDIRS=	science/py-gnudatalanguage

.if defined(BUILD_PYTHON_MODULE)
CATEGORIES+=	python
CMAKE_ARGS+=	-DPYTHON_MODULE:BOOL=YES -DOPENMP:BOOL=NO
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/GDL.so
PLIST_SUB+=	MASTER="@comment "
.else
CMAKE_ARGS+=	-DPYTHON_MODULE:BOOL=NO
PLIST_SUB+=	MASTER=""
.endif

.if !defined(WITHOUT_GRAPHICSMAGICK)
LIB_DEPENDS+=	libGraphicsMagick.so.12:${PORTSDIR}/graphics/GraphicsMagick13
CMAKE_ARGS+=	-DGRAPHICSMAGICK:BOOL=YES
.else
CMAKE_ARGS+=	-DGRAPHICSMAGICK:BOOL=NO
.endif

.if !defined(WITHOUT_HDF5)
LIB_DEPENDS+=	libhdf5.so.7:${PORTSDIR}/science/hdf5-18
CMAKE_ARGS+=	-DHDF5:BOOL=YES
.else
CMAKE_ARGS+=	-DHDF5:BOOL=NO
.endif

.if !defined(WITHOUT_NETCDF)
LIB_DEPENDS+=	libnetcdf.so:${PORTSDIR}/science/netcdf
CMAKE_ARGS+=	-DNETCDF:BOOL=YES -DHDF:BOOL=NO
.else
CMAKE_ARGS+=	-DNETCDF:BOOL=NO
. if !defined(WITHOUT_HDF)
LIB_DEPENDS+=	libdf.so.2:${PORTSDIR}/science/hdf
CMAKE_ARGS+=	-DHDF:BOOL=YES
. else
CMAKE_ARGS+=	-DHDF:BOOL=NO
. endif
.endif

.if !defined(WITHOUT_EIGEN)
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/eigen3.pc:${PORTSDIR}/math/eigen3
CMAKE_ARGS+=	-DEIGEN3:BOOL=YES
.else
CMAKE_ARGS+=	-DEIGEN3:BOOL=NO
.endif

.if !defined(WITHOUT_UDUNITS)
LIB_DEPENDS+=	libudunits2.so:${PORTSDIR}/science/udunits
CMAKE_ARGS+=	-DUDUNITS:BOOL=YES
.else
CMAKE_ARGS+=	-DUDUNITS:BOOL=NO
.endif

.if !defined(WITHOUT_PYTHON) || defined(BUILD_PYTHON_MODULE)
USE_PYTHON=	-2.7
BUILD_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:${PORTSDIR}/math/py-matplotlib
CMAKE_ARGS+=	-DPYTHON:BOOL=YES -DPYTHONVERSION:STRING="${PYTHON_VER}"
.else
CMAKE_ARGS+=	-DPYTHON:BOOL=NO
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800503
BROKEN=	Does not build with ancient binutils
.endif

.if !defined(WITHOUT_FFTW3)
LIB_DEPENDS+=	libfftw3.so:${PORTSDIR}/math/fftw3		\
		libfftw3f.so:${PORTSDIR}/math/fftw3-float
CMAKE_ARGS+=	-DFFTW:BOOL=YES
.else
CMAKE_ARGS+=	-DFFTW:BOOL=NO
.endif

.if defined(BUILD_PYTHON_MODULE)
do-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libgdl.so.0 ${PYTHON_SITELIBDIR}/GDL.so
.endif

.if !defined(BUILD_PYTHON_MODULE)
post-stage:
. if !defined(NOPORTEXAMPLES)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/testsuite
	(cd ${WRKSRC}/testsuite && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/testsuite/)
. endif
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

.include <bsd.port.post.mk>
