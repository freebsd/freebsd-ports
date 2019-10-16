# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	kaa-metadata
PORTVERSION=	0.7.7
PORTREVISION=	18
CATEGORIES=	multimedia python
MASTER_SITES=	SF/freevo/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fbsd@opal.com
COMMENT=	Kaa Media Repository - media file metadata parser

LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread \
		libexiv2.so:graphics/exiv2
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}kaa-base>0:multimedia/py-kaa-base@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

.include <bsd.port.mk>
