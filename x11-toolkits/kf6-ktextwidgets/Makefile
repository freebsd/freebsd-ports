PORTNAME=	ktextwidgets
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Text editing widgets

USES=		cmake gettext-tools gl kde:6 qt:6 tar:xz
USE_GL=		opengl
USE_KDE=	completion config i18n sonnet widgetsaddons \
		ecm:build
USE_QT=		base multimedia speech \
		declarative:build tools:build

.include <bsd.port.mk>
