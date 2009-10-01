# Ports collection makefile for:	p5-Catalyst-Plugin-Authorization-ACL
# Date created:				Dec 12, 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Authorization-ACL
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	ACL support for Catalyst applications

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.80013:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Plugin-Authentication>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication \
		p5-Catalyst-Plugin-Authorization-Roles>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Authorization-Roles \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-Throwable>=0:${PORTSDIR}/devel/p5-Class-Throwable \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Tree-Simple-VisitorFactory>=0:${PORTSDIR}/devel/p5-Tree-Simple-VisitorFactory
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Plugin::Authorization::ACL::Engine.3 \
	Catalyst::Plugin::Authorization::ACL.3

.include <bsd.port.mk>
