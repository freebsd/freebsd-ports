# ex:ts=8
# Ports collection makefile for:	bib2html
# Date created:			Jan 5, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	bib2html
PORTVERSION=	0.10
CATEGORIES=	textproc print
MASTER_SITES=	http://www.arakhne.org/mirrors/ \
		http://fresh.t-systems-sfr.com/unix/src/privat2/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The BibTeX to HTML Translator

USE_REINPLACE=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

PLIST_FILES=	bin/bib2html

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 500800
BROKEN=		"Does not install"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%SITE_PERL%%|${SITE_PERL}|" ${WRKSRC}/bib2html.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bib2html.pl ${PREFIX}/bin/bib2html
	${CP} -R ${WRKSRC}/Bib2HTML ${SITE_PERL}
	@${FIND} ${SITE_PERL}/Bib2HTML -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${SITE_PERL}/Bib2HTML -type d | ${SORT} -r |  \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.post.mk>
