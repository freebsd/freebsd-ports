# New ports collection makefile for:	R (letter)
# Version required:		R-0.99.0a
# Date created:			Tue Jun 23 07:36:55 EST 1998
# Whom:				Maurice Castro <maurice@serc.rmit.edu.au>
#
# $FreeBSD$
#

DISTNAME=	R-0.99.0a
PKGNAME=	R-${PAPERSIZE}-0.99.0a
CATEGORIES=	math
MASTER_SITES=	http://lib.stat.cmu.edu/R/CRAN/src/base/ \
		ftp://ftp.biostat.washington.edu/mirrors/R/CRAN/src/base/ \
		http://cran.stat.wisc.edu/src/base/ \
		ftp://ftp.ci.tuwien.ac.at/R/src/base/ \
		http://SunSITE.auc.dk/R/src/base/ \
		http://www.stat.unipg.it/pub/stat/statlib/R/CRAN/src/base/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/base/ \
		ftp://dola.snu.ac.kr/pub/R/CRAN/src/base/ \
		http://www.stat.math.ethz.ch/R-CRAN/src/base/
EXTRACT_SUFX=	.tgz

MAINTAINER=	maurice@serc.rmit.edu.au

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_PERL5=	yes

CONFIGURE_ENV=		R_PAPERSIZE=${PAPERSIZE}

PAPERSIZE?=	letter
.if ${PAPERSIZE} != letter && ${PAPERSIZE} != a4
.BEGIN:
	@${ECHO} "Invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:  a4 and letter."
	@${FALSE}
.endif

ALL_TARGET=all help html

MAN1=	R.1

test:
	@(cd ${WRKSRC}; make test-All)

.include <bsd.port.mk>
