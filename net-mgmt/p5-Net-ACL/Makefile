# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-ACL
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Class representing a generic access-list/route-map

BUILD_DEPENDS=	p5-Cisco-Reconfig>=0.05:${PORTSDIR}/net-mgmt/p5-Cisco-Reconfig \
		p5-IO-String>=1.02:${PORTSDIR}/devel/p5-IO-String \
		p5-Net-Netmask>=0:${PORTSDIR}/net-mgmt/p5-Net-Netmask
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Signature>=1.04:${PORTSDIR}/devel/p5-Test-Signature

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
