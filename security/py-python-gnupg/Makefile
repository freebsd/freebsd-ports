PORTNAME=	python-gnupg
DISTVERSION=	0.4.7
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Python wrapper for the GNU Privacy Guard (GPG or GnuPG)
WWW=		https://docs.red-dove.com/python-gnupg/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0.15.2:devel/py-coverage@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
		@(cd ${WRKSRC} && ${SETENV} ${PYTHON_CMD} test_gnupg.py --no-doctests)
		@(cd ${WRKSRC} && ${SETENV} coverage-${PYTHON_VER} run test_gnupg.py --no-doctests)

.include <bsd.port.mk>
