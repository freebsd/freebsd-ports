# New ports collection makefile for:	py-funkload
# Date created:		Mar. 03, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	funkload
PORTVERSION=	1.12.0
CATEGORIES=	www python
MASTER_SITES=	http://funkload.nuxeo.org/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	FunkLoad is a functional and load web tester

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/docutils/__init__.py:${PORTSDIR}/textproc/py-docutils \
		${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot \
		${PYTHON_PKGNAMEPREFIX}webunit>=1.3.8:${PORTSDIR}/www/py-webunit \
		${PYXML} \
		tcpwatch.py:${PORTSDIR}/net/tcpwatch

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
