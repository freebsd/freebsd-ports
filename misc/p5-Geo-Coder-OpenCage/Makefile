# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-Coder-OpenCage
PORTVERSION=	0.16
CATEGORIES=	misc geography perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Geocode addresses with the OpenCage Geocoder API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-JSON>=2.94:converters/p5-JSON \
		p5-JSON-XS>=3.04:converters/p5-JSON-XS \
		p5-URI>=0:net/p5-URI
TEST_DEPENDS=	p5-Test-Exception>=0.32:devel/p5-Test-Exception \
		p5-Test-Pod>=1.51:devel/p5-Test-Pod \
		p5-Test-Warn>=0:devel/p5-Test-Warn

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
