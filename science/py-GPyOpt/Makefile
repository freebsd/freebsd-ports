PORTNAME=	GPyOpt # the upstream repository was archived but this packages seems to be ok and is useful
DISTVERSION=	1.2.6
PORTREVISION=	2
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bayesian optimization toolbox based on GPy
WWW=		https://sheffieldml.github.io/GPyOpt/ \
		https://github.com/SheffieldML/GPyOpt

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.16:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}GPy>=1.8:science/py-GPy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
