# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	google-auth
PORTVERSION=	1.32.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Authentication Library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachetools>=2.0.0<5.0:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0.2.1:devel/py-pyasn1-modules@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rsa>=3.1.4<5:security/py-rsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	AIOHTTP PYOPENSSL REAUTH
OPTIONS_DEFAULT=AIOHTTP
AIOHTTP_DESC=	Use aiohttp
PYOPENSSL_DESC=	OpenSSL support
REAUTH_DESC=	Reauth support

AIOHTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.6.2<4.0.0:www/py-aiohttp@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>=2.20.0:www/py-requests@${PY_FLAVOR}
PYOPENSSL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=20.0.0:security/py-openssl@${PY_FLAVOR}
REAUTH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyu2f>=0.1.5:net/py-pyu2f@${PY_FLAVOR}

.include <bsd.port.mk>
