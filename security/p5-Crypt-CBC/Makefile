PORTNAME=	Crypt-CBC
PORTVERSION=	3.04
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to Cipher Block Chaining with DES and IDEA

LICENSE=	ART10

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-PBKDF2>=0:security/p5-Crypt-PBKDF2 \
		p5-CryptX>=0:security/p5-CryptX

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
