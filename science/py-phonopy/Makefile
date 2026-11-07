PORTNAME=	phonopy
DISTVERSION=	4.10.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for phonon calculations at harmonic and quasi-harmonic levels
WWW=		https://phonopy.github.io/phonopy/ \
		https://github.com/phonopy/phonopy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}nanobind>0:devel/py-nanobind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.17:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>=3.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.2.2:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.17:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglib>=2.5:science/py-spglib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}symfc>=1.7:science/py-symfc@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}phonors>=0.6.0:science/py-phonors@${PY_FLAVOR} # undeclared dependency of phonopy, but required for run and tests

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload
TEST_WRKSRC=	${WRKSRC}/test

post-install:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/phonopy -maxdepth 1 -name '_phonopy*.so' -exec ${STRIP_CMD} {} +
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/phonopy -maxdepth 1 -name '_recgrid*.so' -exec ${STRIP_CMD} {} +

# tests as of 4.10.0: 48 failed, 1884 passed, 42 skipped, 239 warnings in 545.49s (0:09:05), see https://github.com/phonopy/phonopy/issues/1092

.include <bsd.port.mk>
