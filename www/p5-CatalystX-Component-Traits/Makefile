# New ports collection makefile for:	www/p5-CatalystX-Component-Traits
# Date created:				25 July 2009
# Whom:					Bill Brinzer <bill.brinzer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	CatalystX-Component-Traits
PORTVERSION=	0.16
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill.brinzer@gmail.com
COMMENT=	Automatic Trait Loading and Resolution for Catalyst Components

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.80005:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-MooseX-Traits-Pluggable>=0.08:${PORTSDIR}/devel/p5-MooseX-Traits-Pluggable \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	CatalystX::Component::Traits.3

.include <bsd.port.mk>
