# $FreeBSD$

PORTNAME=	kguiaddons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 addons to QtGui

USES=		cmake compiler:c++11-lib kde:5 pkgconfig qt:5 tar:xz xorg
USE_KDE=	ecm
USE_QT=		core gui qmake_build testlib wayland widgets x11extras \
		buildtools_build
USE_XORG=	ice sm x11 xcb xext

.include <bsd.port.mk>
