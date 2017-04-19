# Created by: tcberner
# $FreeBSD$

PORTNAME=	kguiaddons
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 addons to QtGui

USES=		cmake:outsource compiler:c++11-lib kde:5 pkgconfig tar:xz
USE_KDE=	ecm
USE_QT5=	buildtools_build core gui qmake_build testlib widgets x11extras
USE_XORG=	ice sm x11 xcb xext

.include <bsd.port.mk>
