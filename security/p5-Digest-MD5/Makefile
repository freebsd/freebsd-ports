# New ports collection makefile for:    p5-Digest-MD5
# Date created:				1999/04/07
# Whom:					ache
#
# $FreeBSD$
#

PORTNAME=	Digest-MD5
PORTVERSION=	2.12
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	ache@FreeBSD.org

PERL_CONFIGURE=	yes

MAN3=	Digest::MD2.3 \
	Digest::SHA1.3 \
	SHA.3 \
	Digest::HMAC.3 \
	Digest.3 \
	Digest::MD5.3 \
	Digest::HMAC_SHA1.3 \
	Digest::HMAC_MD5.3 \
	MD5.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
