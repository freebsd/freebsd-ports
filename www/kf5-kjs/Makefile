PORTNAME=	kjs
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	www kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library providing an ECMAScript interpreter
WWW=		https://api.kde.org/frameworks-api/frameworks5-apidocs/kjs/html/index.html

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		cmake compiler:c++11-lib kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	doctools_build ecm_build
USE_QT=		core \
		buildtools_build qmake_build

.include <bsd.port.mk>
