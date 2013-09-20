# Created by: ijliao
# $FreeBSD$

PORTNAME=	bib2html
DISTVERSION=	5.1-1
CATEGORIES=	textproc print
MASTER_SITES=	http://www.arakhne.org/IMG/gz/ \
		http://fresh.t-systems-sfr.com/fresh/unix/src/privat2/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	The BibTeX to HTML Translator

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/-[0-9]$//}/src

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes

NO_STAGE=	yes
post-patch:
	@${SED} -e \
		's:= "$$0";:= "${PREFIX}/${SITE_PERL_REL}/Bib2HTML";:g' \
		< ${WRKSRC}/bib2html.pl > ${WRKSRC}/bib2html
	@${SED} -e \
		's:= "$$0";:= "${PREFIX}/${SITE_PERL_REL}/Bib2HTML";:g' \
		< ${WRKSRC}/bib2xml.pl > ${WRKSRC}/bib2xml

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bib2html ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bib2xml ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/${SITE_PERL_REL}/Bib2HTML
	@cd ${WRKSRC}/Bib2HTML && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} \
		${PREFIX}/${SITE_PERL_REL}/Bib2HTML
	${FIND} ${PREFIX}/${SITE_PERL_REL}/Bib2HTML -type f | \
		${XARGS} ${CHMOD} ${LIBMODE}
	${FIND} ${PREFIX}/${SITE_PERL_REL}/Bib2HTML -type d | \
		${XARGS} ${CHMOD} a+rx
	@${FIND} ${PREFIX}/${SITE_PERL_REL}/Bib2HTML -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${PREFIX}/${SITE_PERL_REL}/Bib2HTML -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.mk>
