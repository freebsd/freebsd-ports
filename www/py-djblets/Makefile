# $FreeBSD$

PORTNAME=	djblets
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://downloads.reviewboard.org/releases/Djblets/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Djblets-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of useful classes and functions for Django

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django16>=1.6.11:${PORTSDIR}/www/py-django16 \
		${PYTHON_PKGNAMEPREFIX}django-pipeline13>=1.3.27:${PORTSDIR}/www/py-django-pipeline13 \
		uglifyjs:${PORTSDIR}/www/uglifyjs
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django16>=1.6.11:${PORTSDIR}/www/py-django16 \
		${PYTHON_PKGNAMEPREFIX}django-pipeline13>=1.3.27:${PORTSDIR}/www/py-django-pipeline13 \
		${PYTHON_PKGNAMEPREFIX}feedparser>=5.1.2:${PORTSDIR}/textproc/py-feedparser \
		${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz

USES=		gettext-tools python:2 shebangfix
USE_PYTHON=	distutils autoplist
PYDISTUTILS_PKGNAME=	Djblets

SHEBANG_FILES=	contrib/internal/build-media.py

.include <bsd.port.mk>
