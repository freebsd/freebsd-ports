# New ports collection makefile for:    p5-WWW-Search
# Version required:			1.021
# Date created:				June 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	WWW-Search-1.021
PKGNAME=	p5-WWW-Search-1.021
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW

MAINTAINER=	jfitz@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/LWP.pm:${PORTSDIR}/www/p5-libwww

BROKEN=		"installs files in /usr/bin"

USE_PERL5=	YES

MAN1=		AutoSearch.1 \
		WebSearch.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		WWW::Search.3 \
		WWW::Search::AltaVista.3 \
		WWW::Search::AltaVista::AdvancedNews.3 \
		WWW::Search::AltaVista::AdvancedWeb.3 \
		WWW::Search::AltaVista::News.3 \
		WWW::Search::AltaVista::Web.3 \
		WWW::Search::Dejanews.3 \
		WWW::Search::Excite.3 \
		WWW::Search::HotBot.3 \
		WWW::Search::Infoseek.3 \
		WWW::Search::Infoseek::Email.3 \
		WWW::Search::Infoseek::News.3 \
		WWW::Search::Infoseek::Web.3 \
		WWW::Search::Lycos.3 \
		WWW::Search::Magellan.3 \
		WWW::Search::PLweb.3 \
		WWW::Search::SFgate.3 \
		WWW::Search::WebCrawler.3 \
		WWW::Search::Yahoo.3 \
		WWW::SearchResult.3 \
		WWW::Search::Infoseek::Companies.3 \
		WWW::Search::Verity.3 \
		WWW::Search::Gopher.3 \
		WWW::Search::Simple.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300000
BROKEN=         perl
.endif

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.post.mk>
