PORTNAME=	scikit-datasets
DISTVERSION=	0.2.5
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	scikit_datasets-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scikit-learn-compatible datasets
WWW=		https://daviddiazvico.github.io/scikit-datasets/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rdata>0:devel/py-rdata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent

NO_ARCH=	yes

.include <bsd.port.mk>
