PORTNAME=	nibabel
DISTVERSION=	5.5.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Read/write some common neuroimaging file formats
WWW=		https://nipy.org/nibabel/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.27:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20:devel/py-packaging@${PY_FLAVOR}
py311_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}importlib-resources>=5.12:devel/py-importlib-resources@${PY_FLAVOR}
py312_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=7.2:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydicom>=2.3:science/py-pydicom@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=6:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-doctestplus>=1.4:devel/py-pytest-doctestplus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-run-parallel>=0.8.2:devel/py-pytest-run-parallel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.5:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest_httpserver>=1.0.7:devel/py-pytest_httpserver@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PATH=${STAGEDIR}${PREFIX}/bin
# test_a2f_nan2zero_range expects a RuntimeWarning on NaN to int cast, which aarch64 does not emit
TEST_ARGS=	--disable-plugin-autoload -p pytest_httpserver.pytest_plugin \
		--deselect nibabel/tests/test_volumeutils.py::test_a2f_nan2zero_range

post-install:
	@${REINPLACE_CMD} -i '' -e 's|#!python|#!${PYTHON_CMD}|' \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/nibabel/cmdline/diff.py  \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/nibabel/cmdline/ls.py

# tests as of 5.5.0: 5691 passed, 52 skipped, 1 deselected, 42 xfailed, 6 xpassed, 29136 warnings in 68.19s (0:01:08)

.include <bsd.port.mk>
