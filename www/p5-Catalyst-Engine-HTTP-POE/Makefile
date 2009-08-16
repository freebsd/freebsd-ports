# New ports collection makefile for:	p5-Catalyst-Engine-HTTP-POE
# Date created:		2 Aug 2007
# Whom:			Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Engine-HTTP-POE
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Single-threaded multi-tasking Catalyst engine

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-POE>=0:${PORTSDIR}/devel/p5-POE
BUILD_DEPENDS=	${RUN_DEPENDS}

DEPRECATED=	Use p5-Catalyst-Engine-HTTP-Prefork instead.

PERL_CONFIGURE=	5.8.1+

MAN3=		Catalyst::Engine::HTTP::POE.3

.include <bsd.port.mk>
