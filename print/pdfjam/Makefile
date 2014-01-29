# Created by: Paul Chvostek <paul@it.ca>
# $FreeBSD$

PORTNAME=	pdfjam
PORTVERSION=	2.08
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www2.warwick.ac.uk/fac/sci/statistics/staff/academic/firth/software/pdfjam/ \
		ftp://ftp.stack.nl/pub/users/johans/pdfjam/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Shell scripts to manipulate PDF files

USE_TEX=	latex
WRKSRC=		${WRKDIR}/${PORTNAME}

PROGS=		pdf90 pdf180 pdf270 pdfbook pdfflip pdfjam \
		pdfjam-pocketmod pdfjam-slides3up pdfjam-slides6up \
		pdfjoin pdfnup pdfpun
PLIST_FILES=	${PROGS:S/^/bin\//} etc/pdfjam.conf.dist \
		${PROGS:S|^|man/man1/|:S/$/.1.gz/}
PORTDOCS=	PDFjam-README.html pdfdroplets.png

NO_BUILD=	yes

.include <bsd.port.options.mk>

do-install:
.for FILE in ${PROGS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${FILE} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man1/${FILE}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor
	${INSTALL_DATA} ${WRKSRC}/pdfjam.conf ${STAGEDIR}${PREFIX}/etc/pdfjam.conf.dist
.ifndef NOPORTDOCS
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
