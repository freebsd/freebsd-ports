PORTNAME=	mathgl
DISTVERSION=	2.5
PORTREVISION=	3
CATEGORIES=	math graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for high-quality scientific data visualization

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libgsl.so:math/gsl \
		libhdf5.so:science/hdf5 \
		libhpdf.so:print/libharu \
		libltdl.so:devel/libltdl \
		libpng.so:graphics/png \
		libsz.so:science/libaec

USES=		cmake compiler:c++11-lang gettext-runtime gl jpeg xorg
USE_GL=		gl glu glut
USE_XORG=	xi xmu
USE_LDCONFIG=	yes

.for v in double gif glut gsl hdf5 jpeg ltdl mgl2 opengl pdf png zlib
CMAKE_ARGS+=	-Denable-${v}=ON
.endfor

.for v in doc-info doc-html lgpl mgltex
CMAKE_ARGS+=	-Denable-${v}=OFF
.endfor

OPTIONS_DEFINE=		PYTHON MPI
OPTIONS_GROUP=		GRAPHICS
OPTIONS_GROUP_GRAPHICS=	QT5 FLTK WXGTK
OPTIONS_RADIO=		THREADS
OPTIONS_RADIO_THREADS=	PTHREADS OPENMP
OPTIONS_DEFAULT=	QT5
OPTIONS_SUB=		yes
GRAPHICS_DESC=		Graphics support
PTHREADS_DESC=		Enable POSIX threads support (broken, fix pending release)
OPENMP_DESC=		Parallel processing support via OpenMP (broken, cmake bug)
FLTK_DESC=		Enable fltk widget
PLIST_SUB=		SHLIB_VER=7.6.0

PYTHON_CMAKE_BOOL=	enable-python
PYTHON_BUILD_DEPENDS=	swig:devel/swig \
			${PYNUMPY}
PYTHON_RUN_DEPENDS=	${PYNUMPY}
PYTHON_BROKEN=		Python option needs to be fixed: lgpl needs to be enabled for it

MPI_CMAKE_BOOL=		enable-mpi
MPI_LIB_DEPENDS=	libmpi.so:net/openmpi

QT5_CMAKE_BOOL=		enable-qt5
QT5_USE=		QT=core,gui,opengl,printsupport,widgets,buildtools_build,qmake_build
QT5_USES=		desktop-file-utils qt:5 shared-mime-info

FLTK_CMAKE_BOOL=	enable-fltk
FLTK_LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk
FLTK_USE=		XORG=ice,sm,x11,xext

WXGTK_CMAKE_BOOL=	wx
WXGTK_USE=		WX=3.0+

OPENMP_CMAKE_BOOL=	enable-openmp

PTHREADS_CMAKE_BOOL=	enable-pthread

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MFLTK} && ! ${PORT_OPTIONS:MQT5}
PLIST_SUB+=	FLTK_OR_QT5="@comment "
.else
PLIST_SUB+=	FLTK_OR_QT5=""
.endif

.if ${PORT_OPTIONS:MFLTK} && ${PORT_OPTIONS:MQT5}
PLIST_SUB+=	FLTK_AND_QT5=""
.else
PLIST_SUB+=	FLTK_AND_QT5="@comment "
.endif

.include <bsd.port.mk>
