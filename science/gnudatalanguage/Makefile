# Created by: thierry@pompo.net

PORTNAME=	gnudatalanguage
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-rc.3
PORTREVISION=	3
CATEGORIES=	science lang
.if defined(BUILD_PYTHON_MODULE)
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
.endif

MAINTAINER=	thierry@FreeBSD.org
COMMENT?=	Free IDL-compatible incremental compiler

LICENSE=	GPLv2

LIB_DEPENDS+=	libgeotiff.so:graphics/libgeotiff\
		libexpat.so:textproc/expat2	\
		libplplot.so:math/plplot	\
		libtiff.so:graphics/tiff	\
		libshp.so:devel/shapelib	\
		libpng.so:graphics/png		\
		libsz.so:science/szip		\
		libps.so:print/pslib		\
		libgsl.so:math/gsl

USE_GITHUB=	yes
GH_PROJECT=	gdl

USES=		cmake compiler:c++11-lang fortran ncurses pkgconfig readline \
		tar:tgz xorg
USE_WX=		3.0+
USE_XORG=	x11 sm ice xext

# Disable ncurses and readline from ports
# TODO: create a port for Cmsvlib http://cow.physics.wisc.edu/~craigm/idl/down/cmsvlib.tar.gz
# TODO:	create a port for Astron http://idlastro.gsfc.nasa.gov/ftp/astron.tar.gz
# TODO:	create a port for TexToIdl http://physics.mnstate.edu/mcraig/textoidl/textoidl-2-1-2.tar

CMAKE_ARGS=	-DREADLINEDIR:STRING="/usr"	\
		-DOPENMP:BOOL=NO		\
		-DNCURSESDIR:STRING="/usr"	\
		-DPYTHON:BOOL=NO
CPPFLAGS+=	${CFLAGS} -fno-inline -DNPY_NO_DEPRECATED_API -DNPY_1_7_API_VERSION
CXXFLAGS+=	-std=gnu++11 -DACCEPT_USE_OF_DEPRECATED_PROJ_API_H=1
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
TEST_TARGET=	check

SLAVEDIRS=	science/py-gnudatalanguage

# Upstream prefer GraphicsMagick over ImageMackick but ATM it fails
# see https://github.com/gnudatalanguage/gdl/issues/611
# + Python is broken on 1.0.0-rc2 See issue  #757
#OPTIONS_DEFINE=	EIGEN EXAMPLES FFTW GLPK GRAPHICSMAGICK GRIB HDF5 LIBPROJ4 MPI NETCDF PYTHON UDUNITS
#OPTIONS_DEFAULT=EIGEN FFTW GLPK GRAPHICSMAGICK GRIB HDF5 LIBPROJ4 NETCDF PYTHON UDUNITS
OPTIONS_DEFINE=	EIGEN EXAMPLES FFTW GLPK IMAGEMAGICK GRIB HDF5 LIBPROJ4 MPI NETCDF UDUNITS
OPTIONS_DEFAULT=EIGEN FFTW GLPK IMAGEMAGICK GRIB HDF5 LIBPROJ4 NETCDF UDUNITS

EIGEN_DESC=		Eigen3 support (boost performance)
EIGEN_USES=		eigen:3
EIGEN_CMAKE_ON=		-DEIGEN3:BOOL=YES
EIGEN_CMAKE_OFF=	-DEIGEN3:BOOL=NO

FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3		\
			libfftw3f.so:math/fftw3-float
FFTW_CMAKE_ON=		-DFFTW:BOOL=YES
FFTW_CMAKE_OFF=		-DFFTW:BOOL=NO

GLPK_DESC=		Support GLPK for Simplex (Linear programming)
GLPK_LIB_DEPENDS=	libglpk.so:math/glpk
GLPK_CMAKE_ON=		-DGLPK=ON:BOOL=YES
GLPK_CMAKE_OFF=		-DGLPK=OFF:BOOL=NO

# Temporary swith to ImageMagick
#GRAPHICSMAGICK_DESC=		Support GraphicsMagick
#GRAPHICSMAGICK_LIB_DEPENDS=	libGraphicsMagick.so:graphics/GraphicsMagick
#GRAPHICSMAGICK_CMAKE_ON=	-DGRAPHICSMAGICK:BOOL=YES
#GRAPHICSMAGICK_CMAKE_OFF=	-DGRAPHICSMAGICK:BOOL=NO
IMAGEMAGICK_DESC=	Support ImageMagick
IMAGEMAGICK_LIB_DEPENDS=libMagick++-6.so:graphics/ImageMagick6
IMAGEMAGICK_CMAKE_ON=	-DGRAPHICSMAGICK:BOOL=NO -DMAGICK:BOOL=YES -DMAGICKDIR=${LOCALBASE}
IMAGEMAGICK_CMAKE_OFF=	-DMAGICK:BOOL=NO

GRIB_DESC=		Support GRIB messages
GRIB_LIB_DEPENDS=	libgrib_api.so:science/grib_api
GRIB_CMAKE_ON=		-DGRIB:BOOL=YES
GRIB_CMAKE_OFF=		-DGRIB:BOOL=NO

HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HDF5_CMAKE_ON=		-DHDF5:BOOL=YES
HDF5_CMAKE_OFF=		-DHDF5:BOOL=NO -DHDF:BOOL=NO

LIBPROJ4_DESC=		Support cartographic processes
LIBPROJ4_LIB_DEPENDS=	libproj.so:graphics/proj
LIBPROJ4_CMAKE_ON=	-DLIBPROJ4:BOOL=YES
LIBPROJ4_CMAKE_OFF=	-DLIBPROJ4:BOOL=NO

MPI_LIB_DEPENDS=	libmpich.so:net/mpich
MPI_CMAKE_ON=		-DMPI:BOOL=ON
MPI_CMAKE_OFF=		-DMPI:BOOL=OFF -DMPIDIR=/none

NETCDF_LIB_DEPENDS=	libnetcdf.so:science/netcdf
NETCDF_CMAKE_ON=	-DNETCDF:BOOL=YES -DHDF:BOOL=NO
NETCDF_CMAKE_OFF=	-DNETCDF:BOOL=NO

#PYTHON_USES=		python:3.7+
#PYTHON_BUILD_DEPENDS=	${PYNUMPY}
#PYTHON_RUN_DEPENDS=	${PYNUMPY} \
#			${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}
#PYTHON_CMAKE_ON=	-DPYTHON:BOOL=YES -DPYTHONVERSION:STRING="${PYTHON_VER}"
#PYTHON_CMAKE_OFF=	-DPYTHON:BOOL=NO

# QHULL IS NOT NEEDED YET!
#QHULL_DESC=		Enable Triangulate and Qhull support
#QHULL_LIB_DEPENDS=	libqhull.so:math/qhull
#QHULL_CMAKE_ON=		-DQHULL:BOOL=YES
#QHULL_CMAKE_OFF=	-DQHULL:BOOL=NO

UDUNITS_LIB_DEPENDS=	libudunits2.so:science/udunits
UDUNITS_CMAKE_ON=	-DUDUNITS:BOOL=YES
UDUNITS_CMAKE_OFF=	-DUDUNITS:BOOL=NO

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
