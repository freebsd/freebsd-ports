# New ports collection makefile for:	py-csv
# Date created:		27 February 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	csv
PORTVERSION=	0.5
CATEGORIES=	textproc python
MASTER_SITES=	http://object-craft.com.au/projects/csv/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wjv@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PYTHON_SETUP=	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@ cd ${WRKSRC} && ${PYTHON_SETUP} build

do-install:
	@ cd ${WRKSRC} && ${PYTHON_SETUP} install --prefix=${PREFIX}

.include <bsd.port.mk>
