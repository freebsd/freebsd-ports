# $FreeBSD$

PORTNAME=	Tiffany
PORTVERSION=	1.00
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for generic interface for Perl5 template engines

TEST_DEPENDS=	\
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Text-Xslate>0:${PORTSDIR}/textproc/p5-Text-Xslate \
	p5-Template-Toolkit>0:${PORTSDIR}/www/p5-Template-Toolkit \
	p5-HTML-Template>0:${PORTSDIR}/www/p5-HTML-Template \
	p5-Text-MicroTemplate>0:${PORTSDIR}/textproc/p5-Text-MicroTemplate \
	p5-Template-Semantic>0:${PORTSDIR}/textproc/p5-Template-Semantic \
	p5-Text-MicroMason>0:${PORTSDIR}/textproc/p5-Text-MicroMason \
	p5-Template-Declare>0:${PORTSDIR}/textproc/p5-Template-Declare \
	p5-Text-MicroTemplate-Extended>0:${PORTSDIR}/textproc/p5-Text-MicroTemplate-Extended \
	p5-Text-ClearSilver>0:${PORTSDIR}/textproc/p5-Text-ClearSilver \
	p5-HTML-Template-Pro>0:${PORTSDIR}/www/p5-HTML-Template-Pro

PERL_MODBUILD=	yes

MAN3=	Tiffany.3 \
	Tiffany::HTML::Template.3 \
	Tiffany::HTML::Template::Pro.3 \
	Tiffany::TT.3 \
	Tiffany::Template::Declare.3 \
	Tiffany::Template::Semantic.3 \
	Tiffany::Text::ClearSilver.3 \
	Tiffany::Text::MicroMason.3 \
	Tiffany::Text::MicroTemplate::Extended.3 \
	Tiffany::Text::MicroTemplate::File.3 \
	Tiffany::Text::Xslate.3

.include <bsd.port.mk>
