# New ports collection makefile for:	R (letter)
# Date created:			Fri Feb  9 10:50:25 EST 2001
# Whom:				Maurice Castro <maurice@serc.rmit.edu.au>
#
# $FreeBSD$
#

PORTNAME=	R
PORTVERSION=	1.6.1
CATEGORIES=	math
MASTER_SITES=	http://cran.r-project.org/src/base/ \
		ftp://cran.r-project.org/pub/R/src/base/ \
		http://cran.at.r-project.org/src/base/ \
		http://cran.ch.r-project.org/src/base/ \
		http://cran.dk.r-project.org/src/base/ \
		http://cran.hu.r-project.org/src/base/ \
		http://cran.uk.r-project.org/src/base/ \
		http://cran.us.r-project.org/src/base/ \
		http://mirror.aarnet.edu.au/CRAN/src/base/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/base/ \
		ftp://dola.snu.ac.kr/pub/R/CRAN/src/base/ \
		http://lib.stat.cmu.edu/R/CRAN/src/base/
PKGNAMESUFFIX=	-${PAPERSIZE}
DISTNAME=	R-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	maurice@serc.rmit.edu.au

LIB_DEPENDS=	tcl84:${PORTSDIR}/lang/tcl84 \
		tk84:${PORTSDIR}/x11-toolkits/tk84

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_PERL5=	yes
CONFIGURE_ENV=	R_PAPERSIZE=${PAPERSIZE}

PAPERSIZE?=	letter
.if ${PAPERSIZE} != letter && ${PAPERSIZE} != a4
.BEGIN:
	@${ECHO} "Invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:  a4 and letter."
	@${FALSE}
.endif

#ALL_TARGET=	all help html

MAN1=	R.1

test:
	@(cd ${WRKSRC}; make test-All)

.include <bsd.port.mk>
