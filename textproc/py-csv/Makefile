# New ports collection makefile for:	py-csv
# Date created:		27 February 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	csv
PORTVERSION=	1.0
CATEGORIES=	textproc python
MASTER_SITES=	http://object-craft.com.au/projects/csv/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python module to parse or write comma-separated value (CSV) files

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/csv.so
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 230
IGNORE=		As of Python 2.3, a similar (but not identical) module is included in the base system
.endif

.include <bsd.port.post.mk>
