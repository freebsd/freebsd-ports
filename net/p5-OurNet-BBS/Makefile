# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	OurNet-BBS
PORTVERSION=	1.66
PORTREVISION=	5
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Component Object Model for BBS systems

BUILD_DEPENDS=	p5-Class-MethodMaker>=0:devel/p5-Class-MethodMaker \
		p5-Crypt-Blowfish>=0:security/p5-Crypt-Blowfish \
		p5-Crypt-DES>=0:security/p5-Crypt-DES \
		p5-Crypt-GOST>=0:security/p5-Crypt-GOST \
		p5-Crypt-IDEA>=0:security/p5-Crypt-IDEA \
		p5-Crypt-Rijndael>=0:security/p5-Crypt-Rijndael \
		p5-Crypt-TEA>=0:security/p5-Crypt-TEA \
		p5-Crypt-Twofish>=0:security/p5-Crypt-Twofish \
		p5-Crypt-Twofish2>=0:security/p5-Crypt-Twofish2 \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-Crypt-Blowfish_PP>=0:security/p5-Crypt-Blowfish_PP \
		p5-Crypt-DES_PP>=0:security/p5-Crypt-DES_PP \
		p5-Crypt-Rijndael_PP>=0:security/p5-Crypt-Rijndael_PP \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-GnuPG-Interface>=0:security/p5-GnuPG-Interface \
		p5-Hook-LexWrap>=0:devel/p5-Hook-LexWrap \
		p5-Mail-Tools>=0:mail/p5-Mail-Tools \
		p5-Mail-Box>=0:mail/p5-Mail-Box \
		p5-Mail-Tools>=0:mail/p5-Mail-Tools \
		p5-Net-Daemon>=0:net/p5-Net-Daemon \
		p5-Net-Telnet>=0:net/p5-Net-Telnet \
		p5-OurNet-BBSAgent>=0:net/p5-OurNet-BBSAgent \
		p5-PlRPC>=0:net/p5-PlRPC \
		p5-enum>=0:devel/p5-enum
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTSCOUT=	skipv:1.67

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
