# Created by: Marcus Alves Grando <mnag@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyspf
PORTVERSION=	2.0.14
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SPF (Sender Policy Framework) implemented in Python

LICENSE=	PSFL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}authres>=0:mail/py-authres@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=1.16.0:dns/py-dnspython@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}

USES=		python:3.6+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PLIST_FILES=	bin/spf.py

SHEBANG_FILES=	spf.py

# Make the tests run as a module
post-patch:
	@${TOUCH} ${WRKSRC}/test/__init__.py

post-install:
	${CHMOD} ${BINMODE} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/spf.py
	${RLN} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/spf.py ${STAGEDIR}${PREFIX}/bin/

do-test:
	cd ${WRKSRC}/ && ${PYTHON_CMD} -m test.testspf

.include <bsd.port.mk>
