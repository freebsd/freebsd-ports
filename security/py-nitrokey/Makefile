PORTNAME=	nitrokey
DISTVERSION=	0.4.1
CATEGORIES=	security devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	monwarez@mailoo.org
COMMENT=	Python SDK for Nitrokey devices
WWW=		https://pypi.org/project/nitrokey/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fido2>=1.1.2,<3:security/py-fido2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semver>=0:devel/py-semver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tlv8>=0:converters/py-tlv8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crcmod>=1.7,<2:devel/py-crcmod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hidapi>=0.14,<0.15:comms/py-hidapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=5.26:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>=3.5,<4:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry>=0:devel/py-poetry@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fido2>=1.1.2,<3:security/py-fido2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semver>=0:devel/py-semver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tlv8>=0:converters/py-tlv8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crcmod>=1.7,<2:devel/py-crcmod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hidapi>=0.14,<0.15:comms/py-hidapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=5.26:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>=3.5,<4:comms/py-pyserial@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

.include <bsd.port.mk>
