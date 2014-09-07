# Created by: Paul Chvostek <paul@it.ca>
# $FreeBSD$

PORTNAME=	pdfjam
PORTVERSION=	2.08
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://www2.warwick.ac.uk/fac/sci/statistics/staff/academic/firth/software/pdfjam/ \
		ftp://ftp.stack.nl/pub/users/johans/pdfjam/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Shell scripts to manipulate PDF files

USE_TEX=	formats base
WRKSRC=		${WRKDIR}/${PORTNAME}

PROGS=		pdf90 pdf180 pdf270 pdfbook pdfflip pdfjam \
		pdfjam-pocketmod pdfjam-slides3up pdfjam-slides6up \
		pdfjoin pdfnup pdfpun
PLIST_FILES=	${PROGS:S/^/bin\//} etc/pdfjam.conf.dist \
		${PROGS:S|^|man/man1/|:S/$/.1.gz/}
PORTDOCS=	PDFjam-README.html pdfdroplets.png

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${PROGS:S|^|${WRKSRC}/bin/|g} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${PROGS:S|^|${WRKSRC}/man1/|g:S|$|.1|g} \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/pdfjam.conf \
		${STAGEDIR}${PREFIX}/etc/pdfjam.conf.dist
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|g} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
