# New ports collection makefile for: cgi-lib.pl
# Version required:	2.18
# Date created:		29 Nov 1998
# Whom:			sada
#
# $FreeBSD$
#

DISTNAME=	cgi-lib
PKGNAME=	cgi-lib-2.18
CATEGORIES=	www
MASTER_SITES=	http://cgi-lib.stanford.edu/cgi-lib/2.18/
EXTRACT_SUFX=	.pl.txt

MAINTAINER=	sada@FreeBSD.ORG

EXTRACT_AFTER_ARGS= cgi-lib.pl
EXTRACT_BEFORE_ARGS=
EXTRACT_CMD=	${CP}
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PERL5=	yes

INSTALLDIR=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/cgi-lib.pl ${INSTALLDIR}/

.include <bsd.port.mk>
