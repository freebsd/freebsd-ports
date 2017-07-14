# $FreeBSD$

PORTNAME=	websockets-qml
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	www
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt implementation of WebSocket protocol (QML bindings)

USE_QT5=	buildtools_build core network qml quick websockets
QT_DIST=	websockets
USES=		qmake
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
