PORTNAME=	kholidays
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library for calendar holidays

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	ecm emoticons init itemmodels itemviews
USE_QT=		core declarative gui network buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
