# New ports collection makefile for:	p5-HTML-Summary
# Date created:			3 January 2000
# Whom:				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	p5-HTML-Summary
PORTVERSION= 	0.017
CATEGORIES=     www perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
DISTNAME=	HTML-Summary-0.017

MAINTAINER=	dima@Chg.RU

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree

USE_PERL5=	YES

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=		HTML::Summary.3 Text::Sentence.3 Lingua::JA::Jtruncate.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
