PORTNAME=	kcompletion
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 text completion helpers and widgets

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	config widgetsaddons \
		ecm:build
USE_QT=		core gui linguisttools widgets xml \
		buildtools:build qmake:build

.include <bsd.port.mk>
