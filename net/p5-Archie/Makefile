# New ports collection makefile for:	p5-Archie
# Version required:			1.5
# Date created:				October 19th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.5 1997/05/24 13:17:12 jfitz Exp $
#

DISTNAME=	perl_archie.1.5
PKGNAME=	p5-Archie-1.5
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Archie

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

NO_WRKSUBDIR=	YES
NO_BUILD=	YES

do-install:
		@ ${CP} ${WRKDIR}/Archie.pm ${WRKDIR}/Archie-1.5.pm
		@ ${INSTALL_DATA} ${WRKDIR}/Archie-1.5.pm ${PREFIX}/lib/perl5/site_perl/
		@ ln -sf ${PREFIX}/lib/perl5/site_perl/Archie-1.5.pm ${PREFIX}/lib/perl5/site_perl/Archie.pm
		@ ${INSTALL_DATA} ${WRKDIR}/archie_gateway ${PREFIX}/lib/perl5/site_perl/

.include <bsd.port.mk>
