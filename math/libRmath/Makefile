# ex: tabstop=8 softtabstop=0 noexpandtab
# Ports collection Makefile for:	libRmath
# Date created:				14 May 2004
# Whom:					Eric van Gyzen <vangyzen@stat.duke.edu>
#
# $FreeBSD$
#

PORTNAME=	libRmath
PORTVERSION=	1.9.1
CATEGORIES=	math
MASTER_SITES=	http://cran.r-project.org/src/base/ \
		ftp://cran.r-project.org/pub/R/src/base/ \
		http://cran.at.r-project.org/src/base/ \
		http://cran.au.r-project.org/src/base/ \
		http://cran.br.r-project.org/src/base/ \
		http://cran.ch.r-project.org/src/base/ \
		http://cran.es.r-project.org/src/base/ \
		http://cran.dk.r-project.org/src/base/ \
		http://cran.hu.r-project.org/src/base/ \
		http://cran.uk.r-project.org/src/base/ \
		http://cran.us.r-project.org/src/base/ \
		http://cran.za.r-project.org/src/base/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/base/ \
		http://lib.stat.cmu.edu/R/CRAN/src/base/ \
		http://cran.stat.ucla.edu/src/base/ \
		http://probability.ca/cran/src/base/ \
		http://www.ibiblio.org/pub/languages/R/CRAN/src/base/ \
		http://www.bioconductor.org/CRAN/src/base/
DISTNAME=	R-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	vangyzen@stat.duke.edu
COMMENT=	The standalone math library from R

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	include/Rmath.h lib/libRmath.a lib/libRmath.so lib/libRmath.so.0

do-build:
	(cd ${WRKSRC}/src/include; ${MAKE} Rmath.h)
	(cd ${WRKSRC}/src/nmath/standalone; ${MAKE})

do-install:
	${MKDIR} ${PREFIX}/include ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/include/Rmath.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/src/nmath/standalone/libRmath.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/src/nmath/standalone/libRmath.so \
		${PREFIX}/lib/libRmath.so.0
	(cd ${PREFIX}/lib; ${LN} -sf libRmath.so.0 libRmath.so)

.include <bsd.port.mk>
