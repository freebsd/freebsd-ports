# New ports collection makefile for:	p5-MD5
# Version required:			1.7
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	MD5-1.7
PKGNAME=	p5-MD5-1.7
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MD5

MAINTAINER=	jfitz@FreeBSD.org

USE_PERL5=	YES

MAN3=		MD5.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
