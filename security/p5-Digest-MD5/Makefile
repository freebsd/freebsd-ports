# New ports collection makefile for:    p5-Digest-MD5
# Version required:                     2.*
# Date created:				1999/04/07
# Whom:					ache
#
# $Id: Makefile,v 1.1.1.1 1999/04/07 20:20:33 ache Exp $
#

DISTNAME=       Digest-MD5-2.06
PKGNAME=        p5-Digest-MD5-2.06
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MD5

MAINTAINER=     ache@FreeBSD.ORG

USE_PERL5=	YES

MAN3=   \
	Digest::MD2.3 \
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
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
