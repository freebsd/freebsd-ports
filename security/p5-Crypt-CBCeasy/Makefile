# New ports collection makefile for:	p5-Crypt-CBCeasy
# Date created:				16 octobre 2003
# Whom:	      				mat
#
# $FreeBSD$
#

PORTNAME=	Crypt-CBCeasy
PORTVERSION=	0.24
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy things make really easy with Crypt::CBC

BUILD_DEPENDS=	${SITE_PERL}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC \
		${SITE_PERL}/MD5.pm:${PORTSDIR}/security/p5-MD5
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Crypt::CBCeasy.3

.include <bsd.port.pre.mk>

OPTIONS=	DES "Build with Crypt::DES support" on
.if !defined(WITHOUT_DES)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Crypt/DES.pm:${PORTSDIR}/security/p5-Crypt-DES
.endif
OPTIONS+=	IDEA "Build with Crypt::IDEA support" on
.if !defined(WITHOUT_IDEA)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Crypt/IDEA.pm:${PORTSDIR}/security/p5-Crypt-IDEA
.endif
OPTIONS+=	BLOWFISH "Build with Crypt::Blowfish support" on
.if !defined(WITHOUT_BLOWFISH)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Crypt/Blowfish.pm:${PORTSDIR}/security/p5-Crypt-Blowfish
.endif
OPTIONS+=	BLOWFISH_PP "Build with Crypt::Blowfish_PP support" on
.if !defined(WITHOUT_BLOWFISH_PP)
BUILD_DEPENDS+=	${SITE_PERL}/Crypt/Blowfish_PP.pm:${PORTSDIR}/security/p5-Crypt-Blowfish_PP
.endif
OPTIONS+=	TWOFISH2 "Build with Crypt::Twofish2 support" on
.if !defined(WITHOUT_TWOFISH2)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Crypt/Twofish2.pm:${PORTSDIR}/security/p5-Crypt-Twofish2
.endif
OPTIONS+=	RIJNDAEL "Build with Crypt::Rijndael support" on
.if !defined(WITHOUT_RIJNDAEL)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Crypt/Rijndael.pm:${PORTSDIR}/security/p5-Crypt-Rijndael
.endif

.include <bsd.port.post.mk>
