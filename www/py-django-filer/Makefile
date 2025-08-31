PORTNAME=	django-filer
PORTVERSION=	3.1.0
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xenophon+fbsdports@irtnog.org
COMMENT=	File and Image Management Application for django
WWW=		https://github.com/stefanfoulis/django-filer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=3.2<5.1:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-easy-thumbnails>0:graphics/py-django-easy-thumbnails@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-polymorphic>0:www/py-django-polymorphic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=		HEIF
OPTIONS_DEFAULT=	HEIF

HEIF_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow-heif>0:graphics/py-pillow-heif@${PY_FLAVOR}

.include <bsd.port.mk>
