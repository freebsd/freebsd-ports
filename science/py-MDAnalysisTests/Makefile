PORTNAME=	MDAnalysisTests
DISTVERSION=	2.11.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Test code and the trajectory data for test cases of MDAnalysis
WWW=		https://www.mdanalysis.org

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}MDAnalysis>0:science/py-MDAnalysis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest
NO_ARCH=	yes

# test_encore.py crashes with "Too many args to microtask" in libomp (KMeans)
# test_inferring requires rdkit.Chem.rdDetermineBonds which the rdkit port lacks
# test_thread_limit_apply requires threadpoolctl which is disabled in py-MDAnalysis
TEST_ENV=	${MAKE_ENV} MPLBACKEND=Agg
TEST_ARGS=	--disable-plugin-autoload -p hypothesis.extra.pytestplugin \
		--ignore MDAnalysisTests/analysis/test_encore.py \
		--deselect MDAnalysisTests/converters/test_rdkit.py::TestRDKitInferrer::test_inferring \
		--deselect MDAnalysisTests/transformations/test_base.py::test_thread_limit_apply

WRKSRC=		${WRKDIR}/mdanalysistests-${DISTVERSION}

# tests as of 2.11.0: 21465 passed, 424 skipped, 37 deselected, 12 xfailed, 273839 warnings in 3953.72s (1:05:53)

.include <bsd.port.mk>
