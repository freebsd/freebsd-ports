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
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Crypt::CBCeasy.3

OPTIONS_DEFINE=	DES IDEA BLOWFISH BLOWFISH_PP TWOFISH2 RIJNDAEL
OPTIONS_DEFAULT=	DES IDEA BLOWFISH BLOWFISH_PP TWOFISH2 RIJNDAEL
DES_DESC=		Build with Crypt::DES support
IDEA_DESC=		Build with Crypt::IDEA support
BLOWFISH_DESC=		Build with Crypt::Blowfish support
BLOWFISH_PP_DESC=	Build with Crypt::Blowfish_PP support
TWOFISH2_DESC=		Build with Crypt::Twofish2 support
RIJNDAEL_DESC=		Build with Crypt::Rijndael support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDES}
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Crypt/DES.pm:${PORTSDIR}/security/p5-Crypt-DES
.endif
.if ${PORT_OPTIONS:MIDEA}
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Crypt/IDEA.pm:${PORTSDIR}/security/p5-Crypt-IDEA
.endif
.if ${PORT_OPTIONS:MBLOWFISH}
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Crypt/Blowfish.pm:${PORTSDIR}/security/p5-Crypt-Blowfish
.endif
.if ${PORT_OPTIONS:MBLOWFISH_PP}
BUILD_DEPENDS+=	${SITE_PERL}/Crypt/Blowfish_PP.pm:${PORTSDIR}/security/p5-Crypt-Blowfish_PP
.endif
.if ${PORT_OPTIONS:MTWOFISH2}
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Crypt/Twofish2.pm:${PORTSDIR}/security/p5-Crypt-Twofish2
.endif
.if ${PORT_OPTIONS:MRIJNDAEL}
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Crypt/Rijndael.pm:${PORTSDIR}/security/p5-Crypt-Rijndael
.endif

.include <bsd.port.mk>
