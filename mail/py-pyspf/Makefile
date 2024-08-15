PORTNAME=	pyspf
PORTVERSION=	2.0.14
PORTREVISION=	2
CATEGORIES=	mail python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SPF (Sender Policy Framework) implemented in Python
WWW=		https://github.com/sdgathman/pyspf

LICENSE=	PSFL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}authres>=0:mail/py-authres@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=1.16.0,1:dns/py-dnspython@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

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
