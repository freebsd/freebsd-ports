# New ports collection makefile for:	p5-HTML
# Version required:			0.6
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id$
#

DISTNAME=	HTML-0.6
PKGNAME=	p5-HTML-0.6
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/HTML/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/HTML/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/HTML/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/HTML/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/HTML/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/HTML/

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5

NO_WRKSUBDIR=	YES
NO_BUILD=	YES

do-install:
		@ ${MKDIR} -p ${PREFIX}/lib/perl5/site_perl/HTML/
		@ ${INSTALL_DATA} ${WRKDIR}/HTML/Base.pm ${PREFIX}/lib/perl5/site_perl/HTML/
		@ ${INSTALL_DATA} ${WRKDIR}/html_base.pod ${PREFIX}/lib/perl5/site_perl/

.include <bsd.port.mk>
