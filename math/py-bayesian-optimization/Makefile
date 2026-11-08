PORTNAME=	bayesian-optimization
PORTVERSION=	3.3.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	bayesian_optimization-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bayesian Optimization package
WWW=		https://bayesian-optimization.github.io/BayesianOptimization/ \
		https://github.com/bayesian-optimization/BayesianOptimization

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.12:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.4.6:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.1.3,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.0.0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.14.1,1:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	SOURCE_DATE_EPOCH=315532800 # 1980-01-01 00:00:00 UTC
NO_ARCH=	yes

.include <bsd.port.mk>
