PORTNAME=	django-compression-middleware
PORTVERSION=	0.5.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj52-

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Django middleware to compress responses using several algorithms
WWW=		https://github.com/friedelwolff/django-compression-middleware

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=5.2:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zstandard>=0.22.0:archivers/py-zstandard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}brotli>=1.1.0:archivers/py-brotli@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

.include <bsd.port.mk>
