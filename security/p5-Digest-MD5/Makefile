# New ports collection makefile for:    p5-Digest-MD5
# Date created:				1999/04/07
# Whom:					ache
#
# $FreeBSD$
#

PORTNAME=	Digest-MD5
PORTVERSION=	2.09
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MD5
PKGNAMEPREFIX=	p5-

MAINTAINER=	ache@FreeBSD.org

USE_PERL5=	yes

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

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
		CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
