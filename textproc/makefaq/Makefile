# Ports collection makefile for:	makefaq
# Date created:				Sat Aug 23 07:15:39 CEST 2003
# Whom:					king@v2project.com
#
# $FreeBSD$
#

PORTNAME=	makefaq
PORTVERSION=	2.4
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	king@v2project.com
COMMENT=	Makefaq is a Python program that creates a (FAQ)

USE_PYTHON=	yes
NO_BUILD=	yes

MAN1=		makefaq.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/makefaq.py ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/makefaq.1  ${PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README UPGRADING faq.html
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
