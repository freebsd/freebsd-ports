# New ports collection makefile for:	py-csv
# Date created:		27 February 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	csv
PORTVERSION=	0.4
CATEGORIES=	textproc python
MASTER_SITES=	http://object-craft.com.au/projects/csv/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wjv@FreeBSD.org

USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/csv

do-build:
	@ cd ${WRKSRC} && ${PYTHON_CMD} setup.py build

do-install:
	@ cd ${WRKSRC} && ${PYTHON_CMD} setup.py install \
	  --prefix=${PREFIX}

.include <bsd.port.mk>
