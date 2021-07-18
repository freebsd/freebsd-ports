PORTNAME=	kemoticons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-themes kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library to convert emoticons

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	archive config coreaddons service \
		ecm_build
USE_QT=		core dbus gui widgets xml \
		buildtools_build qmake_build 

.include <bsd.port.mk>
