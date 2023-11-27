PORTNAME=	XML-Sig
PORTVERSION=	0.65
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolkit to help sign and verify XML Digital Signatures
WWW=		https://metacpan.org/dist/XML-Sig

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Crypt-OpenSSL-Bignum>=0:security/p5-Crypt-OpenSSL-Bignum \
		p5-Crypt-OpenSSL-DSA>=0.20:security/p5-Crypt-OpenSSL-DSA \
		p5-Crypt-OpenSSL-RSA>=0:security/p5-Crypt-OpenSSL-RSA \
		p5-Crypt-OpenSSL-X509>=0:security/p5-Crypt-OpenSSL-X509 \
		p5-CryptX>=0.036:security/p5-CryptX \
		p5-URI>=0:net/p5-URI \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML
TEST_DEPENDS=	p5-Crypt-OpenSSL-Guess>=0:security/p5-Crypt-OpenSSL-Guess \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-Import-Into>=0:devel/p5-Import-Into \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Lib>=0:devel/p5-Test-Lib

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
