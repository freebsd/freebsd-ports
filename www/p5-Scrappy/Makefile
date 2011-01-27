# New ports collection makefile for:	www/p5-Scrappy
# Date created:				27 January 2011
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Scrappy
PORTVERSION=	0.62
CATEGORIES=	www perl5
MASTER_SITES=	CPAN/../../authors/id/A/AW/AWNCORP
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	All Powerful Web Harvester, Spider, Scraper fully automated

BUILD_DEPENDS=	p5-File-ShareDir-Install>=0.03:${PORTSDIR}/devel/p5-File-ShareDir-Install \
		p5-Array-Unique>=0:${PORTSDIR}/devel/p5-Array-Unique \
		p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-Parallel-ForkManager>=0:${PORTSDIR}/devel/p5-Parallel-ForkManager \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-Web-Scraper>=0:${PORTSDIR}/www/p5-Web-Scraper \
		p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Scrappy.3 \
	Scrappy::Crawler.3 \
	Scrappy::Doo.3 \
	Scrappy::Element.3 \
	Scrappy::Manual.3

.include <bsd.port.mk>
