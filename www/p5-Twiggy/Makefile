# New ports collection makefile for:	Twiggy
# Date created:		05 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Twiggy
PORTVERSION=	0.1010
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of AnyEvent HTTP server for PSGI (like Thin)

RUN_DEPENDS=	\
	p5-AnyEvent>0:${PORTSDIR}/devel/p5-AnyEvent \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-Plack>=0.99:${PORTSDIR}/www/p5-Plack \
	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	twiggy.1
MAN3=	Plack::Handler::Twiggy.3 \
	Twiggy.3

.include <bsd.port.mk>
