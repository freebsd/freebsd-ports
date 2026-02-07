PORTNAME=	django-filer
DISTVERSION=	3.4.3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_filer-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	File and Image Management Application for django
WWW=		https://github.com/django-cms/django-filer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=3.2:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-easy-thumbnails>0:graphics/py-django-easy-thumbnails@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-polymorphic<5:www/py-django-polymorphic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}svglib>=1.5.1:converters/py-svglib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

OPTIONS_DEFINE=		HEIF
OPTIONS_DEFAULT=	HEIF

HEIF_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow-heif>0:graphics/py-pillow-heif@${PY_FLAVOR}

.include <bsd.port.mk>
