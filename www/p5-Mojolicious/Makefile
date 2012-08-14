# New ports collection makefile for:	p5-Mojo
# Date created:		2008-12-29
# Whom:			Murilo Opsfelder <mopsfelder@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Mojolicious
PORTVERSION=	3.30
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mopsfelder@gmail.com
COMMENT=	A high level MVC web framework written in Perl

LICENSE=	ART20

BUILD_DEPENDS=	p5-EV>=4:${PORTSDIR}/devel/p5-EV
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	IPV6 TLS
OPTIONS_DEFAULT=IPV6 TLS

PERL_CONFIGURE=	5.10.1+

MAN1=		hypnotoad.1 \
		mojo.1 \
		morbo.1
MAN3=		Mojo.3 \
		Mojo::Asset.3 \
		Mojo::Asset::File.3 \
		Mojo::Asset::Memory.3 \
		Mojo::Base.3 \
		Mojo::ByteStream.3 \
		Mojo::Cache.3 \
		Mojo::Collection.3 \
		Mojo::Content.3 \
		Mojo::Content::MultiPart.3 \
		Mojo::Content::Single.3 \
		Mojo::Cookie.3 \
		Mojo::Cookie::Request.3 \
		Mojo::Cookie::Response.3 \
		Mojo::DOM.3 \
		Mojo::DOM::CSS.3 \
		Mojo::DOM::HTML.3 \
		Mojo::Date.3 \
		Mojo::EventEmitter.3 \
		Mojo::Exception.3 \
		Mojo::Headers.3 \
		Mojo::HelloWorld.3 \
		Mojo::Home.3 \
		Mojo::IOLoop.3 \
		Mojo::IOLoop::Client.3 \
		Mojo::IOLoop::Delay.3 \
		Mojo::IOLoop::Server.3 \
		Mojo::IOLoop::Stream.3 \
		Mojo::JSON.3 \
		Mojo::JSON::Pointer.3 \
		Mojo::Loader.3 \
		Mojo::Log.3 \
		Mojo::Message.3 \
		Mojo::Message::Request.3 \
		Mojo::Message::Response.3 \
		Mojo::Parameters.3 \
		Mojo::Path.3 \
		Mojo::Reactor.3 \
		Mojo::Reactor::EV.3 \
		Mojo::Reactor::Poll.3 \
		Mojo::Server.3 \
		Mojo::Server::CGI.3 \
		Mojo::Server::Daemon.3 \
		Mojo::Server::Hypnotoad.3 \
		Mojo::Server::Morbo.3 \
		Mojo::Server::PSGI.3 \
		Mojo::Template.3 \
		Mojo::Transaction.3 \
		Mojo::Transaction::HTTP.3 \
		Mojo::Transaction::WebSocket.3 \
		Mojo::URL.3 \
		Mojo::Upload.3 \
		Mojo::UserAgent.3 \
		Mojo::UserAgent::CookieJar.3 \
		Mojo::UserAgent::Transactor.3 \
		Mojo::Util.3 \
		Mojolicious.3 \
		Mojolicious::Command.3 \
		Mojolicious::Command::cgi.3 \
		Mojolicious::Command::cpanify.3 \
		Mojolicious::Command::daemon.3 \
		Mojolicious::Command::eval.3 \
		Mojolicious::Command::generate.3 \
		Mojolicious::Command::generate::app.3 \
		Mojolicious::Command::generate::lite_app.3 \
		Mojolicious::Command::generate::makefile.3 \
		Mojolicious::Command::generate::plugin.3 \
		Mojolicious::Command::get.3 \
		Mojolicious::Command::inflate.3 \
		Mojolicious::Command::psgi.3 \
		Mojolicious::Command::routes.3 \
		Mojolicious::Command::test.3 \
		Mojolicious::Command::version.3 \
		Mojolicious::Commands.3 \
		Mojolicious::Controller.3 \
		Mojolicious::Guides.3 \
		Mojolicious::Guides::CodingGuidelines.3 \
		Mojolicious::Guides::Cookbook.3 \
		Mojolicious::Guides::FAQ.3 \
		Mojolicious::Guides::Growing.3 \
		Mojolicious::Guides::Rendering.3 \
		Mojolicious::Guides::Routing.3 \
		Mojolicious::Lite.3 \
		Mojolicious::Plugin.3 \
		Mojolicious::Plugin::Charset.3 \
		Mojolicious::Plugin::Config.3 \
		Mojolicious::Plugin::DefaultHelpers.3 \
		Mojolicious::Plugin::EPLRenderer.3 \
		Mojolicious::Plugin::EPRenderer.3 \
		Mojolicious::Plugin::HeaderCondition.3 \
		Mojolicious::Plugin::JSONConfig.3 \
		Mojolicious::Plugin::Mount.3 \
		Mojolicious::Plugin::PODRenderer.3 \
		Mojolicious::Plugin::PoweredBy.3 \
		Mojolicious::Plugin::RequestTimer.3 \
		Mojolicious::Plugin::TagHelpers.3 \
		Mojolicious::Plugins.3 \
		Mojolicious::Renderer.3 \
		Mojolicious::Routes.3 \
		Mojolicious::Routes::Match.3 \
		Mojolicious::Routes::Pattern.3 \
		Mojolicious::Routes::Route.3 \
		Mojolicious::Sessions.3 \
		Mojolicious::Static.3 \
		Mojolicious::Types.3 \
		README.3 \
		Test::Mojo.3 \
		ojo.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CATEGORIES+=	ipv6
BUILD_DEPENDS+=	p5-IO-Socket-IP>=0.16:${PORTSDIR}/net/p5-IO-Socket-IP
RUN_DEPENDS+=	p5-IO-Socket-IP>=0.16:${PORTSDIR}/net/p5-IO-Socket-IP
.endif

.if ${PORT_OPTIONS:MTLS}
BUILD_DEPENDS+=	p5-IO-Socket-SSL>=1.75:${PORTSDIR}/security/p5-IO-Socket-SSL
RUN_DEPENDS+=	p5-IO-Socket-SSL>=1.75:${PORTSDIR}/security/p5-IO-Socket-SSL
.endif

.include <bsd.port.mk>
