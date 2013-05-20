# Created by:	Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	RPC-ExtDirect
PORTVERSION=	2.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Perl extension for implimenting the Ext.Direct remoting protocol

BUILD_DEPENDS=	p5-Attribute-Handlers>=0.93:${PORTSDIR}/devel/p5-Attribute-Handlers \
		p5-JSON>=2.53:${PORTSDIR}/converters/p5-JSON
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1.46:${PORTSDIR}/devel/p5-Test-Pod

PERL_CONFIGURE=	yes

MAN3=		RPC::ExtDirect.3 \
		RPC::ExtDirect::API.3 \
		RPC::ExtDirect::Config.3 \
		RPC::ExtDirect::Demo::PollProvider.3 \
		RPC::ExtDirect::Demo::Profile.3 \
		RPC::ExtDirect::Demo::TestAction.3 \
		RPC::ExtDirect::Deserialize.3 \
		RPC::ExtDirect::Event.3 \
		RPC::ExtDirect::EventProvider.3 \
		RPC::ExtDirect::Exception.3 \
		RPC::ExtDirect::Hook.3 \
		RPC::ExtDirect::NoEvents.3 \
		RPC::ExtDirect::Request.3 \
		RPC::ExtDirect::Router.3 \
		RPC::ExtDirect::Serialize.3

.include <bsd.port.mk>
