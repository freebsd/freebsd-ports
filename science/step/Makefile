# $FreeBSD$

PORTNAME=	step
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	science kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE interactive physics simulator

LIB_DEPENDS=	libcln.so:math/cln \
		libgsl.so:math/gsl \
		libqalculate.so:math/libqalculate

USES=		cmake:outsource eigen:3 gettext kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	attica auth bookmarks codecs completion config configwidgets \
		coreaddons crash doctools ecm emoticons guiaddons i18n \
		iconthemes init itemmodels itemviews jobwidgets js \
		kdelibs4support khtml kio newstuff notifications parts \
		plotting service solid sonnet textwidgets unitconversion \
		widgetsaddons windowsystem xmlgui
USE_QT=		core dbus gui network opengl printsupport qml quick svg \
		widgets xml \
		buildtools_build qmake_build

pre-configure:
# Avoid building translations, should the user pass
# CURRENT_LANG to CMake.
	${REINPLACE_CMD} -e '/set(STEP_BUILD_TRANSLATIONS 1)/ d' \
		${WRKSRC}/${PORTNAME}/data/CMakeLists.txt

.include <bsd.port.mk>
