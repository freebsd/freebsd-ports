PORTNAME=	mqtt
DISTVERSIONPREFIX=	v
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	net
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt module implementing the MQTT protocol

USES=		cmake compiler:c++17-lang qt-dist:6
USE_GITHUB=	yes
GH_TUPLE=	qt:qtmqtt:${DISTVERSIONFULL}
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}
USE_QT=		base

.include <bsd.port.mk>
