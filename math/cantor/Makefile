# $FreeBSD$

PORTNAME=	cantor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	2
CATEGORIES=	math kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mathematical software frontend by KDE

LIB_DEPENDS=	libAnalitza.so:math/analitza \
		libcln.so:math/cln \
		libqalculate.so:math/libqalculate \
		libspectre.so:print/libspectre \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5
BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:5 \
		pkgconfig python:3.4+ qt:5 tar:xz
USE_KDE=	attica auth archive bookmarks codecs completion config \
		configwidgets coreaddons crash ecm emoticons i18n iconthemes \
		itemmodels itemviews init jobwidgets kdelibs4support kio \
		newstuff parts pty service solid sonnet syntaxhighlighting \
		texteditor textwidgets widgetsaddons xmlgui
USE_QT=		concurrent core dbus gui network printsupport svg widgets xml xmlpatterns \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	LUAJIT MAXIMA OCTAVE R SAGE SCILAB DOCS
OPTIONS_SUB=	yes # R LUAJIT

LUAJIT_DESC=	Build LuaJIT backend and install LuaJIT
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_CMAKE_OFF=	-DWITH_LuaJIT:BOOL=FALSE

MAXIMA_DESC=	Install Maxima
MAXIMA_RUN_DEPENDS=	maxima:math/maxima

OCTAVE_DESC=	Install Octave
OCTAVE_RUN_DEPENDS=	octave:math/octave

R_DESC=		Build R backend and install R
R_LIB_DEPENDS=	libR.so:math/R
# Required to set CFLAGS for -lgfortran.
R_USES=		fortran
R_CMAKE_OFF=	-DWITH_R:BOOL=FALSE

SAGE_DESC=	Install Sage
SAGE_RUN_DEPENDS=	sage:math/sage

SCILAB_DESC=	Install Scilab
SCILAB_RUN_DEPENDS=	scilab:math/scilab

# Disable python2 binding (should probably be an option PYTHON2, PYTHON3)
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_PythonLibs

post-patch:
	${REINPLACE_CMD} -e '/FIND_PROGRAM(_GFORTRAN_EXECUTABLE/s,gfortran,${FC},' \
		${WRKSRC}/cmake/FindR.cmake
	${REINPLACE_CMD} -e '/find_library(PYTHONLIBS3_LIBRARY/s,python3.5m,python3.5m python3.6m,' \
			 -e '/pkg_check_modules/s,python3,python-${PYTHON_VER},' \
		${WRKSRC}/cmake/FindPythonLibs3.cmake

.include <bsd.port.mk>
