# ex:ts=8
# Ports collection makefile for:	FEAR::API
# Date created:			Jun 5, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	FEAR-API
PORTVERSION=	0.489
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/X/XE/XERN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Web Scraping Zen

RUN_DEPENDS=	p5-Email-Find>=0:${PORTSDIR}/mail/p5-Email-Find \
		p5-Exporter-Lite>=0:${PORTSDIR}/devel/p5-Exporter-Lite \
		p5-File-MMagic>=0:${PORTSDIR}/devel/p5-File-MMagic \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-HTML-Encoding>=0:${PORTSDIR}/www/p5-HTML-Encoding \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-LinkExtractor>=0:${PORTSDIR}/www/p5-HTML-LinkExtractor \
		p5-HTTP-Proxy>=0:${PORTSDIR}/www/p5-HTTP-Proxy \
		p5-HTTP-Recorder>=0:${PORTSDIR}/www/p5-HTTP-Recorder \
		p5-IO-All>=0:${PORTSDIR}/devel/p5-IO-All \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-Inline>=0:${PORTSDIR}/devel/p5-Inline \
		p5-Inline-Files>=0:${PORTSDIR}/devel/p5-Inline-Files \
		p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
		p5-Parallel-ForkManager>=0:${PORTSDIR}/devel/p5-Parallel-ForkManager \
		p5-Regexp-Bind>=0:${PORTSDIR}/devel/p5-Regexp-Bind \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Sort-Versions>=0:${PORTSDIR}/devel/p5-Sort-Versions \
		p5-Spiffy>=0:${PORTSDIR}/devel/p5-Spiffy \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Template-Extract>=0:${PORTSDIR}/textproc/p5-Template-Extract \
		p5-Text-CSV>=0:${PORTSDIR}/textproc/p5-Text-CSV \
		p5-Text-Iconv>=0:${PORTSDIR}/converters/p5-Text-Iconv \
		p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-XML-RSS-SimpleGen>=0:${PORTSDIR}/textproc/p5-XML-RSS-SimpleGen \
		p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	fear.1
MAN3=	FEAR::API.3 \
	FEAR::API::Filters.3 \
	FEAR::API::Document.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
