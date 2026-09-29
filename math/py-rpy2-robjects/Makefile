PORTNAME=	rpy2-robjects
PORTVERSION=	3.6.5
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	rpy2_robjects-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to the R language (embedded R)
WWW=		https://rpy2.github.io/ \
		https://github.com/rpy2/rpy2/tree/master/rpy2-robjects \
		https://github.com/rpy2/rpy2

LICENSE=	GPLv2+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rpy2-rinterface>=3.6.0:math/py-rpy2-rinterface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=0:devel/py-tzlocal@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	NUMPY PANDAS
OPTIONS_DEFAULT=NUMPY PANDAS
NUMPY__DESC=	Numpy support
PANDAS_DESC=	Pandas support

NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.26,1:math/py-numpy@${PY_FLAVOR}
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.26,1:math/py-numpy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pandas>=1.3.5,1<3.0,1:math/py-pandas@${PY_FLAVOR}

.include <bsd.port.mk>
