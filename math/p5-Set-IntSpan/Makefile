# New ports collection makefile for:	p5-Set-IntSpan
# Version required:	1.06
# Date created:		February 7, 1998
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $Id$
#

DISTNAME=	Set-IntSpan-1.06
PKGNAME=	p5-Set-IntSpan-1.06
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Set

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

USE_PERL5=	yes

MAN3=		Set::IntSpan.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
