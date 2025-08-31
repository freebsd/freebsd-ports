PORTNAME=	gnudatalanguage
PORTVERSION=	1.1.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	science lang
MASTER_SITES=	https://github.com/${PORTNAME}/gdl/releases/download/v${PORTVERSION}/
.if defined(BUILD_PYTHON_MODULE)
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
.endif
DISTNAME=	gdl-${DISTVERSIONPREFIX}${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT?=	Free IDL-compatible incremental compiler
WWW=		https://github.com/gnudatalanguage/gdl

LICENSE=	GPLv2

LIB_DEPENDS+=	libGraphicsMagick.so:graphics/GraphicsMagick	\
		libgeotiff.so:graphics/libgeotiff	\
		libfreetype.so:print/freetype2	\
		libexpat.so:textproc/expat2	\
		libplplot.so:math/plplot	\
		libtiff.so:graphics/tiff	\
		libhpdf.so:print/libharu	\
		libshp.so:devel/shapelib	\
		libpng.so:graphics/png		\
		libsz.so:science/libaec		\
		libglpk.so:math/glpk		\
		libps.so:print/pslib		\
		libgsl.so:math/gsl

#USE_GITHUB=	yes
#GH_PROJECT=	gdl

USES=		cmake compiler:c++11-lang fortran ncurses pkgconfig readline \
		xorg
USE_WX=		3.0+
USE_XORG=	x11 sm ice xext

# Disable ncurses and readline from ports
# TODO:	create a port for Astron http://idlastro.gsfc.nasa.gov/ftp/astron.tar.gz

CMAKE_ARGS=	-DREADLINEDIR:STRING="/usr"	\
		-DOPENMP:BOOL=ON		\
		-DNCURSESDIR:STRING="/usr"	\
		-DGRAPHICSMAGICK:BOOL=YES	\
		-DX11:BOOL=ON
CPPFLAGS+=	${CFLAGS} -fno-inline -DNPY_NO_DEPRECATED_API -DNPY_1_7_API_VERSION
CXXFLAGS+=	-std=gnu++11
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
TEST_TARGET=	test

SLAVEDIRS=	science/py-gnudatalanguage

# Upstream prefer GraphicsMagick over ImageMackick
# see https://github.com/gnudatalanguage/gdl/issues/611
# and https://github.com/gnudatalanguage/gdl/issues/1044 for ImageMagick 7
OPTIONS_DEFINE=	EIGEN EXAMPLES FFTW GRIB HDF5 LIBPROJ4	\
		MPICH NETCDF PYTHON QHULL UDUNITS
OPTIONS_DEFAULT=EIGEN FFTW GRIB HDF5 LIBPROJ4 NETCDF PYTHON	\
		QHULL UDUNITS

EIGEN_DESC=		Eigen3 support (boost performance)
EIGEN_USES=		eigen:3
EIGEN_CMAKE_ON=		-DEIGEN3:BOOL=YES
EIGEN_CMAKE_OFF=	-DEIGEN3:BOOL=NO

FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3		\
			libfftw3f.so:math/fftw3-float
FFTW_CMAKE_ON=		-DFFTW:BOOL=YES
FFTW_CMAKE_OFF=		-DFFTW:BOOL=NO

GRIB_DESC=		Support GRIB messages
GRIB_LIB_DEPENDS=	libeccodes.so:science/eccodes
GRIB_CMAKE_ON=		-DGRIB:BOOL=YES
GRIB_CMAKE_OFF=		-DGRIB:BOOL=NO

HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HDF5_CMAKE_ON=		-DHDF5:BOOL=YES
HDF5_CMAKE_OFF=		-DHDF5:BOOL=NO -DHDF:BOOL=NO

LIBPROJ4_DESC=		Support cartographic processes
LIBPROJ4_LIB_DEPENDS=	libproj.so:graphics/proj
LIBPROJ4_CMAKE_ON=	-DLIBPROJ:BOOL=YES
LIBPROJ4_CMAKE_OFF=	-DLIBPROJ:BOOL=NO

MPICH_USES=		mpi
MPICH_CMAKE_ON=		-DMPI:BOOL=ON -DMPIDIR:PATH=${MPI_HOME}
MPICH_CMAKE_OFF=	-DMPI:BOOL=OFF -DMPIDIR=/none

NETCDF_LIB_DEPENDS=	libnetcdf.so:science/netcdf
NETCDF_CMAKE_ON=	-DNETCDF:BOOL=YES -DHDF:BOOL=NO
NETCDF_CMAKE_OFF=	-DNETCDF:BOOL=NO

PYTHON_USES=		python
PYTHON_BUILD_DEPENDS=	${PYNUMPY}
PYTHON_RUN_DEPENDS=	${PYNUMPY} \
			${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}
PYTHON_CMAKE_ON=	-DPYTHON:BOOL=YES -DPYTHONVERSION:STRING="${PYTHON_VER}"
PYTHON_CMAKE_OFF=	-DPYTHON:BOOL=NO

QHULL_DESC=		Enable Triangulate and Qhull support
QHULL_LIB_DEPENDS=	libqhull_r.so:math/qhull
QHULL_CMAKE_ON=		-DQHULL:BOOL=YES
QHULL_CMAKE_OFF=	-DQHULL:BOOL=NO

UDUNITS_LIB_DEPENDS=	libudunits2.so:science/udunits
UDUNITS_CMAKE_ON=	-DUDUNITS2:BOOL=YES
UDUNITS_CMAKE_OFF=	-DUDUNITS2:BOOL=NO

.if defined(BUILD_PYTHON_MODULE)
CATEGORIES+=	python
CMAKE_ARGS+=	-DPYTHON_MODULE:BOOL=YES
PLIST=		${.CURDIR}/pkg-plist.pymod
.else
CMAKE_ARGS+=	-DPYTHON_MODULE:BOOL=NO
.endif

.if defined(BUILD_PYTHON_MODULE)
do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/src/GDL.so ${STAGEDIR}${PYTHON_SITELIBDIR}/
.endif

.if !defined(BUILD_PYTHON_MODULE)
post-install:
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
