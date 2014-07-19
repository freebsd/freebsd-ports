# $FreeBSD$

PORTNAME=	clucene
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	textproc
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt bindings for the CLucene full-text search library

USE_QT5=	core buildtools_build
QT_DIST=	tools
USES=		qmake
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

WRKSRC_SUBDIR=	src/assistant/${PORTNAME}
PATCH_WRKSRC=	${WRKSRC:H}

.include <bsd.port.mk>
