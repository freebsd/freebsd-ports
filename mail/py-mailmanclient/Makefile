PORTNAME=	mailmanclient
PORTVERSION=	3.3.1
CATEGORIES=	mail
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Official Python bindings for the GNU Mailman 3 REST API

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flake8>3.0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8-bugbear>0:devel/py-flake8-bugbear@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mailman>0:mail/mailman3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}falcon>0:www/py-falcon@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC}/src/mailmanclient/tests && ${PYTHON_CMD} test_client.py

.include <bsd.port.mk>
