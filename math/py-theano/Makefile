# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	theano
DISTVERSION=	0.7.0rc2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
MASTER_SITE_SUBDIR=source/T/Theano
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Theano-${DISTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Optimizing compiler for evaluating math expressions on CPUs and GPUs

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.8.0:${PORTSDIR}/science/py-scipy

USES=		python
USE_PYTHON=	concurrent distutils autoplist

.include <bsd.port.mk>
