# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docbook-tdg
PORTVERSION=	2.0.17
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/tdg/en/
DISTNAME=	tdg-en-html-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Norman Walsh's book "DocBook: The Definitive Guide"

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/tdg/en

NO_STAGE=	yes
do-install:
.for D in html/figures/callouts html/figures/admon html/figures html
	${MKDIR} ${DOCSDIR}/${D}
	${INSTALL_DATA} ${WRKSRC}/${D}/*.* ${DOCSDIR}/${D}/
.endfor
	${INSTALL_DATA} ${FILESDIR}/index.html ${DOCSDIR}

.include <bsd.port.mk>
