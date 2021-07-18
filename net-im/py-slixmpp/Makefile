PORTNAME=	slixmpp
DISTVERSION=	1.7.1
CATEGORIES=	net-im python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Elegant Python library for XMPP (aka Jabber, Google Talk, etc.)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libidn.so:dns/libidn
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0:devel/py-pyasn1-modules@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiodns>=1.0:dns/py-aiodns@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR}
TEST_DEPENDS=	gpg:security/gnupg

USES=		pkgconfig python:3.7+
USE_PYTHON=	distutils autoplist cython

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
