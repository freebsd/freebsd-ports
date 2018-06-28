# $FreeBSD$

PORTNAME=	xmlpatterns
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	textproc
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt support for XPath, XQuery, XSLT and XML Schema

BROKEN_powerpc64=	Does not build

USE_QT=		core network buildtools_build
USES=		qmake:norecursive qt-dist:5,xmlpatterns
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
