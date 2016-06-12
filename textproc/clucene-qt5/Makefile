# $FreeBSD$

PORTNAME=	clucene
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	textproc
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt bindings for the CLucene full-text search library

DEPRECATED=	This port will be merged with qt5-help in Qt 5.7 ports.
EXPIRATION_DATE=	2016-08-11

USE_QT5=	core buildtools_build
QT_DIST=	tools
USES=		qmake
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/assistant/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/src/assistant/${PORTNAME}

.include <bsd.port.mk>
