PORTNAME=	readchar
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.5
CATEGORIES=	textproc devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Python library to read characters and key strokes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/README.rst

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		dos2unix localbase python:3.6+
DOS2UNIX_GLOB=	*.py
# CHEESESHOP does not seem to work so far.
USE_GITHUB=	yes
GH_ACCOUNT=	magmax
GH_PROJECT=	python-${PORTNAME}
USE_PYTHON=	autoplist distutils

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
