PORTNAME=	wcmatch
PORTVERSION=	10.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Wildcard/glob file name matcher
WWW=		https://pypi.org/project/wcmatch/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0.21.1:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=22.2:devel/py-pip@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bracex>=2.1.1:textproc/py-bracex@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

# Windows specific tests
PYTEST_IGNORED_TESTS=	test_escape_windows \
			test_norm_windows \
			test_escape_windows \
			test_drive_insensitive \
			test_drive_sensitive \
			test_root_win \
			test_glob_match_real_ignore_forceunix

NO_ARCH=	yes

.include <bsd.port.mk>
