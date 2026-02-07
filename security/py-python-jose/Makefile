PORTNAME=	python-jose
PORTVERSION=	3.4.0
CATEGORIES=	security
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JOSE implementation in Python
WWW=		https://python-jose.readthedocs.io/en/latest/ \
		https://github.com/mpdavis/python-jose

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=39.2.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.29.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ecdsa>=0:security/py-ecdsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.4.1:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rsa>=4.0<5.0:security/py-rsa@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	CRYPTOGRAPHY PYCRYPTODOME
OPTIONS_DEFAULT=CRYPTOGRAPHY
CRYPTOGRAPHY_DESC=	Use cryptography as cryptographic backend
PYCRYPTODOME_DESC=	Use pycryptodome as cryptographic backend

CRYPTOGRAPHY_USE=		PYTHON=cryptography
PYCRYPTODOME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.3.1<4.0.0:security/py-pycryptodome@${PY_FLAVOR}

.include <bsd.port.mk>
