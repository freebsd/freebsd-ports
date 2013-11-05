# Created by: Jesper Skriver <jesper@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-SSH-Perl
PORTVERSION=	1.36
CATEGORIES=		net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module implements both the SSH1 and SSH2 protocols

BUILD_DEPENDS=	p5-String-CRC32>=0:${PORTSDIR}/devel/p5-String-CRC32 \
		p5-Math-GMP>=0:${PORTSDIR}/math/p5-Math-GMP \
		p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-Crypt-DSA>=0:${PORTSDIR}/security/p5-Crypt-DSA \
		p5-Crypt-DH>=0:${PORTSDIR}/security/p5-Crypt-DH \
		p5-Math-Pari>=0:${PORTSDIR}/math/p5-Math-Pari \
		p5-Convert-PEM>=0:${PORTSDIR}/converters/p5-Convert-PEM \
		p5-Crypt-IDEA>=0:${PORTSDIR}/security/p5-Crypt-IDEA \
		p5-Digest-BubbleBabble>=0:${PORTSDIR}/security/p5-Digest-BubbleBabble \
		p5-Crypt-RSA>=0:${PORTSDIR}/security/p5-Crypt-RSA
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFIGURE_ENV+=	PERL_MM_USE_DEFAULT="1"
USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	GMP
OPTIONS_DEFAULT=	GMP
GMP_DESC=	Use the optimized Math::BigInt::GMP backend

GMP_BUILD_DEPENDS=	p5-Math-BigInt-GMP>=0:${PORTSDIR}/math/p5-Math-BigInt-GMP
GMP_RUN_DEPENDS=	${GMP_BUILD_DEPENDS}

.include <bsd.port.mk>
