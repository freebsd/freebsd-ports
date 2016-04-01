# Created by: ijliao
# $FreeBSD$

PORTNAME=	FEAR-API
PORTVERSION=	0.489
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:XERN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Web Scraping Zen

LICENSE=	ARTPERL10

BUILD_DEPENDS=	p5-Email-Find>=0:mail/p5-Email-Find \
		p5-Exporter-Lite>=0:devel/p5-Exporter-Lite \
		p5-File-MMagic>=0:devel/p5-File-MMagic \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-HTML-Encoding>=0:www/p5-HTML-Encoding \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTML-LinkExtractor>=0:www/p5-HTML-LinkExtractor \
		p5-HTTP-Proxy>=0:www/p5-HTTP-Proxy \
		p5-HTTP-Recorder>=0:www/p5-HTTP-Recorder \
		p5-IO-All>=0:devel/p5-IO-All \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-Inline>=0:devel/p5-Inline \
		p5-Inline-Files>=0:devel/p5-Inline-Files \
		p5-Net-Server>=0:net/p5-Net-Server \
		p5-Parallel-ForkManager>=0:devel/p5-Parallel-ForkManager \
		p5-Regexp-Bind>=0:devel/p5-Regexp-Bind \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-Sort-Versions>=0:devel/p5-Sort-Versions \
		p5-Spiffy>=0:devel/p5-Spiffy \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-Template-Extract>=0:textproc/p5-Template-Extract \
		p5-Text-CSV>=0:textproc/p5-Text-CSV \
		p5-Text-Iconv>=0:converters/p5-Text-Iconv \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize \
		p5-XML-RSS-SimpleGen>=0:textproc/p5-XML-RSS-SimpleGen \
		p5-XML-XPath>=0:textproc/p5-XML-XPath \
		p5-YAML>=0:textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
