# ex:ts=8
# Ports collection makefile for:	bib2html
# Date created:			Jan 5, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	bib2html
PORTVERSION=	3.3
CATEGORIES=	textproc print
MASTER_SITES=	http://galland.stephane.free.fr/arakhne.org/bib2html/ \
		http://fresh.t-systems-sfr.com/unix/src/privat2/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The BibTeX to HTML Translator

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_PERL5_RUN=	yes
NO_BUILD=	yes

post-patch:
	@${SED} -e 's:= "$$0";:= "${SITE_PERL}/Bib2HTML";:g' \
		< ${WRKSRC}/bib2html.pl > ${WRKSRC}/bib2html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bib2html ${PREFIX}/bin
	@${MKDIR} ${SITE_PERL}/Bib2HTML
	@cd ${WRKSRC}/Bib2HTML && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${SITE_PERL}/Bib2HTML
	${FIND} ${SITE_PERL}/Bib2HTML -type f | ${XARGS} ${CHMOD} ${LIBMODE}
	${FIND} ${SITE_PERL}/Bib2HTML -type d | ${XARGS} ${CHMOD} a+rx

.include <bsd.port.mk>
