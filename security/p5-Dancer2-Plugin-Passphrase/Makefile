PORTNAME=	Dancer2-Plugin-Passphrase
PORTVERSION=	3.4.1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Passphrases and Passwords as objects for Dancer2

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Crypt-Bcrypt>=0.006:security/p5-Crypt-Bcrypt \
		p5-Dancer2>=0.200000:www/p5-Dancer2 \
		p5-Data-Entropy>=0.007:security/p5-Data-Entropy \
		p5-Digest-Bcrypt>=1.212:security/p5-Digest-Bcrypt

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
