PORTNAME=	pykeepass-cache
DISTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Database caching for PyKeePass
WWW=		https://pypi.org/project/pykeepass-cache \
		https://github.com/libkeepass/pykeepass_cache

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}daemon>=0:devel/py-daemon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pykeepass>=0:security/py-pykeepass@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rpyc>=0:devel/py-RPyC@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
