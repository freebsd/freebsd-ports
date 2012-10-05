# Created by: Fernan Aguero
# $FreeBSD$

PORTNAME=	CGI-FormBuilder
PORTVERSION=	3.0501
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NWIGER
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FormBuilder for CGI

PERL_CONFIGURE=	yes

OPTIONS_DEFINE=	TT HTML_TEMPLATE TEXT_TEMPLATE CGI_FAST_TEMPLATE
OPTIONS_DEFAULT=	TT
TT_DESC=	Template Toolkit support
HTML_TEMPLATE_DESC=	HTML::Template support
TEXT_TEMPLATE_DESC=	Text::Template support
CGI_FAST_TEMPLATE_DESC=	CGI::FastTemplate suppor

MAN3=	CGI::FormBuilder.3 \
	CGI::FormBuilder::Template::Builtin.3 \
	CGI::FormBuilder::Template::Div.3 \
	CGI::FormBuilder::Template::HTML.3 \
	CGI::FormBuilder::Source::File.3 \
	CGI::FormBuilder::Template.3 \
	CGI::FormBuilder::Multi.3 \
	CGI::FormBuilder::Template::TT2.3 \
	CGI::FormBuilder::Test.3 \
	CGI::FormBuilder::Util.3 \
	CGI::FormBuilder::Template::Text.3 \
	CGI::FormBuilder::Source.3 \
	CGI::FormBuilder::Field.3 \
	CGI::FormBuilder::Template::Fast.3 \
	CGI::FormBuilder::Messages.3

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTT}
RUN_DEPENDS+=	p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit
.endif

.if ${PORT_OPTIONS:MHTML_TEMPLATE}
RUN_DEPENDS+=	p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template
.endif

.if ${PORT_OPTIONS:MTEXT_TEMPLATE}
RUN_DEPENDS+=	p5-Text-Template>=0:${PORTSDIR}/textproc/p5-Text-Template
.endif

.if ${PORT_OPTIONS:MCGI_FAST_TEMPLATE}
RUN_DEPENDS+=	p5-CGI-FastTemplate>=0:${PORTSDIR}/www/p5-CGI-FastTemplate
.endif

.include <bsd.port.mk>
