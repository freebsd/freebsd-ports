# New ports collection makefile for:	p5-CGI_Lite
# Version required:			1.62
# Date created:				September 30th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.5 1997/05/24 13:17:15 jfitz Exp $
#

DISTNAME=	CGI_Lite-1.62.pm
PKGNAME=	p5-CGI_Lite-1.62
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI_Lite
EXTRACT_SUFX=	.gz

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

NO_BUILD=	yes

do-extract:
		@ ${MKDIR} -p work
		@ ${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKDIR}
		@ gunzip ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX}

do-install:
		@ ${INSTALL_DATA} ${WRKDIR}/${DISTNAME} ${PREFIX}/lib/perl5/site_perl/
		@ ln -sf ${PREFIX}/lib/perl5/site_perl/${DISTNAME} ${PREFIX}/lib/perl5/site_perl/CGI_Lite.pm

.include <bsd.port.mk>
