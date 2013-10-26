# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$

PORTNAME=	Net-Works
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DROLSKY
PKGNAMEPREFIX=	p5-

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	APIs for IP addresses and networks

LICENSE=	ART20

BUILD_DEPENDS=	p5-List-AllUtils>=0.03:${PORTSDIR}/devel/p5-List-AllUtils \
		p5-Math-Int128>=0.07:${PORTSDIR}/math/p5-Math-Int128 \
		p5-namespace-autoclean>=0.13:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-MooseX-Types>=0.35:${PORTSDIR}/devel/p5-MooseX-Types
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::Works.3 Net::Works::Util.3 Net::Works::Address.3 \
		Net::Works::Network.3

NO_STAGE=	yes
.include <bsd.port.mk>
