# New ports collection makefile for:	p5-Array-PrintCols
# Version required:			2.1
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Array-PrintCols-2.1
PKGNAME=	p5-Array-PrintCols-2.1
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Array

MAINTAINER=	jfitz@FreeBSD.org

USE_PERL5=	YES

MAN3=		Array::PrintCols.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
