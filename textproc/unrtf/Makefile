# New ports collection makefile for:	unrtf
# Date created:		26 March 2002
# Whom:			Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	unrtf
PORTVERSION=	0.18.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/unrtf

ALL_TARGET=	unrtf

MAN1=		unrtf.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/unrtf.1 ${PREFIX}/man/man1/${MAN1}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/unrtf.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
