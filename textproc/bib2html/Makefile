# ex:ts=8
# Ports collection makefile for:	bib2html
# Date created:			Jan 5, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	bib2html
PORTVERSION=	1.0
CATEGORIES=	textproc print
MASTER_SITES=	http://galland.stephane.free.fr/arakhne.org/bib2html/ \
		http://fresh.t-systems-sfr.com/unix/src/privat2/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The BibTeX to HTML Translator

USE_REINPLACE=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

PLIST_FILES=	bin/bib2html

post-patch:
	@${REINPLACE_CMD} -e "s|%%SITE_PERL%%|${SITE_PERL}|" ${WRKSRC}/bib2html.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bib2html.pl ${PREFIX}/bin/bib2html
	@${MKDIR} ${SITE_PERL}
	${CP} -R ${WRKSRC}/Bib2HTML ${SITE_PERL}
	@${FIND} ${SITE_PERL}/Bib2HTML -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${SITE_PERL}/Bib2HTML -type d | ${SORT} -r |  \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.mk>
