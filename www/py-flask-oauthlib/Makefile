PORTNAME=	Flask-OAuthlib
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	OAuthlib for Flask
WWW=		https://github.com/lepture/flask-oauthlib/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		imports oauthlib and werkzeug APIs removed in oauthlib 3.3 and Werkzeug 2.1
DEPRECATED=	Incompatible with current oauthlib and Werkzeug; upstream recommends security/py-authlib
EXPIRATION_DATE=	2026-11-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauthlib>0:security/py-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>0:www/py-requests-oauthlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
