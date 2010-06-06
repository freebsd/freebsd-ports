# New ports collection makefile for:  Catalyst-Controller-ActionRole
# Whom: mons
# Date created: 07 December 2009
# $FreeBSD$
# Generated with portupload. Do not edit directly, please

PORTNAME=	Catalyst-Controller-ActionRole
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mons@cpan.org
COMMENT=	Apply roles to action instances

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.71001:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-MOP>=0.80:${PORTSDIR}/devel/p5-Class-MOP \
		p5-Moose>=0.70:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-String-RewritePrefix>=0.004:${PORTSDIR}/textproc/p5-String-RewritePrefix \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Catalyst::Controller::ActionRole.3

.include <bsd.port.mk>
