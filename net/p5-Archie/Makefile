# New ports collection makefile for:	p5-Archie
# Version required:			1.5
# Date created:				October 19th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1996/10/24 08:28:51 jfitz Exp $
#

DISTNAME=	perl_archie.1.5
PKGNAME=	p5-Archie-1.5
CATEGORIES+=	net
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/Archie/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/Archie/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/Archie/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/Archie/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/Archie/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/Archie/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

NO_WRKSUBDIR=	YES
NO_BUILD=	YES

do-install:
		@ ${CP} ${WRKDIR}/Archie.pm ${WRKDIR}/Archie-1.5.pm
		@ ${INSTALL_DATA} ${WRKDIR}/Archie-1.5.pm ${PREFIX}/lib/perl5/site_perl/
		@ ln -sf ${PREFIX}/lib/perl5/site_perl/Archie-1.5.pm ${PREFIX}/lib/perl5/site_perl/Archie.pm
		@ ${INSTALL_DATA} ${WRKDIR}/archie_gateway ${PREFIX}/lib/perl5/site_perl/

.include <bsd.port.mk>
