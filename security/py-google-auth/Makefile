PORTNAME=	google-auth
PORTVERSION=	2.53.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	google_auth-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Authentication Library
WWW=		https://github.com/googleapis/google-cloud-python/tree/main/packages/google-auth \
		https://github.com/googleapis/google-cloud-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0.2.1:devel/py-pyasn1-modules@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	AIOHTTP PYJWT REAUTH REQUESTS RSA URLLIB3
OPTIONS_DEFAULT=AIOHTTP PYJWT REQUESTS
AIOHTTP_DESC=	Asynchronous HTTP requests via aiohttp
AIOHTTP_IMPLIES=REQUESTS
PYJWT_DESC=	Create/verify JWT tokens
REAUTH_DESC=	Authentication while refreshing credentials
REQUESTS_DESC=	Transport adapter for requests
RSA_DESC=	RSA support (deprecated)
URLLIB3_DESC=	Transport adapter for urllib3

AIOHTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.8.0<4.0.0:www/py-aiohttp@${PY_FLAVOR}
PYJWT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyjwt>=2.0:www/py-pyjwt@${PY_FLAVOR}
REAUTH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyu2f>=0.1.5:net/py-pyu2f@${PY_FLAVOR}
REQUESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.20.0<3.0.0:www/py-requests@${PY_FLAVOR}
RSA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rsa>=3.1.4<5:security/py-rsa@${PY_FLAVOR}
URLLIB3_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}urllib3>=0,1:net/py-urllib3@${PY_FLAVOR}

.include <bsd.port.mk>
