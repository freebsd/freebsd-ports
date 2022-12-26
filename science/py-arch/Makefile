PORTNAME=	arch
DISTVERSION=	5.3.1
CATEGORIES=	science python # economics
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Autoregressive Conditional Heteroskedasticity (ARCH) models
WWW=		https://github.com/RomelTorres/alpha_vantage

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}property-cached>=1.6.4:devel/py-property-cached@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.3:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsmodels>=0.11:math/py-statsmodels@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.8+
USE_PYTHON=	distutils cython autoplist pytest

TEST_WRKSRC=	${WRKSRC}/arch/tests

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/arch/bootstrap/_samplers${PYTHON_EXT_SUFFIX}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/arch/univariate/recursions${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
