# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pybloom
PORTVERSION=	2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Probabilistic data structure

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bitarray>0:devel/py-bitarray@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

USE_GITHUB=     yes
GH_ACCOUNT=     jaybaird
GH_PROJECT=	python-bloomfilter

.include <bsd.port.mk>
