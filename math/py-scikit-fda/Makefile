PORTNAME=	scikit-fda
DISTVERSION=	0.10.1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Functional Data Analysis Python package
WWW=		https://fda.readthedocs.io/en/latest/ \
		https://github.com/GAA-UAM/scikit-fda

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dcor>0:math/py-dcor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fdasrsf>=2.2.0:math/py-fdasrsf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}findiff>0:math/py-findiff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lazy_loader>0:devel/py-lazy_loader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multimethod>=1.5:devel/py-multimethod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rdata>0:devel/py-rdata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-datasets>=0.2.2:math/py-scikit-datasets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0.20:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.6.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent

NO_ARCH=	yes

.include <bsd.port.mk>
