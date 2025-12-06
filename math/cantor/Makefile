PORTNAME=	cantor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	math kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mathematical software frontend by KDE
WWW=		https://edu.kde.org/cantor

LIB_DEPENDS=	libAnalitza.so:math/analitza \
		libcln.so:math/cln \
		libqalculate.so:math/libqalculate \
		libspectre.so:print/libspectre \
		libpoppler.so:graphics/poppler \
		libpoppler-qt6.so:graphics/poppler-qt6
BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:6 \
		pkgconfig python qt:6 shared-mime-info tar:xz xorg
USE_KDE=	archive attica auth bookmarks codecs completion config \
		configwidgets coreaddons crash i18n iconthemes itemmodels \
		itemviews jobwidgets kio newstuff parts pty service solid \
		sonnet syntaxhighlighting texteditor textwidgets widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		base svg webchannel webengine \
		tools:build
USE_XORG=	x11
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	LUAJIT MAXIMA OCTAVE R SCILAB DOCS
OPTIONS_SUB=	yes # R LUAJIT

LUAJIT_DESC=	Build LuaJIT backend and install LuaJIT
LUAJIT_USES=	luajit
LUAJIT_CMAKE_OFF=	-DWITH_LuaJIT:BOOL=FALSE

MAXIMA_DESC=	Install Maxima
MAXIMA_RUN_DEPENDS=	maxima:math/maxima

OCTAVE_DESC=	Install Octave
OCTAVE_RUN_DEPENDS=	octave:math/octave

R_DESC=		Build R backend and install R (broken)
R_LIB_DEPENDS=	libR.so:math/R
# Required to set CFLAGS for -lgfortran.
R_USES=		fortran
R_CMAKE_OFF=	-DWITH_R:BOOL=FALSE
R_BROKEN=	R backend fails with: /usr/include/c++/v1/__locale:1130:9: error: expected ';' at end of declaration list

SCILAB_DESC=	Install Scilab
SCILAB_RUN_DEPENDS=	scilab:math/scilab

post-patch:
	${REINPLACE_CMD} -e '/FIND_PROGRAM(_GFORTRAN_EXECUTABLE/s,gfortran,${FC},' \
		${WRKSRC}/cmake/FindR.cmake

.include <bsd.port.mk>
