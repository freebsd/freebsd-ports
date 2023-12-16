PORTNAME=	python-gnupg
DISTVERSION=	0.5.1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Python wrapper for the GNU Privacy Guard (GPG or GnuPG)
WWW=		https://docs.red-dove.com/python-gnupg/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0.15.2:devel/py-coverage@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

do-test:
		@(cd ${WRKSRC} && ${SETENV} ${PYTHON_CMD} test_gnupg.py --no-doctests)
		@(cd ${WRKSRC} && ${SETENV} coverage-${PYTHON_VER} run test_gnupg.py --no-doctests)

.include <bsd.port.mk>
