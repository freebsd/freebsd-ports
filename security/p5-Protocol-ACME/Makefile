# $FreeBSD$

PORTNAME=	Protocol-ACME
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SLUDIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Interface to the Let's Encrypt ACME API

LICENSE=	ART20

RUN_DEPENDS=	p5-Crypt-Format>=0.06:security/p5-Crypt-Format \
		p5-Crypt-OpenSSL-Bignum>=0.06:security/p5-Crypt-OpenSSL-Bignum \
		p5-Crypt-OpenSSL-RSA>=0.28:security/p5-Crypt-OpenSSL-RSA \
		p5-Crypt-RSA-Parse>=0.041:security/p5-Crypt-RSA-Parse \
		p5-Digest-SHA>=5.95:security/p5-Digest-SHA \
		p5-Log-Any>=1.032:devel/p5-Log-Any \
		p5-JSON>=2.90:converters/p5-JSON \
		p5-libwww>=6.13:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
