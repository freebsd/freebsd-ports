# New ports collection makefile for:	p5-Net-Server
# Date created:				24 Apr 2001
# Whom:					Jesse McConnell <jesse@gallup.com>
#
# $FreeBSD$
#

PORTNAME=	Net-Server
PORTVERSION=	0.96
CATEGORIES=	net perl5
MASTER_SITES=	http://seamons.com/projects/perl/net_server/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A configurable base class for writing internet servers in Perl

RUN_DEPENDS=	${SITE_PERL}/IO/Multiplex.pm:${PORTSDIR}/devel/p5-IO-Multiplex
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Server.3 \
		Net::Server::Daemonize.3\
		Net::Server::Fork.3 \
		Net::Server::INET.3 \
		Net::Server::MultiType.3 \
		Net::Server::Multiplex.3 \
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
