# New ports collection makefile for:	Net::Server::Coro
# Date created:		14 Oct 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Server-Coro
PORTVERSION=	0.7
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for co-operative multithreaded server using Coro

RUN_DEPENDS=	\
	p5-Coro>0:${PORTSDIR}/devel/p5-Coro \
	p5-EV>0:${PORTSDIR}/devel/p5-EV \
	p5-Net-SSLeay>0:${PORTSDIR}/security/p5-Net-SSLeay \
	p5-Net-Server>0:${PORTSDIR}/net/p5-Net-Server
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Net::Server::Coro.3

.include <bsd.port.mk>
