# Created by: jpaetzel
# $FreeBSD$

PORTNAME=	dojango
PORTVERSION=	0.5.9
PORTREVISION=	1
CATEGORIES=	www python java
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Django application for building dojo

LICENSE=	BSD3CLAUSE

DEPRECATED=	No longer maintained, not compatible with Django 2.2+
EXPIRATION_DATE=	2020-06-01

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=1.6:www/py-django111@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	william-gr
GH_PROJECT=	dojango
GH_TAGNAME=	7477cee

OPTIONS_DEFINE=		JAVA

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJAVA}
USE_JAVA=	yes
.endif

.include <bsd.port.mk>
