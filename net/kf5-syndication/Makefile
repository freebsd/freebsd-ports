# $FreeBSD$

PORTNAME=	syndication
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTEPOCH=	1
CATEGORIES=	net kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE RSS feed handling library

LICENSE=	LGPL21

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	codecs config coreaddons ecm kio service
USE_QT=		core gui xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
