PORTNAME=	step
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	science education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE interactive physics simulator
WWW=		https://edu.kde.org/step

LIB_DEPENDS=	libcln.so:math/cln \
		libgsl.so:math/gsl \
		libqalculate.so:math/libqalculate

USES=		cmake compiler:c++11-lang desktop-file-utils eigen:3 gettext \
		kde:6 pkgconfig python qt:6 shared-mime-info shebangfix tar:xz \
		xorg
USE_KDE=	attica auth bookmarks codecs completion config configwidgets \
		coreaddons crash doctools guiaddons i18n iconthemes itemmodels \
		itemviews jobwidgets kio newstuff notifications parts plotting \
		service solid sonnet textwidgets unitconversion widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

SHEBANG_FILES=	step/data/extractxml

OPTIONS_DEFINE=	DOCS

pre-configure:
# Avoid building translations, should the user pass
# CURRENT_LANG to CMake.
	${REINPLACE_CMD} -e '/set(STEP_BUILD_TRANSLATIONS 1)/ d' \
		${WRKSRC}/${PORTNAME}/data/CMakeLists.txt

.include <bsd.port.mk>
