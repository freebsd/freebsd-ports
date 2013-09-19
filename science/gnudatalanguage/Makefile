# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	gnudatalanguage
DISTVERSION=	0.9.3
PORTREVISION=	3
CATEGORIES=	science lang
MASTER_SITES=	SF/${PORTNAME}/gdl/${DISTVERSION}
.if defined(BUILD_PYTHON_MODULE)
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
.endif
DISTNAME=	gdl-${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT?=	GDL, a free IDL compatible incremental compiler

LICENSE=	GPLv2

#---------------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_GRAPHICSMAGICK:	remove GraphicsMagick support
# - WITHOUT_HDF5:		remove HDF5 support
# - WITHOUT_NETCDF:		remove netCDF support
# - WITHOUT_HDF:		remove HDF 4 suppport (conflict with netCDF)
# - WITHOUT_PYTHON:		don't build the interface to python
# - WITH_FFTW3:			faster fft routine than GSL
#
#---------------------------------------------------------------------------

LIB_DEPENDS+=	libplplotd.so:${PORTSDIR}/math/plplot	\
		libps.so:${PORTSDIR}/print/pslib		\
		libgsl.so:${PORTSDIR}/math/gsl		\
		libdps.so:${PORTSDIR}/x11/dgs

USE_GCC=	yes
USE_WX=		2.8
USE_XORG=	x11
USES=		pkgconfig
GNU_CONFIGURE=	yes
# Disable ncurses and readline from ports
# Disable ImageMagick (does'nt work with plplot because dynamic drivers
#	are enabled by default)
CONFIGURE_ARGS=	--with-ncursesdir=/usr --with-readlinedir=/usr --without-Magick
CONFIGURE_ENV=	wxConfig=${WX_CONFIG}
CPPFLAGS+=	${CFLAGS} -fno-inline ${PTHREAD_CFLAGS} -I${LOCALBASE}/include ${GM_INC}
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib

SLAVEDIRS=	science/py-gnudatalanguage

.if defined(BUILD_PYTHON_MODULE)
CATEGORIES+=	python
CONFIGURE_ARGS+=--enable-python_module --with-openmp=no
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/GDL.so
PLIST_SUB+=	MASTER="@comment "
.else
MAN1=		gdl.1
PLIST_SUB+=	MASTER=""
.endif

.if !defined(WITHOUT_GRAPHICSMAGICK)
LIB_DEPENDS+=	libGraphicsMagick.so.12:${PORTSDIR}/graphics/GraphicsMagick13
CONFIGURE_ARGS+=--with-GraphicsMagick=${LOCALBASE}
GM_INC=		-I${LOCALBASE}/include/GraphicsMagick
.else
CONFIGURE_ARGS+=--with-Magick=no
.endif

.if !defined(WITHOUT_HDF5)
LIB_DEPENDS+=	libhdf5.so.7:${PORTSDIR}/science/hdf5-18
CONFIGURE_ARGS+=--with-hdf5=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-hdf5=no
.endif

.if !defined(WITHOUT_NETCDF)
LIB_DEPENDS+=	libnetcdf.so:${PORTSDIR}/science/netcdf
CONFIGURE_ARGS+=--with-netcdf=${LOCALBASE} --with-hdf=no
.else
CONFIGURE_ARGS+=--with-netcdf=no
. if !defined(WITHOUT_HDF)
LIB_DEPENDS+=	libdf.so.2:${PORTSDIR}/science/hdf
CONFIGURE_ARGS+=--with-hdf=${LOCALBASE}
. else
CONFIGURE_ARGS+=--with-hdf=no
. endif
.endif

.if !defined(WITHOUT_PYTHON) || defined(BUILD_PYTHON_MODULE)
USE_PYTHON=	-2.7
BUILD_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:${PORTSDIR}/math/py-matplotlib
CONFIGURE_ENV+=	PYTHON_VERSION=${PYTHON_VER}
CONFIGURE_ARGS+=--with-python=${PYTHONBASE}
.else
CONFIGURE_ARGS+=--with-python=no
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800503
BROKEN=	Does not build with ancient binutils
.endif

.if defined(PACKAGE_BUILDING) || exists(${LOCALBASE}/lib/libfftw3.so)
WITH_FFTW3=	yes
.endif
.if defined(WITH_FFTW3)
LIB_DEPENDS+=	libfftw3.so:${PORTSDIR}/math/fftw3		\
		libfftw3f.so:${PORTSDIR}/math/fftw3-float
CONFIGURE_ARGS+=--with-fftw=${LOCALBASE}
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|g'	\
		${WRKSRC}/${CONFIGURE_SCRIPT}

.if defined(BUILD_PYTHON_MODULE)
do-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libgdl.so.0 ${PYTHON_SITELIBDIR}/GDL.so
.endif

.if !defined(BUILD_PYTHON_MODULE)
post-install:
. if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/testsuite
	(cd ${WRKSRC}/testsuite && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/testsuite/)
	${RM} ${EXAMPLESDIR}/testsuite/Makefile.in.orig
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
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
