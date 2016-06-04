# $FreeBSD$

PORTNAME= 	enginio
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	net
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Enginio module

DEPRECATED=	Deprecated by upstream from Qt 5.6 on, do not use for development
EXPIRATION_DATE=	2016-08-04

USE_QT5=	core network qml buildtools_build
QT_DIST=	${PORTNAME}
USES=		qmake

USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
