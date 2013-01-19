# $FreeBSD$

PORTNAME=	Text-MicroMason
PORTVERSION=	2.13
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for simple and extensible templating

RUN_DEPENDS=	\
	p5-Class-MixinFactory>=0.9:${PORTSDIR}/devel/p5-Class-MixinFactory
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Text::MicroMason.3 \
	Text::MicroMason::AllowGlobals.3 \
	Text::MicroMason::ApacheHandler.3 \
	Text::MicroMason::Base.3 \
	Text::MicroMason::Cache::File.3 \
	Text::MicroMason::Cache::Null.3 \
	Text::MicroMason::Cache::Simple.3 \
	Text::MicroMason::CatchErrors.3 \
	Text::MicroMason::CompileCache.3 \
	Text::MicroMason::Debug.3 \
	Text::MicroMason::Docs::Changes.3 \
	Text::MicroMason::Docs::ReadMe.3 \
	Text::MicroMason::Docs::Related.3 \
	Text::MicroMason::Docs::ToDo.3 \
	Text::MicroMason::DoubleQuote.3 \
	Text::MicroMason::Embperl.3 \
	Text::MicroMason::ExecuteCache.3 \
	Text::MicroMason::Filters.3 \
	Text::MicroMason::Functions.3 \
	Text::MicroMason::HTMLMason.3 \
	Text::MicroMason::HTMLTemplate.3 \
	Text::MicroMason::HasParams.3 \
	Text::MicroMason::LineNumbers.3 \
	Text::MicroMason::PLP.3 \
	Text::MicroMason::PassVariables.3 \
	Text::MicroMason::PostProcess.3 \
	Text::MicroMason::QuickTemplate.3 \
	Text::MicroMason::Safe.3 \
	Text::MicroMason::ServerPages.3 \
	Text::MicroMason::Sprintf.3 \
	Text::MicroMason::StoreOne.3 \
	Text::MicroMason::TemplateDir.3 \
	Text::MicroMason::TemplatePath.3 \
	Text::MicroMason::TextTemplate.3

.include <bsd.port.mk>
