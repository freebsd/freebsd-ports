PORTNAME=	django-htmx
DISTVERSION=	1.29.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_htmx-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Extensions for using Django with htmx
WWW=		https://github.com/adamchainz/django-htmx

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0.11.28:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=5.2:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asgiref>=3.6:www/py-asgiref@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

.include <bsd.port.mk>
