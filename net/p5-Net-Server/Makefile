# New ports collection makefile for:	p5-Net-Server
# Date created:				24 Apr 2001
# Whom:					Jesse McConnell <jesse@gallup.com>
#
# $FreeBSD$
#

PORTNAME=	Net-Server
PORTVERSION=	0.83
CATEGORIES=	net perl5
MASTER_SITES=	http://www.seamons.com/net_server/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	jesse@gallup.com

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::Server.3 \
		Net::Server::Daemonize.3\
		Net::Server::Fork.3 \
		Net::Server::INET.3 \
		Net::Server::MultiType.3 \
		Net::Server::PreFork.3 \
		Net::Server::PreForkSimple.3\
		Net::Server::Proto.3\
		Net::Server::Proto::SSL.3\
		Net::Server::Proto::TCP.3\
		Net::Server::Proto::UDP.3\
		Net::Server::Proto::UNIX.3\
		Net::Server::SIG.3\
		Net::Server::Single.3

.include <bsd.port.mk>
