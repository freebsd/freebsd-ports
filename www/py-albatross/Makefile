# New ports collection makefile for:	albatross
# Date created:		29 August 2002
# Whom:	      		Gregory Bond <gnb@itga.com.au>
#
# $FreeBSD$

PORTNAME=	albatross
PORTVERSION=	1.01
CATEGORIES=	www python
MASTER_SITES=	http://object-craft.com.au/projects/albatross/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnb@itga.com.au

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	@${TAR} -cf - -C ${WRKSRC}/doc . | ${TAR} -xf - -C ${DOCSDIR}
	@${TAR} -cf - -C ${WRKSRC}/samples . | ${TAR} -xf - -C ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
