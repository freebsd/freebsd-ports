# $FreeBSD$

PORTNAME=	step
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	science kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE interactive physics simulator

LIB_DEPENDS=	libcln.so:math/cln \
		libgsl.so:math/gsl \
		libqalculate.so:math/libqalculate

USES=		cmake compiler:c++11-lang eigen:3 gettext kde:5 \
		pkgconfig python:3.5+ qt:5 shebangfix tar:xz
USE_KDE=	attica auth bookmarks codecs completion config configwidgets \
		coreaddons crash doctools ecm emoticons guiaddons i18n \
		iconthemes init itemmodels itemviews jobwidgets js \
		kdelibs4support khtml kio newstuff notifications parts \
		plotting service solid sonnet textwidgets unitconversion \
		widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus declarative gui network opengl printsupport svg \
		widgets xml \
		buildtools_build qmake_build
CXXFLAGS_powerpc64=	-Wno-error=return-type
CXXFLAGS_powerpc=	-Wno-error=return-type
CXXFLAGS_powerpcspe=	-Wno-error=return-type
CXXFLAGS_sparc64=	-Wno-error=return-type

SHEBANG_FILES=	step/data/extractxml

OPTIONS_DEFINE=	DOCS

pre-configure:
# Avoid building translations, should the user pass
# CURRENT_LANG to CMake.
	${REINPLACE_CMD} -e '/set(STEP_BUILD_TRANSLATIONS 1)/ d' \
		${WRKSRC}/${PORTNAME}/data/CMakeLists.txt

.include <bsd.port.mk>
