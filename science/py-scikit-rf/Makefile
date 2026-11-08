PORTNAME=	scikit-rf
PORTVERSION=	2.1.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	scikit_rf-${PORTVERSION}

MAINTAINER=	doconnor@gsoft.com.au
COMMENT=	RF and Microwave Engineering Scikit in Python
WWW=		https://scikit-rf.readthedocs.io/en/latest/ \
		https://github.com/scikit-rf/scikit-rf

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.21:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.7:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.5:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.0:math/py-networkx@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
