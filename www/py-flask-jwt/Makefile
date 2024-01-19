PORTNAME=	Flask-JWT
DISTVERSION=	0.3.2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	JWT token authentication for Flask apps
WWW=		https://github.com/mattupstate/flask-jwt

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=0.9:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=1.4.0:www/py-pyjwt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail to run, see https://github.com/mattupstate/flask-jwt/issues/155

.include <bsd.port.mk>
