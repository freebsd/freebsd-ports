PORTNAME=	pynndescent
DISTVERSION=	0.5.13
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python nearest neighbor descent for approximate nearest neighbors
WWW=		https://github.com/lmcinnes/pynndescent

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}joblib>0.11:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}llvmlite>=0.30:devel/py-llvmlite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>=0.51.2:devel/py-numba@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.18:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # 1 test fails, see https://github.com/lmcinnes/pynndescent/issues/239

NO_ARCH=	yes

.include <bsd.port.mk>
