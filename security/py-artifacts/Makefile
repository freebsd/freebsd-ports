PORTNAME=	artifacts
PORTVERSION=	20230928
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI \
		https://github.com/ForensicArtifacts/artifacts/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	ForensicArtifacts.com Artifact Repository
WWW=		https://github.com/ForensicArtifacts/artifacts

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=3.10:devel/py-pyyaml@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist concurrent
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD}
TEST_TARGET=	run_tests.py

post-patch:
	${REINPLACE_CMD} "s,share/artifacts,${DATADIR_REL}, ; \
		s,share/doc/artifacts,${DOCSDIR_REL}," ${WRKSRC}/setup.py
	${REINPLACE_CMD} "/pip/d" ${WRKSRC}/requirements.txt

.include <bsd.port.mk>
