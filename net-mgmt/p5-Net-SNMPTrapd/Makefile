# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	Net-SNMPTrapd
PORTVERSION=	0.13
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gaod@hychen.org
COMMENT=	SNMP Trap Listener in Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Convert-ASN1>=0.22:${PORTSDIR}/converters/p5-Convert-ASN1 \
		p5-IO-Socket-IP>=0:${PORTSDIR}/net/p5-IO-Socket-IP
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
