PORTNAME=	arch
DISTVERSION=	6.3.0
CATEGORIES=	science finance python # economics
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Autoregressive Conditional Heteroskedasticity (ARCH) models
WWW=		https://github.com/bashtage/arch

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.1:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}property-cached>=1.6.4:devel/py-property-cached@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.5:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsmodels>=0.12:math/py-statsmodels@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest # tests fail to run, see https://github.com/bashtage/arch/issues/668

TEST_WRKSRC=	${WRKSRC}/arch/tests
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/arch/bootstrap/_samplers${PYTHON_EXT_SUFFIX}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/arch/univariate/recursions${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
