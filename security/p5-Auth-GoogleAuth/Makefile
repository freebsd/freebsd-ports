PORTNAME=	Auth-GoogleAuth
DISTVERSION=	1.09
CATEGORIES=	security perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/G/GR/GRYPHON/ \
		https://www.cpan.org/authors/id/G/GR/GRYPHON/
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd@gushi.org
COMMENT=	Google Authenticator TOTP abstraction
WWW=		https://metacpan.org/dist/Auth-GoogleAuth

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Convert-Base32>=0:converters/p5-Convert-Base32 \
		p5-CryptX>=0:security/p5-CryptX \
		p5-Digest-HMAC>=0:security/p5-Digest-HMAC \
		p5-URI>=0:net/p5-URI

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
