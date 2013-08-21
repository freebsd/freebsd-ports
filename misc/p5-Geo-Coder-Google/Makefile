# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-Coder-Google
PORTVERSION=	0.12
CATEGORIES=	misc geography perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ARCANEZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Maps Geocoding API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-JSON>=2.27:${PORTSDIR}/converters/p5-JSON \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=5.5:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Number-Delta>=0:${PORTSDIR}/devel/p5-Test-Number-Delta

USE_PERL5=	configure
USES=		perl5

MAN3=		Geo::Coder::Google.3 \
		Geo::Coder::Google::V2.3 \
		Geo::Coder::Google::V3.3

.include <bsd.port.mk>
