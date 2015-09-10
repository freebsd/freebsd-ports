# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	django-photologue
PORTVERSION=	2.6.1
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Reusable gallery application for Django

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow

USES=		python zip
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=		TAGGING
OPTIONS_DEFAULT=	TAGGING

TAGGING_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/tagging/models.py:${PORTSDIR}/www/py-django-tagging

.include <bsd.port.mk>
