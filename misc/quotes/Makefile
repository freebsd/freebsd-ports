# New ports collection makefile for:	quotes
# Date created:         9 February 1999
# Whom:                 Dima Sivachenko
#
# $FreeBSD$
#

PORTNAME=	quotes
PORTVERSION=	1.7.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.coralys.com/pub/free/
DISTNAME=	${PORTNAME}-1.7-2

MAINTAINER=	demon@FreeBSD.org
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
	@ ${INSTALL_DATA} ${WRKSRC}/QuExample.pm ${DOCSDIR}
.endif

.include <bsd.port.mk>
