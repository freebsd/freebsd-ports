PORTNAME=	step
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	science education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE interactive physics simulator
WWW=		https://edu.kde.org/step

LIB_DEPENDS=	libgsl.so:math/gsl \
		libqalculate.so:math/libqalculate

USES=		cmake compiler:c++11-lang desktop-file-utils eigen:3 gettext-tools gl \
		kde:6 pkgconfig python qt:6 shared-mime-info shebangfix tar:xz \
		xorg
USE_GL=		opengl
USE_KDE=	config crash i18n iconthemes kio newstuff plotting \
		textwidgets xmlgui \
		ecm:build
USE_QT=		base svg \
		declarative:build tools:build
USE_XORG=	x11

SHEBANG_FILES=	step/data/extractxml

OPTIONS_DEFINE=	DOCS

pre-configure:
# Avoid building translations, should the user pass
# CURRENT_LANG to CMake.
	${REINPLACE_CMD} -e '/set(STEP_BUILD_TRANSLATIONS 1)/ d' \
		${WRKSRC}/${PORTNAME}/data/CMakeLists.txt

.include <bsd.port.mk>
