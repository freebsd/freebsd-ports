# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	theano
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP/source/T/Theano
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Theano-${DISTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Optimizing compiler for evaluating math expressions on CPUs and GPUs

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.8.0:science/py-scipy

USES=		compiler:openmp python
USE_PYTHON=	concurrent distutils autoplist

SUB_FILES=	pkg-message
SUB_LIST=	CXX=${CXX}

.include <bsd.port.mk>
