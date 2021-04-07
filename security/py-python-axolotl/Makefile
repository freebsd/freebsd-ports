PORTNAME=	python-axolotl
PORTVERSION=	0.1.42
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Python port of libaxolotl-android

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-axolotl-curve25519>=0:security/py-python-axolotl-curve25519@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.0:devel/py-protobuf@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
