# New ports collection makefile for:	Filter-Crypto
# Date created:	   04 November 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Filter-Crypto
PORTVERSION=	1.23
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Create runnable Perl files encrypted with OpenSSL libcrypto

BUILD_DEPENDS=	${SITE_PERL}/PAR/Filter.pm:${PORTSDIR}/devel/p5-PAR-Packer \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--prefix-dir=${OPENSSLBASE} --defaults

MAN1=		crypt_file.1
MAN3=		Filter::Crypto.3 Filter::Crypto::CryptFile.3 \
		Filter::Crypto::Decrypt.3 PAR::Filter::Crypto.3

.include <bsd.port.mk>
