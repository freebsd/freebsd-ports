# $FreeBSD$

PORTNAME=	webview
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	www
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt component for displaying web content

USES=		compiler:c++11-lang qmake:norecursive qt-dist:5
USE_QT=		core declarative gui network webengine \
		buildtools_build
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
