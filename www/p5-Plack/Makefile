# New ports collection makefile for:	Plack
# Date created:		13 Oct 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack
PORTVERSION=	0.9001
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of PSGI reference implementation and utilities

RUN_DEPENDS=	\
	p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
	p5-Devel-StackTrace>0:${PORTSDIR}/devel/p5-Devel-StackTrace \
	p5-Devel-StackTrace-AsHTML>0:${PORTSDIR}/devel/p5-Devel-StackTrace-AsHTML \
	p5-File-ShareDir>0:${PORTSDIR}/devel/p5-File-ShareDir \
	p5-HTTP-Request-AsCGI>=0.9:${PORTSDIR}/www/p5-HTTP-Request-AsCGI \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-MIME-Types>0:${PORTSDIR}/mail/p5-MIME-Types \
	p5-Path-Class>0:${PORTSDIR}/devel/p5-Path-Class \
	p5-URI>0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	plackup.1
MAN3=	HTTP::Message::PSGI.3 \
	Plack.3 \
	Plack::App::Directory.3 \
	Plack::App::FCGIDispatcher.3 \
	Plack::App::File.3 \
	Plack::App::URLMap.3 \
	Plack::Builder.3 \
	Plack::HTTPParser.3 \
	Plack::HTTPParser::PP.3 \
	Plack::Loader.3 \
	Plack::Middleware.3 \
	Plack::Middleware::AccessLog.3 \
	Plack::Middleware::AccessLog::Timed.3 \
	Plack::Middleware::ConditionalGET.3 \
	Plack::Middleware::ContentLength.3 \
	Plack::Middleware::ErrorDocument.3 \
	Plack::Middleware::Lint.3 \
	Plack::Middleware::MethodOverride.3 \
	Plack::Middleware::RearrangeHeaders.3 \
	Plack::Middleware::Restarter.3 \
	Plack::Middleware::SimpleContentFilter.3 \
	Plack::Middleware::StackTrace.3 \
	Plack::Middleware::Static.3 \
	Plack::Middleware::XFramework.3 \
	Plack::Middleware::XSendfile.3 \
	Plack::Server.3 \
	Plack::Server::Apache2.3 \
	Plack::Server::CGI.3 \
	Plack::Server::FCGI.3 \
	Plack::Server::Standalone.3 \
	Plack::Server::Standalone::Prefork.3 \
	Plack::Test.3 \
	Plack::Test::MockHTTP.3 \
	Plack::Test::Server.3 \
	Plack::Test::Suite.3 \
	Plack::Util.3

.include <bsd.port.mk>
