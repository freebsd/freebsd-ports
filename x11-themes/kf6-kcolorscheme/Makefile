PORTNAME=	kcolorscheme
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-themes kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Classes to read and interact with KColorScheme

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake gettext-tools gl kde:6 qt:6 tar:xz
USE_GL=		opengl
USE_KDE=	config guiaddons i18n \
		ecm:build
USE_QT=		base \
		declarative:build

.include <bsd.port.mk>
