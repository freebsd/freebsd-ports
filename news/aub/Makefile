# ex:ts=8
# Ports collection makefile for:  aub
# Date created:			  Sun Oct 12, 1997
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	aub
PORTVERSION=	2.1.2
CATEGORIES=	news
MASTER_SITES=	http://yukidoke.org/~mako/projects/aub/download/

MAINTAINER=	obrien@FreeBSD.org

NO_BUILD=	yes
MAN1=		aub.1

DOC_FILES=	COPYING README aubconf.example Introducing_AUB USAGE

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/aub ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/aub.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/aub
.for doc in ${DOC_FILES}
	${INSTALL_MAN} ${WRKSRC}/${doc} ${PREFIX}/share/doc/aub
.endfor
.endif

.include <bsd.port.mk>
