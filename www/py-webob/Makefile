# New ports collection makefile for:	webob
# Date created:		2009-02-12
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	webob
DISTVERSION=	1.2b2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYDISTUTILS_PKGNAME}-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	WSGI request and response Python object

PYDISTUTILS_PKGNAME=	WebOb
PYDISTUTILS_PKGVERSION=	${DISTVERSION}
USE_PYTHON=	2.6+
USE_PYDISTUTILS=	easy_install

USE_ZIP=	yes

.include <bsd.port.mk>
