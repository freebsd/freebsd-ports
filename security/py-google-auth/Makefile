PORTNAME=	google-auth
PORTVERSION=	2.25.2
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Authentication Library
WWW=		https://github.com/googleapis/google-auth-library-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachetools>=2.0.0<6.0:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0.2.1:devel/py-pyasn1-modules@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rsa>=3.1.4<5:security/py-rsa@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	AIOHTTP REAUTH REQUESTS
OPTIONS_DEFAULT=AIOHTTP REQUESTS
AIOHTTP_DESC=	Use aiohttp
REAUTH_DESC=	Reauth support
REQUESTS_DESC=	Requests support

AIOHTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.6.2<4.0.0:www/py-aiohttp@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>=2.20.0<3.0.0:www/py-requests@${PY_FLAVOR}
REAUTH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyu2f>=0.1.5:net/py-pyu2f@${PY_FLAVOR}
REQUESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.20.0<3.0.0:www/py-requests@${PY_FLAVOR}

.include <bsd.port.mk>
