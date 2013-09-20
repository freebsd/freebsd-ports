# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	funkload
PORTVERSION=	1.14.0
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
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

NO_STAGE=	yes
.include <bsd.port.mk>
