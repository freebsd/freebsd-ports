# New ports collection makefile for:	p5-HTML
# Version required:			0.6
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.2 1996/10/24 09:58:48 jfitz Exp $
#

DISTNAME=	HTML-0.6
PKGNAME=	p5-HTML-0.6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

NO_WRKSUBDIR=	YES
NO_BUILD=	YES

do-install:
		@ ${MKDIR} -p ${PREFIX}/lib/perl5/site_perl/HTML/
		@ ${INSTALL_DATA} ${WRKDIR}/HTML/Base.pm ${PREFIX}/lib/perl5/site_perl/HTML/
		@ ${INSTALL_DATA} ${WRKDIR}/html_base.pod ${PREFIX}/lib/perl5/site_perl/

.include <bsd.port.mk>
