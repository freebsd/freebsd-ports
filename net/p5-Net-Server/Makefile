# Created by: Jesse McConnell <jesse@gallup.com>
# $FreeBSD$

PORTNAME=	Net-Server
PORTVERSION=	2.007
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A configurable base class for writing internet servers in Perl

BUILD_DEPENDS=	p5-IO-Multiplex>=1.01:${PORTSDIR}/devel/p5-IO-Multiplex
RUN_DEPENDS=	p5-IO-Multiplex>=1.01:${PORTSDIR}/devel/p5-IO-Multiplex

OPTIONS_DEFINE=	IPV6

PERL_CONFIGURE=	yes

MAN1=		net-server.1
MAN3=		Net::Server.3 \
		Net::Server::Daemonize.3 \
		Net::Server::Fork.3 \
		Net::Server::HTTP.3 \
		Net::Server::INET.3 \
		Net::Server::Log::Log::Log4perl.3 \
		Net::Server::Log::Sys::Syslog.3 \
		Net::Server::MultiType.3 \
		Net::Server::Multiplex.3 \
		Net::Server::PSGI.3 \
		Net::Server::PreFork.3 \
		Net::Server::PreForkSimple.3 \
		Net::Server::Proto.3 \
		Net::Server::Proto::SSL.3 \
		Net::Server::Proto::SSLEAY.3 \
		Net::Server::Proto::TCP.3 \
		Net::Server::Proto::UDP.3 \
		Net::Server::Proto::UNIX.3 \
		Net::Server::Proto::UNIXDGRAM.3 \
		Net::Server::SIG.3 \
		Net::Server::Single.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
BUILD_DEPENDS+=	p5-Socket6>=0.23:${PORTSDIR}/net/p5-Socket6
RUN_DEPENDS+=	p5-Socket6>=0.23:${PORTSDIR}/net/p5-Socket6
.endif

.include <bsd.port.mk>
