# New ports collection makefile for:	py-csv
# Date created:		27 February 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	csv
PORTVERSION=	0.2
CATEGORIES=	textproc python
MASTER_SITES=	http://object-craft.com.au/projects/csv/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	johann@egenetics.com

USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/csv

do-configure:
	@ (cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE} -f \
	  Makefile.pre.in boot)

.include <bsd.port.mk>
