# New ports collection makefile for:	webob
# Date created:		2009-02-12
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	webob
PORTVERSION=	1.0.3
PORTREVISION=	0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYDISTUTILS_PKGNAME}-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	WSGI request and response Python object

PYDISTUTILS_PKGNAME=	WebOb
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

USE_BZIP2=	yes

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
