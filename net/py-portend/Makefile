# $FreeBSD$

PORTNAME=	portend
PORTVERSION=	2.5
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	k@stereochro.me
COMMENT=	Monitors TCP ports for bound or unbound states

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.15.0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tempora>=1.8:devel/py-tempora@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.5:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# Ignore non-compulsory dependencies (flake8, etc.) from pytest.ini via "-o"
do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v -o addopts=''

.include <bsd.port.mk>
