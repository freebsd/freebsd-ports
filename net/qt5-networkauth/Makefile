# $FreeBSD$

PORTNAME=	networkauth
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	net ipv6
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt network auth module

USES=		compiler:c++11-lang qmake:no_env qt-dist:5
USE_QT=		core network \
		buildtools_build
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
