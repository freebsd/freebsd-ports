# Created by: Jesper Skriver <jesper@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-SSH-Perl
PORTVERSION=	1.42
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module implementing both the SSH1 and SSH2 protocols

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Convert-PEM>=0.05:converters/p5-Convert-PEM \
		p5-Crypt-DES>0:security/p5-Crypt-DES \
		p5-Crypt-DH>=0.01:security/p5-Crypt-DH \
		p5-Crypt-DSA>=0.11:security/p5-Crypt-DSA \
		p5-Crypt-IDEA>=0:security/p5-Crypt-IDEA \
		p5-Crypt-RSA>=0:security/p5-Crypt-RSA \
		p5-Digest-BubbleBabble>=0:security/p5-Digest-BubbleBabble \
		p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-Digest-SHA1>=2.10:security/p5-Digest-SHA1 \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-Math-GMP>=1.04:math/p5-Math-GMP \
		p5-Math-Pari>=2.001804:math/p5-Math-Pari \
		p5-String-CRC32>=1.2:devel/p5-String-CRC32
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFIGURE_ENV=	PERL_MM_USE_DEFAULT="1"
NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	GMP
OPTIONS_DEFAULT=GMP
GMP_DESC=	Use the optimized Math::BigInt::GMP backend

GMP_BUILD_DEPENDS=	p5-Math-BigInt-GMP>=0:math/p5-Math-BigInt-GMP
GMP_RUN_DEPENDS=	${GMP_BUILD_DEPENDS}

.include <bsd.port.mk>
