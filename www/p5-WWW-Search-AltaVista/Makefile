# New ports collection makefile for:	p5-WWW-Search-AltaVista
# Date created:				24 August 2001
# Whom:					Fanying Jen <fanying@fynet.com>
#
# $FreeBSD$
#

PORTNAME=	WWW-Search-AltaVista
PORTVERSION=	2.08
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW/MTHURN
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/WWW/Search.pm:${PORTSDIR}/www/p5-WWW-Search
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		WWW::Search::AltaVista.3 \
		WWW::Search::AltaVista::Web.3 \
		WWW::Search::AltaVista::NL.3 \
		WWW::Search::AltaVista::AdvancedNews.3 \
		WWW::Search::AltaVista::AdvancedWeb.3 \
		WWW::Search::AltaVista::News.3 \
		WWW::Search::AltaVista::Intranet.3 \
		WWW::Search::AltaVista::Intranet3.3
.include <bsd.port.mk>
