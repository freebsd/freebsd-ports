PORTNAME=	trezor
PORTVERSION=	0.13.9
CATEGORIES=	security
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Client side implementation for TREZOR Bitcoin hardware wallets
WWW=		https://pypi.org/project/trezor/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}protobuf>=2.5.0:devel/py-protobuf@${PY_FLAVOR} \
		protoc:devel/protobuf
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}construct-classes>=0.1.2:devel/py-construct-classes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}construct>=2.9:devel/py-construct@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ecdsa>=0.9:security/py-ecdsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hidapi>=0.7.99.post20:comms/py-hidapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libusb1>=1.6.4:devel/py-libusb1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mnemonic>=0.20:security/py-mnemonic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=2.5.0:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.4.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.10:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
