PORTNAME=	dkimpy
DISTVERSION=	1.1.8
CATEGORIES=	mail python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Python library for DKIM email signing and verification
WWW=		https://launchpad.net/dkimpy

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}authres>=0:mail/py-authres@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiodns>0:dns/py-aiodns@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=0:security/py-pynacl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

.include <bsd.port.mk>
