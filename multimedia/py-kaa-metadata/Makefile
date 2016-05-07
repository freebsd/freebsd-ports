# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	kaa-metadata
PORTVERSION=	0.7.7
PORTREVISION=	12
CATEGORIES=	multimedia python
MASTER_SITES=	SF/freevo/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fbsd@opal.com
COMMENT=	Kaa Media Repository - media file metadata parser

LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}kaa-base>0:multimedia/py-kaa-base \
		${PYTHON_PKGNAMEPREFIX}exiv2>0:graphics/py-exiv2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2
USE_PYTHON=	distutils autoplist

CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

.include <bsd.port.mk>
