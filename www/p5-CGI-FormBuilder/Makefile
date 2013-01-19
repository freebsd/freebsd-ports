# Created by: Fernan Aguero
# $FreeBSD$

PORTNAME=	CGI-FormBuilder
PORTVERSION=	3.0800
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S,00$,,}
EXTRACT_SUFX=	.tgz

MAINTAINER=	linpc@cs.nctu.edu.tw
COMMENT=	FormBuilder for CGI

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PERL_CONFIGURE=	yes

OPTIONS_DEFINE=	TT HTML_TEMPLATE TEXT_TEMPLATE CGI_FAST_TEMPLATE CGI_SSI CGI_SESSION
OPTIONS_DEFAULT=	TT
TT_DESC=	Template Toolkit support
HTML_TEMPLATE_DESC=	HTML::Template support
TEXT_TEMPLATE_DESC=	Text::Template support
CGI_FAST_TEMPLATE_DESC=	CGI::FastTemplate support
CGI_SSI_DESC=	CGI::SSI support
CGI_SESSION_DESC=	CGI::Session support

MAN3=	CGI::FormBuilder.3 \
	CGI::FormBuilder::Field.3 \
	CGI::FormBuilder::Messages.3 \
	CGI::FormBuilder::Multi.3 \
	CGI::FormBuilder::Source.3 \
	CGI::FormBuilder::Source::File.3 \
	CGI::FormBuilder::Template.3 \
	CGI::FormBuilder::Template::Builtin.3 \
	CGI::FormBuilder::Template::CGI_SSI.3 \
	CGI::FormBuilder::Template::Div.3 \
	CGI::FormBuilder::Template::Fast.3 \
	CGI::FormBuilder::Template::HTML.3 \
	CGI::FormBuilder::Template::TT2.3 \
	CGI::FormBuilder::Template::Text.3 \
	CGI::FormBuilder::Test.3 \
	CGI::FormBuilder::Util.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTT}
RUN_DEPENDS+=	p5-Template-Toolkit>=2.08:${PORTSDIR}/www/p5-Template-Toolkit
.endif

.if ${PORT_OPTIONS:MHTML_TEMPLATE}
RUN_DEPENDS+=	p5-HTML-Template>=2.06:${PORTSDIR}/www/p5-HTML-Template
.endif

.if ${PORT_OPTIONS:MTEXT_TEMPLATE}
RUN_DEPENDS+=	p5-Text-Template>=1.43:${PORTSDIR}/textproc/p5-Text-Template
.endif

.if ${PORT_OPTIONS:MCGI_FAST_TEMPLATE}
RUN_DEPENDS+=	p5-CGI-FastTemplate>=1.09:${PORTSDIR}/www/p5-CGI-FastTemplate
.endif

.if ${PORT_OPTIONS:MCGI_SSI}
RUN_DEPENDS+=	p5-CGI-SSI>=0.92:${PORTSDIR}/www/p5-CGI-SSI
.endif

.if ${PORT_OPTIONS:MCGI_SESSION}
RUN_DEPENDS+=	p5-CGI-Session>=3.95:${PORTSDIR}/www/p5-CGI-Session
.endif

.include <bsd.port.mk>
