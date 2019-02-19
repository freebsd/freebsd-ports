# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-Coder-OpenCage
PORTVERSION=	0.20
CATEGORIES=	misc geography perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Geocode addresses with the OpenCage Geocoder API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Cpanel-JSON-XS>=4.08:converters/p5-Cpanel-JSON-XS \
		p5-JSON-MaybeXS>=1.004000:converters/p5-JSON-MaybeXS \
		p5-URI>=0:net/p5-URI
TEST_DEPENDS=	p5-Net-Ping>=2.71:net/p5-Net-Ping \
		p5-Test-Exception>=0.32:devel/p5-Test-Exception \
		p5-Test-Pod>=1.51:devel/p5-Test-Pod \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
