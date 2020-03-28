# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nevergrad
PORTVERSION=	0.4.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python toolbox for performing gradient-free optimization

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bayesian-optimization>=1.1.0:math/py-bayesian-optimization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cma>=2.6.0:math/py-cma@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hiplot>=0:graphics/py-hiplot@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.23.4:math/py-pandas@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	BENCHMARK
OPTIONS_DEFAULT=BENCHMARK
BENCHMARK_DESC=	Run benchmark functions

BENCHMARK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gym>=0.12.1:math/py-gym@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}matplotlib>=2.2.3:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>=2.21.0:www/py-requests@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xlrd>=1.2.0:textproc/py-xlrd@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xlwt>=1.3.0:textproc/py-xlwt@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3700
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.6.6:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
