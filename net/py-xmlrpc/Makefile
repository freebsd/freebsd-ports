# New ports collection makefile for:	py-xmlrpc
# Date created:				22 April 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	xmlrpc
PORTVERSION=	0.8.8.3
PORTREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	SF/py-${PORTNAME}/source/py-${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast implementation of the xmlrpc spec for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	py-xmlrpc
EXAMPLESDIR=	${PREFIX}/share/examples/py-xmlrpc

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/examples -cf- . | ${TAR} -C ${EXAMPLESDIR} -xpf-
.endif

.include <bsd.port.mk>
