PORTNAME=	focker
DISTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	FreeBSD image orchestration tool in the vein of Docker
WWW=		https://github.com/sadaszewski/focker

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>0:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes # PyPi package is at 0.91
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	sadaszewski
GH_TAGNAME=	1f2d790

NO_ARCH=	yes

# some tests assume `focker` is installed. Tests
# need refactor to test against WRKSRC build
do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.mk>
