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

post-patch:
	@${SED} -e \
		's:= "$$0";:= "${SITE_PERL}/Bib2HTML";:g' \
		< ${WRKSRC}/bib2html.pl > ${WRKSRC}/bib2html
	@${SED} -e \
		's:= "$$0";:= "${SITE_PERL}/Bib2HTML";:g' \
		< ${WRKSRC}/bib2xml.pl > ${WRKSRC}/bib2xml

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bib2html ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bib2xml ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${SITE_PERL}/Bib2HTML
	cd ${WRKSRC}/Bib2HTML && ${COPYTREE_SHARE} . ${STAGEDIR}${SITE_PERL}/Bib2HTML
	${FIND} ${STAGEDIR}${SITE_PERL}/Bib2HTML -type f | \
		${SED} "s,^${STAGEDIR}${PREFIX}/,," >> ${TMPPLIST}
	${FIND} ${STAGEDIR}${SITE_PERL}/Bib2HTML -type d | ${SORT} -r | \
		${SED} "s,^${STAGEDIR}${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.mk>
