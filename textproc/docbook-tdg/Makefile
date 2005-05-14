# New ports collection makefile for:	docbook-tdg
# Date created:		24 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	docbook-tdg
PORTVERSION=	2.0.12
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/tdg/en/
DISTNAME=	tdg-en-html-${PORTVERSION}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Norman Walsh's book "DocBook: The Definitive Guide"

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/tdg/en

do-install:
.for D in html/figures/callouts html/figures/admon html/figures html
	${MKDIR} ${DOCSDIR}/${D}
	${INSTALL_DATA} ${WRKSRC}/${D}/*.* ${DOCSDIR}/${D}/
.endfor
	${INSTALL_DATA} ${FILESDIR}/index.html ${DOCSDIR}

.include <bsd.port.mk>
