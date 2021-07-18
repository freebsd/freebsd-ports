# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	keepkey
PORTVERSION=	6.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Library for communicating with KeepKey Hardware Wallet

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ecdsa>=0.9:security/py-ecdsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hidapi>=0.7.99.post15:comms/py-hidapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libusb1>=1.6:devel/py-libusb1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mnemonic>=0.8:security/py-mnemonic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.0.0:devel/py-protobuf@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_PROJECT=	python-keepkey
GH_TUPLE=	keepkey:device-protocol:84d438b:devproto/device-protocol \
		keepkey:ethereum-lists:e216e92:ethlist/keepkeylib/eth/ethereum-lists
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
