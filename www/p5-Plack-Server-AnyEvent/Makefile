# New ports collection makefile for:	Plack::Server::AnyEvent
# Date created:		13 Oct 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Server-AnyEvent
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for AnyEvent based HTTP server

RUN_DEPENDS=	\
	p5-AnyEvent>0:${PORTSDIR}/devel/p5-AnyEvent \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny \
	p5-namespace-clean>0:${PORTSDIR}/devel/p5-namespace-clean
BUILD_DEPENDS=	${RUN_DEPENDS}

DEPRECATED=	yes
EXPIRATION_DATE=2010-08-31
PERL_CONFIGURE=	yes

MAN3=	Plack::Server::AnyEvent.3

.include <bsd.port.mk>
