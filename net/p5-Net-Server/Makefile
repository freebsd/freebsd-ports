# New ports collection makefile for:	p5-Net-Server
# Date created:				24 Apr 2001
# Whom:	      				Jesse McConnell <jesse_mcconnell@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	Net-Server
PORTVERSION=	0.63
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	jesse_mcconnell@hotmail.com

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::Server.3 \
		Net::Server::Fork.3 \
		Net::Server::INET.3 \
		Net::Server::MultiType.3 \
		Net::Server::PreFork.3 \
		Net::Server::Single.3

.include <bsd.port.mk>
