# New ports collection makefile for:    p5-WWW-Search
# Version required:			1.019
# Date created:				June 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.ORG>
#
# $Id: Makefile,v 1.4 1998/06/04 03:51:19 vanilla Exp $
#

DISTNAME=	WWW-Search-1.019
PKGNAME=	p5-WWW-Search-1.019
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/5.005/LWP.pm:${PORTSDIR}/www/p5-libwww

USE_PERL5=	YES

MAN1PREFIX=	${PREFIX}
MAN1=		AutoSearch.1 WebSearch.1
MAN3PREFIX=	${PREFIX}/lib/perl5/5.00501
MAN3=		WWW::Search.3 WWW::Search::AltaVista.3 \
		WWW::Search::AltaVista::AdvancedNews.3 \
		WWW::Search::AltaVista::AdvancedWeb.3 \
		WWW::Search::AltaVista::News.3 WWW::Search::AltaVista::Web.3 \
		WWW::Search::Dejanews.3 WWW::Search::Excite.3 \
		WWW::Search::HotBot.3 WWW::Search::Infoseek.3 \
		WWW::Search::Infoseek::Email.3 WWW::Search::Infoseek::News.3 \
		WWW::Search::Infoseek::Web.3 WWW::Search::Lycos.3 \
		WWW::Search::Magellan.3 WWW::Search::PLweb.3 \
		WWW::Search::SFgate.3 WWW::Search::WebCrawler.3 \
		WWW::Search::Yahoo.3 WWW::SearchResult.3 \
		WWW::Search::Infoseek::Companies.3 WWW::Search::Verity.3 \
		WWW::Search::Gopher.3 WWW::Search::Simple.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
