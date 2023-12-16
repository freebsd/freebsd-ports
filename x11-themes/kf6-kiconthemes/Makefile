PORTNAME=	kiconthemes
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-themes kde kde-frameworks

COMMENT=	Icon GUI utilities
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake gettext gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	archive colorscheme config configwidgets i18n widgetsaddons \
		ecm:build
USE_QT=		base declarative svg

.include <bsd.port.mk>
