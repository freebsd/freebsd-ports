PORTNAME=	django-htmx
DISTVERSION=	1.23.2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_htmx-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Extensions for using Django with htmx
WWW=		https://github.com/adamchainz/django-htmx

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asgiref>=3.6:www/py-asgiref@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

.include <bsd.port.mk>
