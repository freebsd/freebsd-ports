# $FreeBSD$

PORTNAME=	djblets
PORTVERSION=	0.7.28
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://downloads.reviewboard.org/releases/Djblets/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Djblets-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of useful classes and functions for Django

DEPRECATED=	Django 1.4 extended support ended on 2015-10-01
EXPIRATION_DATE=	2015-12-09

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django14>=1.4.3:${PORTSDIR}/www/py-django14 \
		${PYTHON_PKGNAMEPREFIX}django-pipeline12>=1.2.24:${PORTSDIR}/www/py-django-pipeline12
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django14>=1.4.3:${PORTSDIR}/www/py-django14 \
		${PYTHON_PKGNAMEPREFIX}django-pipeline12>=1.2.24:${PORTSDIR}/www/py-django-pipeline12 \
		${PYTHON_PKGNAMEPREFIX}feedparser>=5.1.2:${PORTSDIR}/textproc/py-feedparser \
		${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz

USES=		python:2 shebangfix
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	Djblets

SHEBANG_FILES=	contrib/internal/build-media.py

.include <bsd.port.mk>
