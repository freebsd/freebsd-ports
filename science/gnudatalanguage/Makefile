# New ports collection makefile for:	gnudatalanguage
# Date created:		Sat 22 oct 2005
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	gnudatalanguage
PORTVERSION=	0.8.11
PORTREVISION=	2
CATEGORIES=	science lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
.if defined(BUILD_PYTHON_MODULE)
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
.endif
DISTNAME=	gdl-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT?=	GDL, a free IDL compatible incremental compiler

#---------------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_IMAGEMAGICK:	remove ImageMagick support
# - WITHOUT_HDF5:		remove HDF5 support
# - WITHOUT_NETCDF:		remove netCDF support
# - WITHOUT_HDF:		remove HDF 4 suppport (conflict with netCDF)
# - WITHOUT_PYTHON:		don't build the interface to python
# - WITH_FFTW3:			faster fft routine than GSL
#
#---------------------------------------------------------------------------

LIB_DEPENDS+=	plplotd.10:${PORTSDIR}/math/plplot	\
		gsl.9:${PORTSDIR}/math/gsl		\
		readline.5:${PORTSDIR}/devel/readline

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include"	\
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib"

SLAVEDIRS=	science/py-gnudatalanguage

CONFLICTS=	antlr-2.*

.if defined(BUILD_PYTHON_MODULE)
CATEGORIES+=	python
CONFIGURE_ARGS+=--enable-python_module
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/GDL.so
PLIST_SUB+=	MASTER="@comment "
.else
PLIST_SUB+=	MASTER=""
.endif

.if !defined(WITHOUT_IMAGEMAGICK)
LIB_DEPENDS+=	Magick.9:${PORTSDIR}/graphics/ImageMagick
CONFIGURE_ARGS+=--with-Magick=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-Magick=no
.endif

.if !defined(WITHOUT_HDF5)
LIB_DEPENDS+=	hdf5.0:${PORTSDIR}/science/hdf5
CONFIGURE_ARGS+=--with-hdf5=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-hdf5=no
.endif

.if !defined(WITHOUT_NETCDF)
LIB_DEPENDS+=	netcdf.1:${PORTSDIR}/science/netcdf
CONFIGURE_ARGS+=--with-netcdf=${LOCALBASE} --with-hdf=no
.else
CONFIGURE_ARGS+=--with-netcdf=no
. if !defined(WITHOUT_HDF)
LIB_DEPENDS+=	df.1:${PORTSDIR}/science/hdf
CONFIGURE_ARGS+=--with-hdf=${LOCALBASE}
. else
CONFIGURE_ARGS+=--with-hdf=no
. endif
.endif

.if !defined(WITHOUT_PYTHON) || defined(BUILD_PYTHON_MODULE)
USE_PYTHON=	2.3+
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/numarray:${PORTSDIR}/math/py-numarray
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/numarray:${PORTSDIR}/math/py-numarray \
		${PYTHON_SITELIBDIR}/matplotlib:${PORTSDIR}/math/py-matplotlib
CONFIGURE_ENV+=	PYTHON_VERSION=${_PYTHON_VERSION}
CONFIGURE_ARGS+=--with-python=${PYTHONBASE}
.else
CONFIGURE_ARGS+=--with-python=no
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libfftw3.so)
WITH_FFTW3=	yes
.endif
.if defined(WITH_FFTW3)
LIB_DEPENDS+=	fftw3.3:${PORTSDIR}/math/fftw3		\
		fftw3f.3:${PORTSDIR}/math/fftw3-float
CONFIGURE_ARGS+=--with-fftw=${LOCALBASE}
.endif

.if ${OSVERSION} < 500000
BROKEN=	Does not compile with gcc-2.95
.endif

.if defined(BUILD_PYTHON_MODULE)
do-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libgdl.so.0 ${PYTHON_SITELIBDIR}/GDL.so
.endif

.if !defined(BUILD_PYTHON_MODULE)
post-install:
. if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/pro/* ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
. endif
.endif

.if defined(MAINTAINER_MODE)
test:	install
. if defined(BUILD_PYTHON_MODULE)
	@${ECHO_CMD} 'import GDL' > ${WRKDIR}/testgdl.py
	@${ECHO_CMD} 'print GDL.function("sin",(1,))' >> ${WRKDIR}/testgdl.py
	${PYTHON_CMD} ${WRKDIR}/testgdl.py
. else
	@${ECHO_CMD} ".RUN ${EXAMPLESDIR}/test_suite.pro" > ${WRKDIR}/testgdl
	@${ECHO_CMD} "exit" >> ${WRKDIR}/testgdl
	${PREFIX}/bin/gdl < ${WRKDIR}/testgdl
. endif
.endif

.include <bsd.port.post.mk>
