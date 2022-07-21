PORTNAME=	bitbox02
PORTVERSION=	6.1.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Python API for communicating with the BitBox02 device

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}base58>=2.0.0:security/py-base58@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ecdsa>=0.14:security/py-ecdsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hidapi>=0:comms/py-hidapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}noiseprotocol>=0.3:security/py-noiseprotocol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.7:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semver>=2.8.1:devel/py-semver@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
