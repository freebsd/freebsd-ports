# New ports collection makefile for:	p5-CGI_Lite
# Version required:			1.62
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.1.1.1 1996/10/24 08:41:38 jfitz Exp $
#

DISTNAME=	CGI_Lite-1.62.pm
PKGNAME=	p5-CGI_Lite-1.62
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/CGI_Lite/ \
		ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/CGI_Lite/ \
		ftp://ftp.cis.ufl.edu/pub/perl/CPAN/modules/by-module/CGI_Lite/ \
		ftp://ftp.leo.org/pub/comp/programming/languages/perl/CPAN/modules/by-module/CGI_Lite/ \
		ftp://ftp.demon.co.uk/pub/mirrors/perl/CPAN/modules/by-module/CGI_Lite/ \
		ftp://ftp.lab.kdd.co.jp/lang/perl/CPAN/modules/by-module/CGI_Lite/

MAINTAINER=	jfitz@FreeBSD.ORG

EXTRACT_SUFX=	.gz
BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

NO_BUILD=	yes

do-extract:
		@ ${MKDIR} -p work
		@ ${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKDIR}
		@ gunzip ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX}

do-install:
		@ ${INSTALL_DATA} ${WRKDIR}/${DISTNAME} ${PREFIX}/lib/perl5/site_perl/
		@ ln -sf ${PREFIX}/lib/perl5/site_perl/${DISTNAME} ${PREFIX}/lib/perl5/site_perl/CGI_Lite.pm

.include <bsd.port.mk>
