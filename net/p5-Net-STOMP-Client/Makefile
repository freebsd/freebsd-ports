# $FreeBSD$

PORTNAME=	Net-STOMP-Client
PORTVERSION=	2.0
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Streaming Text Orientated Messaging Protocol Client

BUILD_DEPENDS=	p5-No-Worries>=0:${PORTSDIR}/devel/p5-No-Worries \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PERL_CONFIGURE=	yes

MAN3=	Net::STOMP::Client.3 \
	Net::STOMP::Client::Auth.3 \
	Net::STOMP::Client::Connection.3 \
	Net::STOMP::Client::Frame.3 \
	Net::STOMP::Client::HeartBeat.3 \
	Net::STOMP::Client::IO.3 \
	Net::STOMP::Client::Peer.3 \
	Net::STOMP::Client::Receipt.3 \
	Net::STOMP::Client::Tutorial.3 \
	Net::STOMP::Client::Version.3

.include <bsd.port.mk>
