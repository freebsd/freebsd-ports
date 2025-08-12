PORTNAME=	google-auth-oauthlib
PORTVERSION=	1.2.2
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	google_auth_oauthlib-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Authentication Library
WWW=		https://github.com/googleapis/google-auth-library-python-oauthlib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-auth>=2.15.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0:www/py-requests-oauthlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	TOOL
OPTIONS_DEFAULT=TOOL
TOOL_DESC=	Tool for obtaining authorization and credentials

TOOL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=6.0.0:devel/py-click@${PY_FLAVOR}

.include <bsd.port.mk>
