# New ports collection makefile for:	p5-Crypt-DES
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	p5-Crypt-DES
PORTVERSION=	1.01
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
DISTNAME=	Crypt-DES-1.01

MAINTAINER=	jfitz@FreeBSD.org

RESTRICTED=	"Crypto; export-controlled"

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Crypt::DES.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
