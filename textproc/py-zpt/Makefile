# Ports collection makefile for:	py-zpt
# Date created:				8 Mar 2005
# Whom:					Benno Rice <benno@jeamland.net>
#
# $FreeBSD$
#

PORTNAME=	zpt
PORTVERSION=	2.5
CATEGORIES=	textproc python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ZopePageTemplates-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Zope-less version of Zope Page Templates

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	ZopePageTemplates
PYDISTUTILS_PKGVERSION=	0.0.0
PYDISTUTILS_EGGINFODIR=	${PYTHONPREFIX_SITELIBDIR}/ZopePageTemplates
WRKSRC=		${WRKDIR}/ZopePageTemplates

.include <bsd.port.mk>
