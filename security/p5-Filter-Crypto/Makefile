# New ports collection makefile for:	Filter-Crypto
# Date created:	   04 November 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Filter-Crypto
PORTVERSION=	2.03
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create runnable Perl files encrypted with OpenSSL libcrypto

BUILD_DEPENDS=	p5-PAR-Packer>=0:${PORTSDIR}/devel/p5-PAR-Packer
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--prefix-dir=${OPENSSLBASE} --defaults

MAN1=		crypt_file.1
MAN3=		Filter::Crypto.3 Filter::Crypto::CryptFile.3 \
		Filter::Crypto::Decrypt.3 PAR::Filter::Crypto.3

.include <bsd.port.mk>
