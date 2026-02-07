PORTNAME=	kcalendarcore
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	net kde kde-frameworks

COMMENT=	Provides access to and handling of calendar data
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libical.so:devel/libical

USES=		cmake gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	ecm:build
USE_QT=		base declarative tools:build

.include <bsd.port.mk>
