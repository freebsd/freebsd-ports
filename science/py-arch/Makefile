PORTNAME=	arch
DISTVERSION=	8.0.0
PORTREVISION=	1
CATEGORIES=	science finance python # economics
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Autoregressive Conditional Heteroskedasticity (ARCH) models
WWW=		https://github.com/bashtage/arch

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meson-python>0:devel/meson-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.4.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}property-cached>=1.6.4:devel/py-property-cached@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.8:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsmodels>=0.13.0:math/py-statsmodels@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest # tests fail to run, see https://github.com/bashtage/arch/issues/668

TEST_WRKSRC=	${WRKSRC}/arch/tests
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/arch/bootstrap/_samplers${PYTHON_TAG}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/arch/univariate/recursions${PYTHON_TAG}.so

.include <bsd.port.mk>
