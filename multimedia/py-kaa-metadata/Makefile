# New ports collection makefile for:	py-kaa-metadata
# Date created:		2009 January 10
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	kaa-metadata
PORTVERSION=	0.7.6
CATEGORIES=	multimedia python
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	freevo
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fbsd@opal.com
COMMENT=	Kaa Media Repository - media file metadata parser

LIB_DEPENDS=	dvdread.4:${PORTSDIR}/multimedia/libdvdread
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/kaa/__init__.py:${PORTSDIR}/multimedia/py-kaa-base
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"	# ${CFLAGS} is already there

.include <bsd.port.mk>
