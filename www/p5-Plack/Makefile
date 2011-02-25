# New ports collection makefile for:	Plack
# Date created:		13 Oct 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack
PORTVERSION=	0.9972
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of PSGI reference implementation and utilities

RUN_DEPENDS=	\
	p5-Devel-StackTrace>=1.23:${PORTSDIR}/devel/p5-Devel-StackTrace \
	p5-Devel-StackTrace-AsHTML>=0.11:${PORTSDIR}/devel/p5-Devel-StackTrace-AsHTML \
	p5-File-ShareDir>=1.00:${PORTSDIR}/devel/p5-File-ShareDir \
	p5-Filesys-Notify-Simple>0:${PORTSDIR}/devel/p5-Filesys-Notify-Simple \
	p5-HTTP-Body>=1.06:${PORTSDIR}/www/p5-HTTP-Body \
	p5-Hash-MultiValue>=0.05:${PORTSDIR}/devel/p5-Hash-MultiValue \
	p5-Path-Class>0:${PORTSDIR}/devel/p5-Path-Class \
	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny \
	p5-libwww>=5.814:${PORTSDIR}/www/p5-libwww \
	p5-URI>0:${PORTSDIR}/net/p5-URI \
	p5-parent>0:${PORTSDIR}/devel/p5-parent
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	plackup.1
MAN3=	HTTP::Message::PSGI.3 \
	HTTP::Server::PSGI.3 \
	Plack.3 \
	Plack::App::CGIBin.3 \
	Plack::App::Cascade.3 \
	Plack::App::Directory.3 \
	Plack::App::FCGIDispatcher.3 \
	Plack::App::File.3 \
	Plack::App::PSGIBin.3 \
	Plack::App::URLMap.3 \
	Plack::App::WrapCGI.3 \
	Plack::Builder.3 \
	Plack::Component.3 \
	Plack::HTTPParser.3 \
	Plack::HTTPParser::PP.3 \
	Plack::Handler.3 \
	Plack::Handler::Apache1.3 \
	Plack::Handler::Apache2.3 \
	Plack::Handler::Apache2::Registry.3 \
	Plack::Handler::CGI.3 \
	Plack::Handler::FCGI.3 \
	Plack::Handler::HTTP::Server::PSGI.3 \
	Plack::Handler::HTTP::Server::Simple.3 \
	Plack::Handler::Standalone.3 \
	Plack::Loader.3 \
	Plack::Loader::Delayed.3 \
	Plack::Loader::Restarter.3 \
	Plack::Loader::Shotgun.3 \
	Plack::MIME.3 \
	Plack::Middleware.3 \
	Plack::Middleware::AccessLog.3 \
	Plack::Middleware::AccessLog::Timed.3 \
	Plack::Middleware::Auth::Basic.3 \
	Plack::Middleware::BufferedStreaming.3 \
	Plack::Middleware::Chunked.3 \
	Plack::Middleware::Conditional.3 \
	Plack::Middleware::ConditionalGET.3 \
	Plack::Middleware::ContentLength.3 \
	Plack::Middleware::ContentMD5.3 \
	Plack::Middleware::ErrorDocument.3 \
	Plack::Middleware::HTTPExceptions.3 \
	Plack::Middleware::Head.3 \
	Plack::Middleware::JSONP.3 \
	Plack::Middleware::LighttpdScriptNameFix.3 \
	Plack::Middleware::Lint.3 \
	Plack::Middleware::Log4perl.3 \
	Plack::Middleware::LogDispatch.3 \
	Plack::Middleware::NullLogger.3 \
	Plack::Middleware::RearrangeHeaders.3 \
	Plack::Middleware::Recursive.3 \
	Plack::Middleware::Refresh.3 \
	Plack::Middleware::Runtime.3 \
	Plack::Middleware::SimpleContentFilter.3 \
	Plack::Middleware::SimpleLogger.3 \
	Plack::Middleware::StackTrace.3 \
	Plack::Middleware::Static.3 \
	Plack::Middleware::Writer.3 \
	Plack::Middleware::XFramework.3 \
	Plack::Middleware::XSendfile.3 \
	Plack::Request.3 \
	Plack::Request::Upload.3 \
	Plack::Response.3 \
	Plack::Runner.3 \
	Plack::Server.3 \
	Plack::Server::Apache1.3 \
	Plack::Server::Apache2.3 \
	Plack::Server::CGI.3 \
	Plack::Server::FCGI.3 \
	Plack::Server::ServerSimple.3 \
	Plack::Server::Standalone.3 \
	Plack::Server::Standalone::Prefork.3 \
	Plack::TempBuffer.3 \
	Plack::Test.3 \
	Plack::Test::MockHTTP.3 \
	Plack::Test::Server.3 \
	Plack::Test::Suite.3 \
	Plack::Util.3 \
	Plack::Util::Accessor.3

post-extract:
	${RM} ${WRKSRC}/share/\#foo

.include <bsd.port.mk>
