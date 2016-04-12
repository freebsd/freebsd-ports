# Created by: mat
# $FreeBSD$

PORTNAME=	Crypt-CBCeasy
PORTVERSION=	0.24
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy things make really easy with Crypt::CBC

BUILD_DEPENDS=	p5-Crypt-CBC>=0:security/p5-Crypt-CBC \
		p5-MD5>=0:security/p5-MD5
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=		DES IDEA BLOWFISH BLOWFISH_PP TWOFISH2 RIJNDAEL
OPTIONS_DEFAULT=	DES IDEA BLOWFISH BLOWFISH_PP TWOFISH2 RIJNDAEL
DES_DESC=		Build with Crypt::DES support
IDEA_DESC=		Build with Crypt::IDEA support
BLOWFISH_DESC=		Build with Crypt::Blowfish support
BLOWFISH_PP_DESC=	Build with Crypt::Blowfish_PP support
TWOFISH2_DESC=		Build with Crypt::Twofish2 support
RIJNDAEL_DESC=		Build with Crypt::Rijndael support

DES_BUILD_DEPENDS=		p5-Crypt-DES>=0:security/p5-Crypt-DES
DES_RUN_DEPENDS=		p5-Crypt-DES>=0:security/p5-Crypt-DES

IDEA_BUILD_DEPENDS=		p5-Crypt-IDEA>=0:security/p5-Crypt-IDEA
IDEA_RUN_DEPENDS=		p5-Crypt-IDEA>=0:security/p5-Crypt-IDEA

BLOWFISH_BUILD_DEPENDS=		p5-Crypt-Blowfish>=0:security/p5-Crypt-Blowfish
BLOWFISH_RUN_DEPENDS=		p5-Crypt-Blowfish>=0:security/p5-Crypt-Blowfish

BLOWFISH_PP_BUILD_DEPENDS=	p5-Crypt-Blowfish_PP>=0:security/p5-Crypt-Blowfish_PP
BLOWFISH_PP_RUN_DEPENDS=	p5-Crypt-Blowfish_PP>=0:security/p5-Crypt-Blowfish_PP

TWOFISH2_BUILD_DEPENDS=		p5-Crypt-Twofish2>=0:security/p5-Crypt-Twofish2
TWOFISH2_RUN_DEPENDS=		p5-Crypt-Twofish2>=0:security/p5-Crypt-Twofish2

RIJNDAEL_BUILD_DEPENDS=		p5-Crypt-Rijndael>=0:security/p5-Crypt-Rijndael
RIJNDAEL_RUN_DEPENDS=		p5-Crypt-Rijndael>=0:security/p5-Crypt-Rijndael

.include <bsd.port.mk>
