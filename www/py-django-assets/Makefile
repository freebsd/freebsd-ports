PORTNAME=	django-assets
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Compress and merge CSS and Javascript files
WWW=		https://github.com/miracle2k/django-assets

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=1.7:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webassets>=2.0:www/py-webassets@${PY_FLAVOR}

USES=		dos2unix python
DOS2UNIX_FILES= django_assets/management/commands/assets.py
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
