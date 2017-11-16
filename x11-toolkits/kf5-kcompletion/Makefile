# $FreeBSD$

PORTNAME=	kcompletion
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 text completion helpers and widgets

USES=		cmake:outsource compiler:c++11-lib kde:5 tar:xz
USE_KDE=	config ecm widgetsaddons
USE_QT5=	buildtools_build core gui linguisttools qmake_build \
		widgets xml

.include <bsd.port.mk>
