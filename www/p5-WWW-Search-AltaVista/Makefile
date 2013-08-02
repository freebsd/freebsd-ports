# Created by: Fanying Jen <fanying@fynet.com>
# $FreeBSD$

PORTNAME=	WWW-Search-AltaVista
PORTVERSION=	2.154
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl WWW::Search class for searching AltaVista

BUILD_DEPENDS=	p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-WWW-Search>=0:${PORTSDIR}/www/p5-WWW-Search
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		WWW::Search::AltaVista.3 \
		WWW::Search::AltaVista::Web.3 \
		WWW::Search::AltaVista::DE.3 \
		WWW::Search::AltaVista::NL.3 \
		WWW::Search::AltaVista::AdvancedNews.3 \
		WWW::Search::AltaVista::AdvancedWeb.3 \
		WWW::Search::AltaVista::Careers.3 \
		WWW::Search::AltaVista::News.3 \
		WWW::Search::AltaVista::Intranet.3 \
		WWW::Search::AltaVista::Intranet3.3

.include <bsd.port.mk>
