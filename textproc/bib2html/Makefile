# ex:ts=8
# Ports collection makefile for:	bib2html
# Date created:			Jan 5, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	bib2html
DISTVERSION=	4.2-1
CATEGORIES=	textproc print
MASTER_SITES=	http://www.arakhne.org/IMG/gz/ \
		http://fresh.t-systems-sfr.com/fresh/unix/src/privat2/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The BibTeX to HTML Translator

WRKSRC=		${WRKDIR}/${PORTNAME}-4.2/src

USE_PERL5_RUN=	yes
NO_BUILD=	yes

post-patch:
	@${SED} -e 's:= "$$0";:= "${PREFIX}/${SITE_PERL_REL}/Bib2HTML";:g' \
		< ${WRKSRC}/bib2html.pl > ${WRKSRC}/bib2html
	@${SED} -e 's:= "$$0";:= "${PREFIX}/${SITE_PERL_REL}/Bib2HTML";:g' \
		< ${WRKSRC}/bib2xml.pl > ${WRKSRC}/bib2xml

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bib2html ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bib2xml ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/${SITE_PERL_REL}/Bib2HTML
	@cd ${WRKSRC}/Bib2HTML && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/${SITE_PERL_REL}/Bib2HTML
	${FIND} ${PREFIX}/${SITE_PERL_REL}/Bib2HTML -type f | ${XARGS} ${CHMOD} ${LIBMODE}
	${FIND} ${PREFIX}/${SITE_PERL_REL}/Bib2HTML -type d | ${XARGS} ${CHMOD} a+rx

.include <bsd.port.mk>
