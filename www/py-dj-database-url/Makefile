PORTNAME=	dj-database-url
DISTVERSION=	3.0.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	dj_database_url-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Use Database URLs in your Django Application
WWW=		https://github.com/jazzband/dj-database-url

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
