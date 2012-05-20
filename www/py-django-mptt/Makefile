# New ports collection makefile for:	django-mptt
# Date created:				2011-02-16
# Whom:					Carlo Strub
#
# $FreeBSD$
#

PORTNAME=	django-mptt
PORTVERSION=	0.5.2
CATEGORIES=	www python
MASTER_SITES=	https://github.com/django-mptt/django-mptt/tarball/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Utilities for implementing a pre-order traversal tree in django

LICENSE=	BSD

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django

GITVERSION=	8ab6a85

FETCH_ARGS=	-Fpr
USE_GETTEXT=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-${GITVERSION}

do fetch:
	[ -f ${DISTDIR}/${DISTFILES} ] || \
		${FETCH_CMD} -o ${DISTDIR}/${DISTFILES} \
			${MASTER_SITES}${PORTVERSION}

.include <bsd.port.mk>
