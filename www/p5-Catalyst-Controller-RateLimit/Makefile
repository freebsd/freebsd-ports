# New ports collection makefile for:  Catalyst-Controller-RateLimit
# Date created: 12 February 2010
# Whom: andrey@kostenko.name
#
# $FreeBSD$

PORTNAME=	Catalyst-Controller-RateLimit
PORTVERSION=	0.28
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Protect your site from robots

RUN_DEPENDS=	p5-Algorithm-FloodControl>=1.91:${PORTSDIR}/devel/p5-Algorithm-FloodControl \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.7+
MAN3=	Catalyst::Controller::RateLimit.3

.include <bsd.port.mk>
