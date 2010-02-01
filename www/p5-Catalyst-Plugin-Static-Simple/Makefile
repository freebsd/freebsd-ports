# New ports collection makefile for:	www/p5-Catalyst-Plugin-Static-Simple
# Date created:				July 11, 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Static-Simple
PORTVERSION=	0.29
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Make serving static pages painless

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.80008:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-MIME-Types>=1.25:${PORTSDIR}/mail/p5-MIME-Types \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Catalyst::Plugin::Static::Simple.3

.include <bsd.port.mk>
