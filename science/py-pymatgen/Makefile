PORTNAME=	pymatgen
DISTVERSIONPREFIX=	v
DISTVERSION=	2026.5.4
PORTREVISION=	1
CATEGORIES=	science python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Materials Genomics is a robust materials analysis code
WWW=		https://pymatgen.org/ \
		https://github.com/materialsproject/pymatgen

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymatgen-core>=2026.3.9:science/py-pymatgen-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2024.8.30:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}charset-normalizer>=3.4.0:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=3.10:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml.clib>=0.2.12:devel/py-ruamel.yaml.clib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.18.10:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=9.0.0:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>=2024.2:devel/py-tzdata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=2.6.3:net/py-urllib3@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ase>=3.23.0:science/py-ase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=3.11.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}phonopy>=2.33.3:science/py-phonopy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}seekpath>=2.0.1:science/py-seekpath@${PY_FLAVOR} # optional dependencies
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybtex>0:textproc/py-pybtex@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	pep517 cython concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	materialsproject

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		PMG_TEST_FILES_DIR=${WRKSRC}/test-files \
		MPLBACKEND=Agg
TEST_WRKSRC=	${WRKSRC}/tests

post-patch:
	# Remove files owned by py-pymatgen-core (both packages install these from shared namespace)
	@${RM} ${WRKSRC}/src/pymatgen/analysis/chempot_diagram.py \
		${WRKSRC}/src/pymatgen/analysis/phase_diagram.py \
		${WRKSRC}/src/pymatgen/analysis/reaction_calculator.py

# tests as of 2025.2.18: 56 failed, 2912 passed, 149 skipped, 1980 warnings in 11080.55s (3:04:40), see https://github.com/materialsproject/pymatgen/issues/4264
# tests as of 2025.5.28: 56 failed, 3015 passed, 161 skipped, 131 warnings, 7 errors in 5700.13s (1:35:00)
# tests as of 2026.3.23: 0 failed (2 spglib-version-sensitive tests patched), 719 passed, 275 skipped, 7 xfailed, 1 xpassed

.include <bsd.port.mk>
