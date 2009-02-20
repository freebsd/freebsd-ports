# New ports collection makefile for:	HTTP::Engine::Middleware
# Date created:		20 Feb 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Engine-Middleware
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for official distribution of HTTP::Engine

RUN_DEPENDS=	\
	p5-HTTP-Engine>=0.1.3:${PORTSDIR}/www/p5-HTTP-Engine \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	HTTP::Engine::Middleware.3 \
	HTTP::Engine::Middleware::DebugRequest.3 \
	HTTP::Engine::Middleware::DebugScreen.3 \
	HTTP::Engine::Middleware::DoCoMoGUID.3 \
	HTTP::Engine::Middleware::Encode.3 \
	HTTP::Engine::Middleware::FillInForm.3 \
	HTTP::Engine::Middleware::HTTPSession.3 \
	HTTP::Engine::Middleware::MethodOverride.3 \
	HTTP::Engine::Middleware::MobileAttribute.3 \
	HTTP::Engine::Middleware::ModuleReload.3 \
	HTTP::Engine::Middleware::Profile.3 \
	HTTP::Engine::Middleware::ReverseProxy.3 \
	HTTP::Engine::Middleware::Static.3

.include <bsd.port.mk>
