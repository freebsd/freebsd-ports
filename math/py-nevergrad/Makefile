PORTNAME=	nevergrad
PORTVERSION=	0.4.3
DISTVERSIONSUFFIX=	.post2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python toolbox for performing gradient-free optimization

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bayesian-optimization>=1.2.0:math/py-bayesian-optimization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cma>=2.6.0:math/py-cma@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.15.0,1:math/py-numpy@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	BENCHMARK
OPTIONS_DEFAULT=BENCHMARK
BENCHMARK_DESC=	Run benchmark functions

BENCHMARK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gym>=0.12.1:math/py-gym@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}hiplot>=0:graphics/py-hiplot@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}iohexperimenter>=0.2.8:math/py-iohexperimenter@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}matplotlib>=2.2.3:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mixsimulator>=0.2.9.5:math/py-mixsimulator@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pandas>=0.23.4,1:math/py-pandas@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}Pyomo>=5.7:math/py-Pyomo@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyproj>=2.6.1:graphics/py-pyproj@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>=2.21.0:www/py-requests@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tqdm>=0:misc/py-tqdm@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xlrd>=1.2.0:textproc/py-xlrd@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xlwt>=1.3.0:textproc/py-xlwt@${PY_FLAVOR}

.include <bsd.port.mk>
