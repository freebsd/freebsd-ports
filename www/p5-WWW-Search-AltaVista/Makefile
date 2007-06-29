# New ports collection makefile for:	p5-WWW-Search-AltaVista
# Date created:				24 August 2001
# Whom:					Fanying Jen <fanying@fynet.com>
#
# $FreeBSD$
#

PORTNAME=	WWW-Search-AltaVista
PORTVERSION=	2.146
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl WWW::Search class for searching AltaVista

BUILD_DEPENDS=	${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/WWW/Search.pm:${PORTSDIR}/www/p5-WWW-Search
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6 or newer. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
