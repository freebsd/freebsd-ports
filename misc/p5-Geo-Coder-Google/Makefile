# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-Coder-Google
PORTVERSION=	0.16
CATEGORIES=	misc geography perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Maps Geocoding API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-JSON>=2.27:converters/p5-JSON \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=5.5:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Number-Delta>=0:devel/p5-Test-Number-Delta

PORTSCOUT=	limit:^[0-9\.]*$$

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
