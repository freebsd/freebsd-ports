# $FreeBSD$

PORTNAME=	GPyOpt
DISTVERSION=	1.2.5
PORTREVISION=	2
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bayesian optimization toolbox based on GPy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.16:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}GPy>=1.8>0:science/py-GPy@${PY_FLAVOR}

USES=		python:-3.6
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
