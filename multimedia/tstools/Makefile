# New ports collection makefile for:	tstools
# Date created:		2009 January 12
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	tstools
DISTVERSION=	1_11
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	tstools
EXTRACT_SUFX=	.tgz

MAINTAINER=	fbsd@opal.com
COMMENT=	MPEG transport, program, and elementary stream tools

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

do-install:
		@${MKDIR} ${PREFIX}/bin
		${CP} ${WRKSRC}/bin/* ${PREFIX}/bin
		@${MKDIR} ${PREFIX}/lib
		${CP} ${WRKSRC}/lib/* ${PREFIX}/lib
.if !defined(NOPORTDOCS)
		@${MKDIR} ${PREFIX}/share/docs/${PORTNAME}
		${CP} ${WRKSRC}/docs/* ${PREFIX}/share/docs/${PORTNAME}
.endif

.include <bsd.port.post.mk>
