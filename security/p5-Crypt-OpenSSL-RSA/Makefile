# Created by: nork@cityfujisawa.ne.jp
# $FreeBSD$

PORTNAME=	Crypt-OpenSSL-RSA
PORTVERSION=	0.31
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to RSA encode and decode strings using OpenSSL

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Crypt-OpenSSL-Guess>=0.11:security/p5-Crypt-OpenSSL-Guess \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-OpenSSL-Bignum>=0:security/p5-Crypt-OpenSSL-Bignum \
		p5-Crypt-OpenSSL-Random>=0:security/p5-Crypt-OpenSSL-Random

USES=		perl5 ssl
USE_PERL5=	configure

.include <bsd.port.mk>
