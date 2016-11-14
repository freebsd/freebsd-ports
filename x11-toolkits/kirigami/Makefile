# Created by: tcberner
# $FreeBSD$

PORTNAME=	kirigami
PORTVERSION=	1.1.0
MASTER_SITES=	KDE/stable/${PORTNAME}
# kirigami will likely become a framework. So already put the distfile there.
DIST_SUBDIR=	KDE/frameworks/${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde # kde-framework

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QtQuick based components set

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 tar:xz
USE_KDE=	ecm kdeclarative plasma-framework
USE_QT5=	buildtools_build core gui linguisttools network qmake_build \
		qml quick svg testlib widgets

.include <bsd.port.mk>
