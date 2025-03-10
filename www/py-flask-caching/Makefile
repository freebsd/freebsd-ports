PORTNAME=	flask-caching
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	flask_caching-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Flask-Caching is an extension to Flask
WWW=		https://github.com/pallets-eco/flask-caching

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=0.8:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachelib>0:www/py-cachelib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
