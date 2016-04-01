# Created by: Fernan Aguero
# $FreeBSD$

PORTNAME=	CGI-FormBuilder
PORTVERSION=	3.0900
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/00$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	FormBuilder for CGI

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USE_PERL5=	configure
USES=		perl5 tar:tgz

# Follow upstream order in Makefile.PL
OPTIONS_DEFINE=	HTML_TEMPLATE TEXT_TEMPLATE TEMPLATE CGI_FAST_TEMPLATE CGI_SSI CGI_SESSION
OPTIONS_DEFAULT=HTML_TEMPLATE
NO_OPTIONS_SORT=yes
CGI_FAST_TEMPLATE_DESC=	CGI::FastTemplate support
CGI_SESSION_DESC=	CGI::Session support
CGI_SSI_DESC=		CGI::SSI support
HTML_TEMPLATE_DESC=	HTML::Template support
TEXT_TEMPLATE_DESC=	Text::Template support
TEMPLATE_DESC=		Template Toolkit support

CGI_FAST_TEMPLATE_BUILD_DEPENDS=p5-CGI-FastTemplate>=1.09:www/p5-CGI-FastTemplate
CGI_FAST_TEMPLATE_RUN_DEPENDS=	p5-CGI-FastTemplate>=1.09:www/p5-CGI-FastTemplate
CGI_SESSION_BUILD_DEPENDS=	p5-CGI-Session>=3.95:www/p5-CGI-Session
CGI_SESSION_RUN_DEPENDS=p5-CGI-Session>=3.95:www/p5-CGI-Session
CGI_SSI_BUILD_DEPENDS=	p5-CGI-SSI>=0.92:www/p5-CGI-SSI
CGI_SSI_RUN_DEPENDS=	p5-CGI-SSI>=0.92:www/p5-CGI-SSI
HTML_TEMPLATE_BUILD_DEPENDS=	p5-HTML-Template>=2.06:www/p5-HTML-Template
HTML_TEMPLATE_RUN_DEPENDS=	p5-HTML-Template>=2.06:www/p5-HTML-Template
TEXT_TEMPLATE_BUILD_DEPENDS=	p5-Text-Template>=1.43:textproc/p5-Text-Template
TEXT_TEMPLATE_RUN_DEPENDS=	p5-Text-Template>=1.43:textproc/p5-Text-Template
TEMPLATE_BUILD_DEPENDS=	p5-Template-Toolkit>=2.08:www/p5-Template-Toolkit
TEMPLATE_RUN_DEPENDS=	p5-Template-Toolkit>=2.08:www/p5-Template-Toolkit

.include <bsd.port.mk>
