PORTNAME=	scikit-quant
DISTVERSION=	0.8.2
CATEGORIES=	misc python # quantum-computing
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Aggregator package for interoperability for quantum computing software
WWW=		http://scikit-quant.org

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Py-BOBYQA>=1.2:math/py-Py-BOBYQA@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}SQCommon>0:misc/py-SQCommon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}SQImFil>0:misc/py-SQImFil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}SQNomad>0:math/py-SQNomad@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}SQSnobFit>0:misc/py-SQSnobFit@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # several tests fail, see https://github.com/scikit-quant/scikit-quant/issues/25

NO_ARCH=	yes

.include <bsd.port.mk>
