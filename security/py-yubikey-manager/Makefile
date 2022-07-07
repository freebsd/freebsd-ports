PORTNAME=	yubikey-manager
PORTVERSION=	4.0.9
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Python library and command line tool for configuring a YubiKey

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=2.6<40:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fido2>0:security/py-fido2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyscard>0:security/py-pyscard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyusb>0:devel/py-pyusb@${PY_FLAVOR} \
		RSA_SecurID_getpasswd:devel/libccid \
		pcsc-spy:devel/pcsc-lite \
		u2f-host:security/libu2f-host \
		ykpersonalize:security/ykpers
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}makefun>0:devel/py-makefun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		dos2unix python:3.6+
USE_PYTHON=	autoplist concurrent distutils unittest

DOS2UNIX_GLOB=	*.adoc *.py

NO_ARCH=	yes

.include <bsd.port.mk>
