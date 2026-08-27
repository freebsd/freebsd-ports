PORTNAME=	flask-caching
PORTVERSION=	2.5.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	flask_caching-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Flask-Caching is an extension to Flask
WWW=		https://github.com/pallets-eco/flask-caching

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.11:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=3.0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachelib>=0.17.0:www/py-cachelib@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
