# Created by: Antoine Brodin <antoine@FreeBSD.org>

PORTNAME=	artifacts
PORTVERSION=	20210620
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP \
		https://github.com/ForensicArtifacts/artifacts/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	ForensicArtifacts.com Artifact Repository

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=4.2.0:devel/py-pbr@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.5+
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	distutils autoplist concurrent
DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD}
TEST_TARGET=	run_tests.py

post-patch:
	${REINPLACE_CMD} "s,share/artifacts,${DATADIR_REL}, ; \
		s,share/doc/artifacts,${DOCSDIR_REL}," ${WRKSRC}/setup.py

.include <bsd.port.mk>
