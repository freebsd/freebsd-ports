# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>
# $FreeBSD$

PORTNAME=	Crypt-PKCS10
PORTVERSION=	1.800201
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Parse PKCS #10 certificate requests

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Convert-ASN1>=0.27:converters/p5-Convert-ASN1 \
		p5-Crypt-OpenSSL-DSA>0:security/p5-Crypt-OpenSSL-DSA \
		p5-Crypt-OpenSSL-RSA>0:security/p5-Crypt-OpenSSL-RSA \
		p5-CryptX>0:security/p5-CryptX \
		p5-Digest-MD2>0:security/p5-Digest-MD2 \
		p5-Digest-MD4>0:security/p5-Digest-MD4
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Module-Signature>0:security/p5-Module-Signature

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
