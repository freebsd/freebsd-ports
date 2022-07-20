PORTNAME=	Alt-Crypt-RSA-BigInt
PORTVERSION=	0.06
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DANAJ
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RSA public-key cryptosystem, using Math::BigInt

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Loader>=0:devel/p5-Class-Loader \
		p5-Convert-ASCII-Armour>=0:converters/p5-Convert-ASCII-Armour \
		p5-Crypt-Blowfish>=0:security/p5-Crypt-Blowfish \
		p5-Crypt-CBC>=2.17:security/p5-Crypt-CBC \
		p5-Data-Buffer>=0:misc/p5-Data-Buffer \
		p5-Digest-MD2>=0:security/p5-Digest-MD2 \
		p5-Math-BigInt-GMP>=0:math/p5-Math-BigInt-GMP \
		p5-Math-Prime-Util>=0.64:math/p5-Math-Prime-Util \
		p5-Math-Prime-Util-GMP>=0:math/p5-Math-Prime-Util-GMP \
		p5-Sort-Versions>=0:devel/p5-Sort-Versions \
		p5-Tie-EncryptedHash>=0:security/p5-Tie-EncryptedHash

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
