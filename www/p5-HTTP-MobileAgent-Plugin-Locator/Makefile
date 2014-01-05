# $FreeBSD$

PORTNAME=	HTTP-MobileAgent-Plugin-Locator
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Mobile location information plugin for p5-HTTP-MobileAgent

RUN_DEPENDS=	\
	p5-Geo-Coordinates-Converter>=0.10:${PORTSDIR}/science/p5-Geo-Coordinates-Converter \
	p5-Geo-Coordinates-Converter-iArea>=0.11:${PORTSDIR}/science/p5-Geo-Coordinates-Converter-iArea \
	p5-HTTP-MobileAgent>=0.31:${PORTSDIR}/www/p5-HTTP-MobileAgent \
	p5-UNIVERSAL-can>0:${PORTSDIR}/devel/p5-UNIVERSAL-can \
	p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
