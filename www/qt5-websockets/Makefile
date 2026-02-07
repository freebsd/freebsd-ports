PORTNAME=	websockets
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	www
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt implementation of WebSocket protocol

USES=		compiler:c++11-lang perl5 qmake:norecursive qt-dist:5,websockets
USE_PERL5=	extract
USE_QT=		buildtools:build core network
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
