# New ports collection makefile for:	Filter-Crypto
# Date created:	   04 November 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Filter-Crypto
PORTVERSION=	1.13
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Filter
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Create runnable Perl files encrypted with OpenSSL libcrypto

BUILD_DEPENDS=	${SITE_PERL}/PAR/Filter.pm:${PORTSDIR}/devel/p5-PAR
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--prefix-dir=${OPENSSLBASE} --defaults

MAN1=		crypt_file.1
MAN3=		Filter::Crypto.3 Filter::Crypto::CryptFile.3 \
		Filter::Crypto::Decrypt.3 PAR::Filter::Crypto.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	"Perl 5.6 or newer required. Install lang/perl5.8 or lang/perl5 and try again."
.endif

.include <bsd.port.post.mk>
