# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	funkload
PORTVERSION=	1.17.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Functional and load web tester

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>0:${PORTSDIR}/textproc/py-docutils \
		${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot \
		${PYTHON_PKGNAMEPREFIX}webunit>=1.3.8:${PORTSDIR}/www/py-webunit \
		tcpwatch.py:${PORTSDIR}/net/tcpwatch

USES=		python:2
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
