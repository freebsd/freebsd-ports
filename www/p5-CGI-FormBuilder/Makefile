# New ports collection makefile for:	www/p5-CGI-FormBuilder
# Date created:				14 Sep 2006
# Whom:					Fernan Aguero
#
# $FreeBSD$

PORTNAME=	CGI-FormBuilder
PORTVERSION=	3.0501
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NWIGER
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	FormBuilder for CGI

PERL_CONFIGURE=	yes

OPTIONS=	TT		"Template Toolkit support" on \
		HTML_TEMPLATE	"HTML::Template support" off \
		TEXT_TEMPLATE	"Text::Template support" off \
		CGI_FAST_TEMPLATE "CGI::FastTemplate support" off

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

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_TT)
RUN_DEPENDS+=	p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit
.endif

.if defined(WITH_HTML_TEMPLATE)
RUN_DEPENDS+=	p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template
.endif

.if defined(WITH_TEXT_TEMPLATE)
RUN_DEPENDS+=	p5-Text-Template>=0:${PORTSDIR}/textproc/p5-Text-Template
.endif

.if defined(WITH_CGI_FAST_TEMPLATE)
RUN_DEPENDS+=	p5-CGI-FastTemplate>=0:${PORTSDIR}/www/p5-CGI-FastTemplate
.endif

.include <bsd.port.post.mk>
