# ex:ts=8
# Ports collection makefile for:  aub
# Date created:			  Sun Oct 12, 1997
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	aub
PORTVERSION=	2.2
CATEGORIES=	news
MASTER_SITES=	http://yukidoke.org/~mako/projects/aub/download/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Assemble usenet binaries

NO_BUILD=	yes
MAN1=		aub.1.sgml aubconf.1.sgml
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DOC_FILES=	COPYING README aubconf.example

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/aub ${PREFIX}/bin
.for manpage in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${manpage} ${MANPREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	${INSTALL_MAN} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
