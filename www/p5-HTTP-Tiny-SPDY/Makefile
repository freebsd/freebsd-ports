# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTTP-Tiny-SPDY
PORTVERSION=	0.020
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Subclass of HTTP::Tiny with SPDY support

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-Socket-SSL>=1.560:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Net-SPDY>=0:${PORTSDIR}/net/p5-Net-SPDY \
		p5-Net-SSLeay>=1.49:${PORTSDIR}/security/p5-Net-SSLeay
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Mozilla-CA>=0:${PORTSDIR}/www/p5-Mozilla-CA

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
