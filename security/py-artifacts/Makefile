PORTNAME=	artifacts
PORTVERSION=	20260421
CATEGORIES=	security python
MASTER_SITES=	PYPI \
		https://github.com/ForensicArtifacts/artifacts/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	ForensicArtifacts.com Artifact Repository
WWW=		https://github.com/ForensicArtifacts/artifacts

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=3.10:devel/py-pyyaml@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517
SHEBANG_FILES=	artifacts/scripts/stats.py \
		artifacts/scripts/validator.py
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD}
TEST_TARGET=	run_tests.py

.include <bsd.port.mk>
