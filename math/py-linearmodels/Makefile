PORTNAME=	linearmodels
PORTVERSION=	4.27
CATEGORIES=	math python # statistics
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Linear Panel, Instrumental Variable, Asset Pricing and other models
WWW=		https://bashtage.github.io/linearmodels/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}formulaic>=0.3.2:math/py-formulaic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy_extensions>=0.4:devel/py-mypy_extensions@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.24:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}property-cached>=1.6.3:devel/py-property-cached@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyhdfe>=0.1:math/py-pyhdfe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.2:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsmodels>=0.11:math/py-statsmodels@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=6.4.2,<7.0.0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.7+ shebangfix
USE_PYTHON=	autoplist cython distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/linearmodels/panel/_utility${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
