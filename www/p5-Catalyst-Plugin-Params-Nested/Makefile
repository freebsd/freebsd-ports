# New ports collection makefile for:	www/p5-Catalyst-Plugin-Params-Nested
# Date created:				28 Dec 2006
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Params-Nested
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Nested params (ala Ruby on Rails or PHP-style param arrays)

BUILD_DEPENDS=	p5-CGI-Expand>=1.06:${PORTSDIR}/www/p5-CGI-Expand 
RUN_DEPENDS=	p5-CGI-Expand>=1.06:${PORTSDIR}/www/p5-CGI-Expand \
		p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Plugin::Params::Nested.3 \
	Catalyst::Plugin::Params::Nested::Expander.3

.include <bsd.port.mk>
