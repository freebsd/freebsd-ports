# New ports collection makefile for:	py-martel
# Date created:		19 October 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	martel
PORTVERSION=	0.8
PORTEPOCH=	1
CATEGORIES=	textproc biology python
MASTER_SITES=	# no longer available separately from biopython
MASTER_SITE_SUBDIR=	wjv
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	biopython-${BIOPYTHON_VERSION}

MAINTAINER=	wjv@FreeBSD.org
COMMENT=	A parser generator for regular languages, written in Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/TextTools/__init__.py:${PORTSDIR}/lang/py-mx-base

DEPRECATED=	"not up-to-date and is only a subset of biology/py-biopython"
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/Martel
BIOPYTHON_VERSION=	1.00a4

pre-install:
	@ ${SH} ${PKGREQ} INSTALL

.include <bsd.port.mk>
