# New ports collection makefile for:	pdfjam
# Date created:		Tue Mar 15 17:50:34 EST 2005
# Whom:			Paul Chvostek <paul@it.ca>
#
# $FreeBSD$
#

PORTNAME=	pdfjam
PORTVERSION=	1.20
CATEGORIES=	print
MASTER_SITES=	http://www2.warwick.ac.uk/fac/sci/statistics/staff/academic/firth/software/pdfjam/ \
		http://www.it.ca/~paul/src/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	paul+ports@it.ca
COMMENT=	Shell scripts to manipulate PDF files

RUN_DEPENDS=	pdflatex:${PORTSDIR}/print/teTeX-base

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		pdfjoin.1 pdf90.1 pdfnup.1
PLIST_FILES=	bin/pdfjoin bin/pdf90 bin/pdfnup
PORTDOCS=	PDFjam-README.html pdfdroplets.png

NO_BUILD=	yes

post-patch:
	@${LN} -s scripts ${WRKSRC}/bin
.for FILE in ${PLIST_FILES}
	@${SED} -i '' "1s:^#! /bin/sh:#!${SH}:;s:__LOCALBASE__:${LOCALBASE}:" ${WRKSRC}/${FILE}
.endfor

do-install:
.for FILE in ${PLIST_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor
.for FILE in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man1/${FILE} ${PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
