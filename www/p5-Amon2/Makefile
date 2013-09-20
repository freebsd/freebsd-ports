# $FreeBSD$

PORTNAME=	Amon2
PORTVERSION=	3.85
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for/to lightweight web application framework

RUN_DEPENDS=	\
	p5-Plack>=0.9982:${PORTSDIR}/www/p5-Plack \
	p5-Plack-Middleware-Session>0:${PORTSDIR}/www/p5-Plack-Middleware-Session \
	p5-Router-Simple>=0.14:${PORTSDIR}/www/p5-Router-Simple \
	p5-Router-Simple-Sinatraish>=0.02:${PORTSDIR}/www/p5-Router-Simple-Sinatraish \
	p5-Text-Xslate>=1.6001:${PORTSDIR}/textproc/p5-Text-Xslate \
	p5-Try-Tiny>=0.06:${PORTSDIR}/lang/p5-Try-Tiny \
	p5-URI>=1.54:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires

USES=	perl5
USE_PERL5=	modbuild

MAN1=	amon2-setup.pl.1
MAN3=	Amon2.3 \
	Amon2::Config::Simple.3 \
	Amon2::Declare.3 \
	Amon2::Plugin::Web::CSRFDefender.3 \
	Amon2::Plugin::Web::FillInFormLite.3 \
	Amon2::Plugin::Web::HTTPSession.3 \
	Amon2::Plugin::Web::JSON.3 \
	Amon2::Plugin::Web::NoCache.3 \
	Amon2::Plugin::Web::PlackSession.3 \
	Amon2::Plugin::Web::Streaming.3 \
	Amon2::Plugin::Web::WebSocket.3 \
	Amon2::Setup::Flavor.3 \
	Amon2::Setup::Flavor::Basic.3 \
	Amon2::Setup::Flavor::Large.3 \
	Amon2::Setup::Flavor::Minimum.3 \
	Amon2::Trigger.3 \
	Amon2::Util.3 \
	Amon2::Web.3 \
	Amon2::Web::Dispatcher::Lite.3 \
	Amon2::Web::Dispatcher::RouterSimple.3 \
	Amon2::Web::Request.3 \
	Amon2::Web::Response.3 \
	Amon2::Web::Response::Callback.3 \
	Amon2::Web::WebSocket.3

NO_STAGE=	yes
.include <bsd.port.mk>
