# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	Geo-Coder-OpenCage
PORTVERSION=	0.30
CATEGORIES=	misc geography perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Geocode addresses with the OpenCage Geocoder API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Cpanel-JSON-XS>=4.21:converters/p5-Cpanel-JSON-XS \
		p5-IO-Socket-SSL>=2.068:security/p5-IO-Socket-SSL \
		p5-JSON-MaybeXS>=1.004003:converters/p5-JSON-MaybeXS \
		p5-URI>=0:net/p5-URI
TEST_DEPENDS=	p5-Net-Ping>=2.73:net/p5-Net-Ping \
		p5-Perl-Tidy>=20210111:devel/p5-Perl-Tidy \
		p5-Test-Exception>=0.32:devel/p5-Test-Exception \
		p5-Test-Pod>=1.51:devel/p5-Test-Pod \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
