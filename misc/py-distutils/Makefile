# New ports collection makefile for:    Distutils
# Date created:         23 March 2000
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	distutils
PORTVERSION=	0.9.1
CATEGORIES=	misc python
MASTER_SITES=	http://www.python.org/sigs/distutils-sig/download/
PKGNAMEPREFIX=	py-
DISTNAME=	Distutils-${PORTVERSION}

MAINTAINER=	tg@FreeBSD.org

USE_PYTHON=	yes

do-build:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup.py build)

do-install:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup.py install)

.include <bsd.port.mk>
