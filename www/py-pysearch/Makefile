# New ports collection makefile for:	py-pysearch
# Date created:		Mar. 01, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	pysearch
PORTVERSION=	3.1
CATEGORIES=	www python
MASTER_SITES=	SF/${PORTNAME}/pYsearch/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pYsearch-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Yahoo Search Web Services SDK for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pYsearch

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
