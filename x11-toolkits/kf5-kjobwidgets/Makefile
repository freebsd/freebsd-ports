PORTNAME=	kjobwidgets
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 widgets for tracking KJob instance

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	coreaddons widgetsaddons \
		ecm:build
USE_QT=		core dbus gui linguisttools widgets x11extras \
		buildtools:build qmake:build

.include <bsd.port.mk>
