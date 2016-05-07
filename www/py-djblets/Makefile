# $FreeBSD$

PORTNAME=	djblets
PORTVERSION=	0.9.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Djblets-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Collection of useful classes and functions for Django

LICENSE=	MIT

BUILD_DEPENDS=	uglifyjs:www/uglifyjs
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django16>=1.6.11:www/py-django16 \
		${PYTHON_PKGNAMEPREFIX}django-pipeline13>=1.3.27:www/py-django-pipeline13 \
		${PYTHON_PKGNAMEPREFIX}feedparser>=5.1.2:textproc/py-feedparser \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz

NO_ARCH=	yes
USES=		gettext-tools python:-2.7 shebangfix
USE_PYTHON=	autoplist distutils

SHEBANG_FILES=	contrib/internal/build-i18n.py \
		contrib/internal/build-media.py \
		contrib/internal/release.py

.include <bsd.port.mk>
