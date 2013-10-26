# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	kaa-metadata
PORTVERSION=	0.7.7
PORTREVISION=	6
CATEGORIES=	multimedia python
MASTER_SITES=	SF/freevo/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fbsd@opal.com
COMMENT=	Kaa Media Repository - media file metadata parser

LIB_DEPENDS=	dvdread.4:${PORTSDIR}/multimedia/libdvdread
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}kaa-base>0:${PORTSDIR}/multimedia/py-kaa-base \
		${PYTHON_PKGNAMEPREFIX}exiv2>0:${PORTSDIR}/graphics/py-exiv2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes

CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

NO_STAGE=	yes
.include <bsd.port.mk>
