# New ports collection makefile for:    p5-WWW-Search
# Date created:				June 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Search
PORTVERSION=	2.10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree

PERL_CONFIGURE=	yes

MAN1=		AutoSearch.1 \
		WebSearch.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		WWW::Search.3 \
		WWW::Search::AOL::Classifieds::Employment.3 \
		WWW::Search::AltaVista.3 \
		WWW::Search::AltaVista::AdvancedNews.3 \
		WWW::Search::AltaVista::AdvancedWeb.3 \
		WWW::Search::AltaVista::Careers.3 \
		WWW::Search::AltaVista::Intranet.3 \
		WWW::Search::AltaVista::News.3 \
		WWW::Search::AltaVista::Web.3 \
		WWW::Search::Crawler.3 \
		WWW::Search::Dice.3 \
		WWW::Search::Euroseek.3 \
		WWW::Search::Excite::News.3 \
		WWW::Search::ExciteForWebServers.3 \
		WWW::Search::Fireball.3 \
		WWW::Search::FolioViews.3 \
		WWW::Search::GoTo.3 \
		WWW::Search::Google.3 \
		WWW::Search::Gopher.3 \
		WWW::Search::HeadHunter.3 \
		WWW::Search::HotFiles.3 \
		WWW::Search::Infoseek.3 \
		WWW::Search::Infoseek::Companies.3 \
		WWW::Search::Infoseek::Email.3 \
		WWW::Search::Infoseek::News.3 \
		WWW::Search::Infoseek::Web.3 \
		WWW::Search::Livelink.3 \
		WWW::Search::LookSmart.3 \
		WWW::Search::Lycos.3 \
		WWW::Search::Lycos::Pages.3 \
		WWW::Search::Lycos::Sites.3 \
		WWW::Search::MSIndexServer.3 \
		WWW::Search::Magellan.3 \
		WWW::Search::MetaCrawler.3 \
		WWW::Search::Metapedia.3 \
		WWW::Search::Monster.3 \
		WWW::Search::NetFind.3 \
		WWW::Search::NorthernLight.3 \
		WWW::Search::Null.3 \
		WWW::Search::OpenDirectory.3 \
		WWW::Search::PLweb.3 \
		WWW::Search::SFgate.3 \
		WWW::Search::Search97.3 \
		WWW::Search::Simple.3 \
		WWW::Search::Snap.3 \
		WWW::Search::Test.3 \
		WWW::Search::Verity.3 \
		WWW::Search::WebCrawler.3 \
		WWW::Search::Yahoo::Classifieds::Employment.3 \
		WWW::Search::ZDNet.3 \
		WWW::SearchResult.3

.include <bsd.port.mk>
