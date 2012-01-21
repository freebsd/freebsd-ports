# New ports collection makefile for:	django-mptt
# Date created:				2011-02-16
# Whom:					Carlo Strub
#
# $FreeBSD$
#

PORTNAME=	django-mptt
PORTVERSION=	0.4.2
CATEGORIES=	www python
MASTER_SITES=	http://www.c-s.li/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Utilities for implementing a pre-order traversal tree in django

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	BSD

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-7d3e111
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
