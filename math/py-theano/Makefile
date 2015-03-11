# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	theano
PORTVERSION=	0.6.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
MASTER_SITE_SUBDIR=source/T/Theano
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Theano-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Optimizing compiler for evaluating math expressions on CPUs and GPUs

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.8.0:${PORTSDIR}/science/py-scipy

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
