PORTNAME=	stem
PORTVERSION=	1.8.0
CATEGORIES=	security net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Python controller library for Tor

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expired security/py-pycrypto
EXPIRATION_DATE=2022-09-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyflakes>0:devel/py-pyflakes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>0:devel/py-pycodestyle@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist concurrent
NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} run_tests.py -a

.include <bsd.port.mk>
