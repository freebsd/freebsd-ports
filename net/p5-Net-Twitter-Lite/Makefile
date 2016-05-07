# Created by: Masafumi NAKANE <max@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Twitter-Lite
PORTVERSION=	0.12006
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Perl interface to the Twitter API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON>=2.02:converters/p5-JSON \
		p5-libwww>=0:www/p5-libwww \
		p5-URI>=1.4:net/p5-URI \
		p5-Net-OAuth>=0.25:net/p5-Net-OAuth \
		p5-Crypt-SSLeay>=0.5:security/p5-Crypt-SSLeay
RUN_DEPENDS=	p5-JSON>=2.02:converters/p5-JSON \
		p5-libwww>=0:www/p5-libwww \
		p5-URI>=1.4:net/p5-URI \
		p5-Net-OAuth>=0.25:net/p5-Net-OAuth \
		p5-Crypt-SSLeay>=0.5:security/p5-Crypt-SSLeay
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
