PORTNAME=	kiconthemes
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-themes kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Icon GUI utilities

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake gettext-tools gl kde:6 qt:6 tar:xz
USE_GL=		opengl
USE_KDE=	archive breeze-icons colorscheme config i18n widgetsaddons \
		ecm:build
USE_QT=		base declarative svg \
		tools:build

.include <bsd.port.mk>
