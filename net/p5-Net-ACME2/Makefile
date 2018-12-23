# $FreeBSD$

PORTNAME=	Net-ACME2
PORTVERSION=	0.25
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Interface to the Let's Encrypt ACMEv2 API

LICENSE=	ART20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Call-Context>=0.02:devel/p5-Call-Context \
		p5-Crypt-Format>=0.06:security/p5-Crypt-Format \
		p5-Crypt-Perl>=0.17:security/p5-Crypt-Perl \
		p5-Crypt-OpenSSL-Bignum>=0.06:security/p5-Crypt-OpenSSL-Bignum \
		p5-Crypt-OpenSSL-RSA>=0.28:security/p5-Crypt-OpenSSL-RSA \
		p5-Crypt-RSA-Parse>=0.041:security/p5-Crypt-RSA-Parse \
		p5-File-Slurp>=9999:devel/p5-File-Slurp \
		p5-Log-Any>=1.032:devel/p5-Log-Any \
		p5-JSON>=2.90:converters/p5-JSON \
		p5-libwww>=6.13:www/p5-libwww \
		p5-HTTP-Tiny-UA>=0.004:www/p5-HTTP-Tiny-UA \
		p5-Net-SSLeay>=1.49:security/p5-Net-SSLeay \
		p5-Test-Deep>=1.128:devel/p5-Test-Deep \
		p5-Test-Exception>=0.43:devel/p5-Test-Exception \
		p5-Test-NoWarnings>=1.04:devel/p5-Test-NoWarnings \
		p5-X-Tiny>=0.13:devel/p5-X-Tiny

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
