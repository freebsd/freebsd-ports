# New ports collection makefile for:   pyweblib
# Date created:        22 March 2002
# Whom:                Oddbjorn Steffensen <oddbjorn@tricknology.org>
#
# $FreeBSD$
#

PORTNAME=	pyweblib
PORTVERSION=	1.1.0
CATEGORIES=	www
MASTER_SITES=	http://www.stroeder.com/pylib/PyWebLib/download/ \
		http://www.tricknology.org/ports/

MAINTAINER=	oddbjorn@tricknology.org

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S=-src==}

do-build:
	cd ${WRKSRC} && python setup.py build

do-install:
	cd ${WRKSRC} && python setup.py install

.include <bsd.port.mk>
