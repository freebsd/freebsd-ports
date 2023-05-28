PORTNAME=	bonsai
DISTVERSION=	1.5.1
CATEGORIES=	net devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	meka@tilda.center
COMMENT=	Module for handling LDAP operations in Python
WWW=		https://github.com/noirello/bonsai

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

MY_DEPENDS=	openldap26-client>=0:net/openldap26-client
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		localbase python:3.7+
USE_PYTHON=	autoplist concurrent distutils pytest

OPTIONS_DEFINE=	GEVENT TORNADO TRIO

GEVENT_DESC=		Support for async IO using gevent
GEVENT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gevent>=0:devel/py-gevent@${PY_FLAVOR}
TORNADO_DESC=		Support for async IO using tornado
TORNADO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado>=0:www/py-tornado@${PY_FLAVOR}
TRIO_DESC=		Support for async IO using trio
TRIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}trio>=0:net/py-trio@${PY_FLAVOR}

.include <bsd.port.mk>
