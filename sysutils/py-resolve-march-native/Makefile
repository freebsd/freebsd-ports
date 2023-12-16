PORTNAME=	resolve-march-native
DISTVERSION=	5.0.1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Command line tool to resolve -march=native into explicit flags
WWW=		https://github.com/hartwork/resolve-march-native

LICENSE=	GPLv2+

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	hartwork
USE_PYTHON=	autoplist concurrent distutils

ALL_TARGET=	install
BINARY_ALIAS=	python=${PYTHON_CMD}
NO_ARCH=	yes
TEST_TARGET=	check

.include <bsd.port.mk>
