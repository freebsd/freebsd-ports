# New ports collection makefile for:    Distutils
# Version required:     0.1.3
# Date created:         23 March 2000
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Distutils-0.1.3
PKGNAME=	py-distutils-0.1.3
CATEGORIES=	misc python
MASTER_SITES=	http://www.python.org/sigs/distutils-sig/

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

do-build:
	@(cd ${WRKSRC}; python setup.py build)

do-install:
	@(cd ${WRKSRC}; python setup.py install)

.include <bsd.port.mk>
