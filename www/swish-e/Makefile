# New ports collection makefile for:    swish-e
# Version required:     		1.2.4
# Date created:         		23 Feb 98
# Whom:              			Daniel O'Connor <doconnor@gsoft.com.au>
#
# $Id$
#

DISTNAME=       swish-efiles.1.2.4
PKGNAME=        swish-e-1.2.4
CATEGORIES=     www textproc
MASTER_SITES=   ftp://sunsite.berkeley.edu/pub/swish-e/

MAINTAINER=	doconnor@gsoft.com.au

WRKSRC=		${WRKDIR}/src
USE_GMAKE=	yes

post-patch:

	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.pre_sed
	${SED} -e 's#/vol/moby/moby_a/gnu/sun4_sunos5.1/bin/gcc#${CC}#' \
		-e 's#\"-g\"#\"${CFLAGS}\"#g' \
		-e 's#CFLAGS= -O2#CFLAGS = \"${CFLAGS}\"#' \
		${WRKSRC}/Makefile.pre_sed >> ${WRKSRC}/Makefile

do-install:

	$(INSTALL_PROGRAM) ${WRKSRC}/swish-e ${PREFIX}/bin

.include <bsd.port.mk>
