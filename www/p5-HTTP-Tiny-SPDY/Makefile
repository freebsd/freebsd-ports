# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	HTTP-Tiny-SPDY
PORTVERSION=	0.020
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Subclass of HTTP::Tiny with SPDY support

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-Socket-SSL>=1.560:security/p5-IO-Socket-SSL \
		p5-Net-SPDY>=0:net/p5-Net-SPDY \
		p5-Net-SSLeay>=1.49:security/p5-Net-SSLeay
TEST_DEPENDS=	p5-Mozilla-CA>=0:www/p5-Mozilla-CA

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
