PORTNAME=	syndication
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTEPOCH=	1
CATEGORIES=	net kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE RSS feed handling library

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	codecs service \
		ecm_build
USE_QT=		core xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
