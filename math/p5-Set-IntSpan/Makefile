# New ports collection makefile for:	p5-Set-IntSpan
# Version required:	1.07
# Date created:		February 7, 1998
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $Id: Makefile,v 1.1.1.1 1998/12/24 06:46:58 steve Exp $
#

DISTNAME=	Set-IntSpan-1.07
PKGNAME=	p5-Set-IntSpan-1.07
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Set

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

USE_PERL5=	yes

MAN3=		Set::IntSpan.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
