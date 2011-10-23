# Ports collection makefile for:	p5-Catalyst-Runtime
# Date created:			Jul 8, 2006
# Whom:				lbr
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Runtime
PORTVERSION=	5.90005
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The Elegant MVC Web Application Framework (Runtime)

RUN_DEPENDS=	p5-B-Hooks-EndOfScope>=0.08:${PORTSDIR}/devel/p5-B-Hooks-EndOfScope \
		p5-CGI-Simple>=1.109:${PORTSDIR}/www/p5-CGI-Simple \
		p5-Class-C3-Adopt-NEXT>=0.07:${PORTSDIR}/devel/p5-Class-C3-Adopt-NEXT \
		p5-Class-Load>=0.08:${PORTSDIR}/devel/p5-Class-Load \
		p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Data-OptList>=0:${PORTSDIR}/devel/p5-Data-OptList \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTTP-Body>=1.06:${PORTSDIR}/www/p5-HTTP-Body \
		p5-HTTP-Request-AsCGI>=1.0:${PORTSDIR}/www/p5-HTTP-Request-AsCGI \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Emulate-Class-Accessor-Fast>=0.00903:${PORTSDIR}/devel/p5-MooseX-Emulate-Class-Accessor-Fast \
		p5-MooseX-Getopt>=0.30:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-MooseX-MethodAttributes>=0.24:${PORTSDIR}/devel/p5-MooseX-MethodAttributes \
		p5-MooseX-Role-WithOverloading>=0.09:${PORTSDIR}/devel/p5-MooseX-Role-WithOverloading \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-MooseX-Types-LoadableClass>=0.003:${PORTSDIR}/devel/p5-MooseX-Types-LoadableClass \
		p5-MooseX-Types-Common>=0:${PORTSDIR}/devel/p5-MooseX-Types-Common \
		p5-Path-Class>=0.09:${PORTSDIR}/devel/p5-Path-Class \
		p5-Plack>=0.9974:${PORTSDIR}/www/p5-Plack \
		p5-Plack-Middleware-ReverseProxy>=0.04:${PORTSDIR}/www/p5-Plack-Middleware-ReverseProxy \
		p5-Plack-Test-ExternalServer>=0:${PORTSDIR}/www/p5-Plack-Test-ExternalServer \
		p5-String-RewritePrefix>=0.004:${PORTSDIR}/textproc/p5-String-RewritePrefix \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-Text-SimpleTable>=0.03:${PORTSDIR}/textproc/p5-Text-SimpleTable \
		p5-Tree-Simple>=1.15:${PORTSDIR}/devel/p5-Tree-Simple \
		p5-Tree-Simple-VisitorFactory>=0:${PORTSDIR}/devel/p5-Tree-Simple-VisitorFactory \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-namespace-autoclean>=0.09:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-namespace-clean>=0.13:${PORTSDIR}/devel/p5-namespace-clean
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN1=	catalyst.pl.1
MAN3=	Catalyst.3 \
	Catalyst::Action.3 \
	Catalyst::ActionChain.3 \
	Catalyst::ActionContainer.3 \
	Catalyst::Base.3 \
	Catalyst::ClassData.3 \
	Catalyst::Component.3 \
	Catalyst::Component::ApplicationAttribute.3 \
	Catalyst::Component::ContextClosure.3 \
	Catalyst::Controller.3 \
	Catalyst::Delta.3 \
	Catalyst::DispatchType.3 \
	Catalyst::DispatchType::Chained.3 \
	Catalyst::DispatchType::Default.3 \
	Catalyst::DispatchType::Index.3 \
	Catalyst::DispatchType::Path.3 \
	Catalyst::DispatchType::Regex.3 \
	Catalyst::Dispatcher.3 \
	Catalyst::Engine.3 \
	Catalyst::EngineLoader.3 \
	Catalyst::Exception.3 \
	Catalyst::Exception::Basic.3 \
	Catalyst::Exception::Detach.3 \
	Catalyst::Exception::Go.3 \
	Catalyst::Exception::Interface.3 \
	Catalyst::Log.3 \
	Catalyst::Model.3 \
	Catalyst::PSGI.3 \
	Catalyst::Request.3 \
	Catalyst::Request::Upload.3 \
	Catalyst::Response.3 \
	Catalyst::Runtime.3 \
	Catalyst::Script::CGI.3 \
	Catalyst::Script::Create.3 \
	Catalyst::Script::FastCGI.3 \
	Catalyst::Script::Server.3 \
	Catalyst::Script::Test.3 \
	Catalyst::ScriptRole.3 \
	Catalyst::ScriptRunner.3 \
	Catalyst::Stats.3 \
	Catalyst::Test.3 \
	Catalyst::Upgrading.3 \
	Catalyst::Utils.3 \
	Catalyst::View.3

post-install:
	@${CAT} ${PKGDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS+=	p5-Module-Pluggable>=3.9:${PORTSDIR}/devel/p5-Module-Pluggable
.endif

.include <bsd.port.post.mk>
