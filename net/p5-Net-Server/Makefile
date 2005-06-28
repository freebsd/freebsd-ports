# New ports collection makefile for:	p5-Net-Server
# Date created:				24 Apr 2001
# Whom:					Jesse McConnell <jesse@gallup.com>
#
# $FreeBSD$
#

PORTNAME=	Net-Server
PORTVERSION=	0.88
CATEGORIES=	net perl5
MASTER_SITES=	http://www.seamons.com/net_server/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A configurable base class for writing internet servers in Perl

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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/IO/Socket/UNIX.pm:${PORTSDIR}/devel/p5-IO
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/IO/Socket/UNIX.pm:${PORTSDIR}/devel/p5-IO
.endif

.include <bsd.port.post.mk>
