# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MaxMind-DB-Reader
PORTVERSION=	0.050.003
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DROLSKY
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read MaxMind DB files

LICENSE=	ART20

BUILD_DEPENDS=	p5-Data-IEEE754>=0:${PORTSDIR}/devel/p5-Data-IEEE754 \
		p5-Data-Printer>=0:${PORTSDIR}/devel/p5-Data-Printer \
		p5-Data-Validate-IP>=0.16:${PORTSDIR}/net-mgmt/p5-Data-Validate-IP \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-List-AllUtils>=0:${PORTSDIR}/devel/p5-List-AllUtils \
		p5-Math-Int128>=0:${PORTSDIR}/math/p5-Math-Int128 \
		p5-MaxMind-DB-Common>=0.031.000:${PORTSDIR}/net/p5-MaxMind-DB-Common \
		p5-Module-Implementation>=0:${PORTSDIR}/devel/p5-Module-Implementation \
		p5-Moo>=1.003000:${PORTSDIR}/devel/p5-Moo \
		p5-MooX-StrictConstructor>=0:${PORTSDIR}/devel/p5-MooX-StrictConstructor \
		p5-Net-Works>=0:${PORTSDIR}/net/p5-Net-Works \
		p5-Role-Tiny>=0:${PORTSDIR}/devel/p5-Role-Tiny \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Bits>=0:${PORTSDIR}/devel/p5-Test-Bits \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Number-Delta>=0:${PORTSDIR}/devel/p5-Test-Number-Delta

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
