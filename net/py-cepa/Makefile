PORTNAME=	cepa
PORTVERSION=	1.8.4
CATEGORIES=	net security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Python controller library for Tor, with v3 onion client auth support
WWW=		https://github.com/onionshare/cepa

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR}\
		${PYTHON_PKGNAMEPREFIX}pycryptodome>0:security/py-pycryptodome@${PY_FLAVOR}

TEST_DEPENDS=	tor:security/tor \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyflakes>0:devel/py-pyflakes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>0:devel/py-pycodestyle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	distutils autoplist concurrent
NO_ARCH=	yes

SHEBANG_FILES=		*.py
CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}stem-*

do-test:
	@cd ${WRKSRC} \
	&& ${PYTHON_CMD} run_tests.py -a

.include <bsd.port.mk>
