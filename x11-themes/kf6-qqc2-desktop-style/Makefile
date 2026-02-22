PORTNAME=	qqc2-desktop-style
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-themes kde kde-frameworks
PATCH_SITES=	https://invent.kde.org/frameworks/qqc2-desktop-style/-/commit/
PATCHFILES=	6d79bb7309352c4f77980ed1c68c984c074745f1.patch:-p1

COMMENT=	Style for Qt Quick Controls 2
MAINTAINER=	kde@FreeBSD.org

USES=		cmake gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	colorscheme config iconthemes kirigami2 \
		ecm:build \
		sonnet:run
USE_QT=		base declarative

.include <bsd.port.mk>
