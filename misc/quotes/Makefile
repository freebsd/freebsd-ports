# New ports collection makefile for:	quotes
# Date created:         9 February 1999
# Whom:                 Dima Sivachenko
#
# $FreeBSD$
#

PORTNAME=	quotes
DISTVERSION=	1.7-2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_TUCOWS} \
		http://freebsd.unixfreunde.de/sources/
MASTER_SITE_SUBDIR=	console/office

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quote, currency, and Slashdot headline fetcher based on Perl

NO_BUILD=	yes
USE_PERL5=	yes

post-patch:
	@ ${PERL} -pi -e "s:/usr/bin/perl:${PERL}:g" ${WRKSRC}/quotes
	@ ${PERL} -pi -e "s:/usr/local/lib/Quotes:${PREFIX}/etc:g" ${WRKSRC}/quotes
	@ ${PERL} -pi -e "s:/usr/local:${PREFIX}:g" ${WRKSRC}/quotes
	@ ${PERL} -pi -e "s:/usr/bin/perl:${PERL}:g" ${WRKSRC}/quotesmailer
	@ ${PERL} -pi -e "s:/usr/bin/perl:${PERL}:g" ${WRKSRC}/QuExample.pm

do-install:
	@ ${INSTALL_SCRIPT} ${WRKSRC}/quotes ${PREFIX}/bin
	@ ${INSTALL_SCRIPT} ${WRKSRC}/quotesmailer ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/sample.quotesrc ${PREFIX}/etc/quotesrc.sample
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/quotes.txt ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@ ${MKDIR} ${EXAMPLESDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/QuExample.pm ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
