# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	pdfcrack
PORTVERSION=	0.11
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	A command line, password recovery tool for PDF-files

DEPRECATED=	Not active since several years
EXPIRATION_DATE=	2013-12-08

USE_GMAKE=	yes

PLIST_FILES=	bin/pdfcrack
PORTDOCS=	README

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdfcrack ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
