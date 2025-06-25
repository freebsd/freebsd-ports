PORTNAME=	qqc2-desktop-style
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-themes kde kde-frameworks

COMMENT=	Style for Qt Quick Controls 2
MAINTAINER=	kde@FreeBSD.org

USES=		cmake gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	colorscheme config iconthemes kirigami2 \
		ecm:build \
		sonnet:run
USE_QT=		base declarative

.include <bsd.port.mk>
