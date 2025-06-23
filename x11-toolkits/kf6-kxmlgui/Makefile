PORTNAME=	kxmlgui
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

COMMENT=	Framework for managing menu and toolbar actions
MAINTAINER=	kde@FreeBSD.org

USES=		cmake gettext gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	colorscheme config configwidgets coreaddons globalaccel \
		guiaddons i18n iconthemes itemviews widgetsaddons \
		ecm:build
USE_QT=		base

CMAKE_OFF=	BUILD_PYTHON_BINDINGS

.include <bsd.port.mk>
