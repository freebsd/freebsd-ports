# Ports collection Makefile for:	Math-MatrixReal
# Version Required:			1.2
# Date Created:				Aug 14 1997
# Whom:					Sander Vesik <sander@haldjas.folklore.ee>
#
# $FreeBSD$

DISTNAME=		Math-MatrixReal-1.2
PKGNAME=		p5-MatrixReal-1.2
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math

MAINTAINER=	sander@haldjas.folklore.ee

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Math::MatrixReal.3 Math::Kleene.3

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
