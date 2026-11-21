PORTNAME=	qqc2-desktop-style
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-themes kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Style for Qt Quick Controls 2

USES=		cmake gl kde:6 qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	colorscheme config iconthemes kirigami2 \
		ecm:build \
		sonnet:run
USE_QT=		base declarative \
		tools:build
USE_XORG=	x11

.include <bsd.port.mk>
