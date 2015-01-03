# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	funkload
PORTVERSION=	1.16.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	FunkLoad is a functional and load web tester

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/docutils/__init__.py:${PORTSDIR}/textproc/py-docutils \
		${LOCALBASE}/bin/gnuplot:${PORTSDIR}/math/gnuplot \
		${PYTHON_PKGNAMEPREFIX}webunit>=1.3.8:${PORTSDIR}/www/py-webunit \
		${PYXML} \
		tcpwatch.py:${PORTSDIR}/net/tcpwatch

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
