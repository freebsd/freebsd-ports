# New ports collection makefile for:	p5-Crypt-IDEA
# Version required:			1.0
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Crypt-IDEA-1.0
PKGNAME=	p5-Crypt-IDEA-1.0
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt

MAINTAINER=	jfitz@FreeBSD.org

RESTRICTED=	"Crypto; export-controlled"

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Crypt::IDEA.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
