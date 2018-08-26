# $FreeBSD$

PORTNAME=	Crypt-Perl
PORTVERSION=	0.29
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Cryptography in Pure Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Test-Class>=0.4:devel/p5-Test-Class \
		p5-Call-Context>=0:devel/p5-Call-Context \
		p5-Class-Accessor>=0.34:devel/p5-Class-Accessor \
		p5-Convert-ASN1>=0.27:converters/p5-Convert-ASN1 \
		p5-Crypt-Format>=0.06:security/p5-Crypt-Format \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-Math-Utils>=1.07:math/p5-Math-Utils \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-FailWarnings>=0:devel/p5-Test-FailWarnings \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-Bytes-Random-Secure-Tiny>=1.008:security/p5-Bytes-Random-Secure-Tiny \
		p5-Math-ProvablePrime>=0.043:math/p5-Math-ProvablePrime \
		p5-Symbol-Get>=0.02:devel/p5-Symbol-Get

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
