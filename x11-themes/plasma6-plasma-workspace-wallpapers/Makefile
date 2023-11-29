PORTNAME=	plasma-workspace-wallpapers
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-themes kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Wallpapers for Plasma Workspaces

USES=		cmake kde:6 qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		base declarative
CMAKE_ARGS=	-DQT_MAJOR_VERSION=6

.include <bsd.port.mk>
