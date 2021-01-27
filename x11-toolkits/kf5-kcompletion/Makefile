# $FreeBSD$

PORTNAME=	kcompletion
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits kde kde-frameworks

PATCH_SITES=	https://invent.kde.org/frameworks/kcompletion/commit/
PATCHFILES=	7acda936f06193e9fc85ae5cf9ccc8d65971f657.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 text completion helpers and widgets

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	config ecm widgetsaddons
USE_QT=		buildtools_build core gui linguisttools qmake_build \
		widgets xml

.include <bsd.port.mk>
