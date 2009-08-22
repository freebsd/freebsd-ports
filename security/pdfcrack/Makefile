# New ports collection makefile for:   snoopy
# Date created:			24 October 2007
# Whom:                        Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	pdfcrack
PORTVERSION=	0.11
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A command line, password recovery tool for PDF-files

USE_GMAKE=	yes

PLIST_FILES=	bin/pdfcrack
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdfcrack ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
