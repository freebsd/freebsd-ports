PORTNAME=	kxmlgui
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Framework for managing menu and toolbar actions

USES=		cmake gettext-tools gl kde:6 qt:6 tar:xz
USE_GL=		opengl
USE_KDE=	config configwidgets coreaddons globalaccel \
		guiaddons i18n iconthemes itemviews widgetsaddons \
		ecm:build
USE_QT=		base \
		declarative:build tools:build

CMAKE_OFF=	BUILD_PYTHON_BINDINGS

.include <bsd.port.mk>
