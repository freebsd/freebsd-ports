# New ports collection makefile for:	pdfjam
# Date created:		Tue Mar 15 17:50:34 EST 2005
# Whom:			Paul Chvostek <paul@it.ca>
#
# $FreeBSD$
#

PORTNAME=	pdfjam
PORTVERSION=	2.08
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www2.warwick.ac.uk/fac/sci/statistics/staff/academic/firth/software/pdfjam/ \
		ftp://ftp.stack.nl/pub/users/johans/pdfjam/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Shell scripts to manipulate PDF files

USE_TEX=	tetex
WRKSRC=		${WRKDIR}/${PORTNAME}

PROGS=		pdf90 pdf180 pdf270 pdfbook pdfflip pdfjam \
		pdfjam-pocketmod pdfjam-slides3up pdfjam-slides6up \
		pdfjoin pdfnup pdfpun
MAN1=		${PROGS:S/$/.1/}
PLIST_FILES=	${PROGS:S/^/bin\//} etc/pdfjam.conf.dist
PORTDOCS=	PDFjam-README.html pdfdroplets.png

NO_BUILD=	yes

do-install:
.for FILE in ${PROGS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${FILE} ${PREFIX}/bin
.endfor
.for FILE in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man1/${FILE} ${MAN1PREFIX}/man/man1
.endfor
	${INSTALL_DATA} ${WRKSRC}/pdfjam.conf ${PREFIX}/etc/pdfjam.conf.dist
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
