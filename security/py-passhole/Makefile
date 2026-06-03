PORTNAME=	passhole
DISTVERSION=	1.10.1
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Secure hole for your passwords (KeePass CLI)
WWW=		https://pypi.org/project/passhole \
		https://github.com/Evidlo/passhole

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pykeepass-cache>=0:security/py-pykeepass-cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pykeepass>=0:security/py-pykeepass@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynput>=0:x11/py-pynput@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyotp>=0:security/py-pyotp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>=0:textproc/py-qrcode@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
