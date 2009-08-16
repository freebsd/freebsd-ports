# Ports collection makefile for: p5-Catalyst-Plugin-C3
# Date created:			 Apr 6, 2007
# Whom:				 lbr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-C3
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst Plugin to subvert NEXT to use Class::C3

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7006:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Class-C3>=0.19:${PORTSDIR}/devel/p5-Class-C3
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Plugin::C3.3

.include <bsd.port.mk>
