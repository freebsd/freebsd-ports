# Created by: tcberner
# $FreeBSD$

PORTNAME=	kirigami2
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QtQuick based components set

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	ecm kdeclarative
USE_QT=		core dbus declarative gui linguisttools network \
		quickcontrols2 svg testlib widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
