# Created by: Jesse McConnell <jesse@gallup.com>
# $FreeBSD$

PORTNAME=	Net-Server
PORTVERSION=	2.008
PORTREVISION=	3
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Configurable base class for writing internet servers in Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-Multiplex>=1.01:devel/p5-IO-Multiplex
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	IPV6

USES=		perl5
USE_PERL5=	configure

IPV6_BUILD_DEPENDS=	p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6 \
			p5-Socket6>=0.23:net/p5-Socket6
IPV6_RUN_DEPENDS=	p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6 \
			p5-Socket6>=0.23:net/p5-Socket6

.include <bsd.port.mk>
