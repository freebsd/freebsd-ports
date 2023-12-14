PORTNAME=	google-auth-oauthlib
PORTVERSION=	1.2.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Authentication Library
WWW=		https://github.com/googleapis/google-auth-library-python-oauthlib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-auth>=2.15.0:security/py-google-auth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0:www/py-requests-oauthlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	TOOL
OPTIONS_DEFAULT=TOOL
TOOL_DESC=	Tool for obtaining authorization and credentials

TOOL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=6.0.0:devel/py-click@${PY_FLAVOR}

.include <bsd.port.mk>
