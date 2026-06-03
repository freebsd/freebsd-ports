PORTNAME=	qcengine
DISTVERSION=	0.50.0
CATEGORIES=	science python # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum chemistry program executor and IO standardizer (QCSchema)
WWW=		https://github.com/MolSSI/QCEngine

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8.0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}py-cpuinfo>0:sysutils/py-py-cpuinfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.11:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>0:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qcelemental>=0.50.0:science/py-qcelemental@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		dftd3:science/dftd3 \
		dftd4:science/dftd4 \
		mctc-gcp:science/gcp \
		mopac:science/mopac \
		mp2d:science/mp2d \
		mrchem:science/py-mrchem@${PY_FLAVOR} \
		nwchem:science/nwchem \
		psi4:science/psi4 \
		rdkit>0:science/rdkit \
		s-dftd3:science/simple-dftd3 \
		xtb:science/xtb \
		${PYTHON_PKGNAMEPREFIX}dftd4>0:science/py-dftd4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyberny>0:science/py-pyberny@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geometric>0:science/py-geometric@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest # 1 tests fails, see https://github.com/MolSSI/QCEngine/issues/377#issuecomment-2191948293

NO_ARCH=	yes

.include <bsd.port.mk>
