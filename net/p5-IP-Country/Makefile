# Created by: dikshie <dikshie@lapi.itb.ac.id>
# $FreeBSD$

PORTNAME=	IP-Country
PORTVERSION=	2.28
CATEGORIES=	net perl5 geography
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dikshie@lapi.itb.ac.id
COMMENT=	Fast lookup of country codes from IP addresses

BUILD_DEPENDS=	p5-Geography-Countries>=0:${PORTSDIR}/misc/p5-Geography-Countries
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		ip2cc.1
MAN3=		IP::Authority.3 \
		IP::Country::Fast.3 \
		IP::Country::MaxMind.3 \
		IP::Country::Medium.3 \
		IP::Country::Slow.3 \
		IP::Country.3

NO_STAGE=	yes
.include <bsd.port.mk>
