PORTNAME=	Crypt-CBC
PORTVERSION=	3.07
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to Cipher Block Chaining with DES and IDEA
WWW=		https://metacpan.org/release/Crypt-CBC

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-PBKDF2>=0:security/p5-Crypt-PBKDF2 \
		p5-Crypt-URandom>=0:security/p5-Crypt-URandom \
		p5-CryptX>=0:security/p5-CryptX
TEST_DEPENDS=	p5-Crypt-Blowfish>=0:security/p5-Crypt-Blowfish \
		p5-Crypt-Blowfish_PP>=0:security/p5-Crypt-Blowfish_PP \
		p5-Crypt-CAST5>=0:security/p5-Crypt-CAST5 \
		p5-Crypt-DES>=0:security/p5-Crypt-DES \
		p5-Crypt-IDEA>=0:security/p5-Crypt-IDEA \
		p5-Crypt-Rijndael>=0:security/p5-Crypt-Rijndael \
		p5-Math-Int128>=0:math/p5-Math-Int128

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
