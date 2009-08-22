# Ports collection makefile for:	makefaq
# Date created:				Sat Aug 23 07:15:39 CEST 2003
# Whom:					king@v2project.com
#
# $FreeBSD$
#

PORTNAME=	makefaq
PORTVERSION=	2.5
CATEGORIES=	textproc python
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Makefaq is a Python program that creates a (FAQ)

USE_PYTHON=	yes
NO_BUILD=	yes

MAN1=		makefaq.1
PLIST_FILES=	bin/makefaq.py
PORTDOCS=	README UPGRADING faq.html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/makefaq.py ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/makefaq.1  ${MAN1PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
