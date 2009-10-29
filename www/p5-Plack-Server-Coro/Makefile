# New ports collection makefile for:	Plack::Server::Coro
# Date created:		14 Oct 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Server-Coro
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Coro cooperative multithread web server

RUN_DEPENDS=	\
	p5-Coro>0:${PORTSDIR}/devel/p5-Coro \
	p5-Net-Server-Coro>=0.5:${PORTSDIR}/net/p5-Net-Server-Coro \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Plack::Server::Coro.3

.include <bsd.port.mk>
