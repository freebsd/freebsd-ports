PORTNAME=	mplhep
DISTVERSION=	0.3.59
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Matplotlib styles for HEP
WWW=		https://mplhep.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cycler>0:devel/py-cycler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.4:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mplhep-data>=0.0.4:science/py-mplhep-data@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uhi>=0.2.0:misc/py-uhi@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boost-histogram>0:misc/py-boost-histogram@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hist>0:misc/py-hist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mpl>0:devel/py-pytest-mpl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uproot>0:devel/py-uproot@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

# tests as for 0.3.59: 4 failed, 74 passed, 35 skipped, 15 warnings in 22.65s (4 failures are due to missing dependency uproot4)

.include <bsd.port.mk>
