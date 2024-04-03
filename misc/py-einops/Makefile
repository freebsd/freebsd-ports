PORTNAME=	einops
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	misc # machine-learning
#MASTER_SITES=	PYPI # some test files are missing in the PYPI tarball
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	New flavour of deep learning operations
WWW=		https://einops.rocks/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.10.0:devel/py-hatchling@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nbconvert>0:devel/py-nbconvert@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 5 tests fail because of some pytorch issues, see https://github.com/arogozhnikov/einops/issues/313

USE_GITHUB=	yes
GH_ACCOUNT=	arogozhnikov

NO_ARCH=	yes

BINARY_ALIAS=	python=${PYTHON_CMD}

TEST_ENV=	${MAKE_ENV} EINOPS_TEST_BACKENDS="numpy,torch"

do-test-via-script:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} test.py numpy pytorch

.include <bsd.port.mk>
