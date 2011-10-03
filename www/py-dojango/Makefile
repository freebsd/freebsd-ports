# Ports collection makefile for:	py-dojango
# Date created:			Sept 13, 2010
# Whom:				jpaetzel
#
# $FreeBSD$
#

PORTNAME=	dojango
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	www python java
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
MASTER_SITE_SUBDIR=	""
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	A django application for building dojo

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME}

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django

OPTIONS=	JAVA	"Java support needed to build dojo libraries"	off

.include <bsd.port.pre.mk>

.if defined(WITH_JAVA)
USE_JAVA=	yes
JAVA_VERSION=	1.6+
.endif

.include <bsd.port.post.mk>
