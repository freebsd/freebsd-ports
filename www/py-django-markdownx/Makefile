# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	django-markdownx
PORTVERSION=	2.0.23
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Django Markdown editor with image uploads and live preview

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:www/py-django18@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${FLAVOR}

USE_GITHUB=	yes

GH_ACCOUNT=	neutronX
USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
