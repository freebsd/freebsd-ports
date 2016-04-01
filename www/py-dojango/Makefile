# Created by: jpaetzel
# $FreeBSD$

PORTNAME=	dojango
PORTVERSION=	0.5.7
PORTREVISION=	1
CATEGORIES=	www python java
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Django application for building dojo

USES=		python
USE_PYTHON=	distutils autoplist

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>=1.6:www/py-django18

OPTIONS_DEFINE=		JAVA

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJAVA}
USE_JAVA=	yes
JAVA_VERSION=	1.6+
.endif

.include <bsd.port.mk>
