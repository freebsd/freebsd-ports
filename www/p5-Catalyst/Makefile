# ex:ts=8
# Ports collection makefile for:	p5-Catalyst
# Date created:			Apr 7, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Catalyst
PORTVERSION=	4.34
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/SR/SRI
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Elegant MVC Web Application Framework

BUILD_DEPENDS=	${SITE_PERL}/CGI/Simple.pm:${PORTSDIR}/www/p5-CGI-Simple \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/HTTP/Headers.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/HTTP/Server/Simple.pm:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		${SITE_PERL}/Module/Pluggable/Fast.pm:${PORTSDIR}/devel/p5-Module-Pluggable-Fast \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-exports
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	catalyst.pl.1
MAN3=	Catalyst.3 \
	Catalyst::Base.3 \
	Catalyst::Engine.3 \
	Catalyst::Engine::Apache.3 \
	Catalyst::Engine::CGI.3 \
	Catalyst::Engine::CGI::NPH.3 \
	Catalyst::Engine::FCGI.3 \
	Catalyst::Engine::Server.3 \
	Catalyst::Engine::Test.3 \
	Catalyst::Helper.3 \
	Catalyst::Log.3 \
	Catalyst::Manual.3 \
	Catalyst::Manual::Cookbook.3 \
	Catalyst::Manual::FAQ.3 \
	Catalyst::Manual::Internals.3 \
	Catalyst::Manual::Intro.3 \
	Catalyst::Manual::SuccessStories.3 \
	Catalyst::Manual::Troubleshooting.3 \
	Catalyst::Manual::Tutorial.3 \
	Catalyst::Request.3 \
	Catalyst::Response.3 \
	Catalyst::Test.3

.include <bsd.port.mk>
