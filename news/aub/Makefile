# ex:ts=8
# Ports collection makefile for:  aub
# Version required:     	  v2.0.5
# Date created:			  Sun Oct 12, 1997
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.2 1997/01/25 18:08:40 obrien Exp $
#

DISTNAME=	aub
PKGNAME=	aub-2.0.5
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.cdrom.com/pub/perl/CPAN/scripts/news/nntpstuff/aub/ \
		ftp://ftp.digital.com/pub/plan/perl/CPAN/scripts/news/nntpstuff/aub/ \
		ftp://ftp.perl.org/pub/CPAN/scripts/news/nntpstuff/aub/
DISTFILES=	aub aub.1 BUG_FIXES

MAINTAINER=	obrien@FreeBSD.ORG

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
MAN1=		aub.1

do-extract:
	@${MKDIR} ${WRKDIR}

pre-configure:
	@${SED} -e '1,1s:/usr/local/bin/perl:!/usr/bin/perl:' \
		-e 's:$SUM = "/bin/sum":$SUM = "/usr/bin/sum":' \
		${DISTDIR}/aub > ${WRKDIR}/aub

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/aub ${PREFIX}/bin
	${INSTALL_MAN} ${DISTDIR}/aub.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/aub
	${INSTALL_MAN} ${DISTDIR}/BUG_FIXES ${PREFIX}/share/doc/aub

#
# There is a patch to aub to run with perl5.
# You may find it in the files/ dir.
#

.include <bsd.port.mk>
