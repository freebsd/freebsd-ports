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
MASTER_SITES=	http://www.biopython.org/Download/
MASTER_SITE_SUBDIR=	wjv
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	biopython-${BIOPYTHON_VERSION}

MAINTAINER=	wjv@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/TextTools/__init__.py:${PORTSDIR}/lang/py-mx-base

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/Martel
BIOPYTHON_VERSION=	1.00a4
PYTHON_SETUP=	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@ cd ${WRKSRC} && ${PYTHON_SETUP} build

pre-install:
	@ ${SH} ${PKGREQ} INSTALL

do-install:
	@ cd ${WRKSRC} && ${PYTHON_SETUP} install -c -O1 --prefix=${PREFIX}

.include <bsd.port.mk>
