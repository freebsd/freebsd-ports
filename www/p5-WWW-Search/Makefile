# New ports collection makefile for:    p5-WWW-Search
# Date created:				June 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Search
PORTVERSION=	2.26
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI.pm:${PORTSDIR}/net/p5-URI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		AutoSearch.1 \
		WebSearch.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		WWW::Search.3 \
		WWW::Search::Crawler.3 \
		WWW::Search::Excite::News.3 \
		WWW::Search::ExciteForWebServers.3 \
		WWW::Search::Fireball.3 \
		WWW::Search::FolioViews.3 \
		WWW::Search::Gopher.3 \
		WWW::Search::HotFiles.3 \
		WWW::Search::Livelink.3 \
		WWW::Search::MSIndexServer.3 \
		WWW::Search::MetaCrawler.3 \
		WWW::Search::Metapedia.3 \
		WWW::Search::NetFind.3 \
		WWW::Search::Null.3 \
		WWW::Search::PLweb.3 \
		WWW::Search::SFgate.3 \
		WWW::Search::Search97.3 \
		WWW::Search::Simple.3 \
		WWW::Search::Test.3 \
		WWW::Search::Verity.3 \
		WWW::Search::VoilaFr.3 \
		WWW::SearchResult.3

.include <bsd.port.mk>
