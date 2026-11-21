PORTNAME=	kconfigwidgets
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Widgets for configuration dialogs

USES=		cmake gettext-tools gl kde:6 qt:6 tar:xz
USE_GL=		opengl
USE_KDE=	codecs colorscheme config coreaddons guiaddons i18n \
		widgetsaddons \
		ecm:build
USE_QT=		base \
		declarative:build tools:build

.include <bsd.port.mk>
