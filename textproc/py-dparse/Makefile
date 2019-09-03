# $FreeBSD$

PORTNAME=	dparse
DISTVERSION=	0.4.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Parser for Python dependency files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

# test_update_pipfile fails with devel/py-pipenv >= 11.10.2 which is an
# optional dependency.  See also: https://github.com/pyupio/dparse/issues/37
do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v -k 'not pip'

.include <bsd.port.mk>
