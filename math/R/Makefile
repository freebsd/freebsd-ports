# New ports collection makefile for:	R (letter)
# Date created:			Fri Feb  9 10:50:25 EST 2001
# Whom:				Maurice Castro <maurice@serc.rmit.edu.au>
#
# $FreeBSD$
#

PORTNAME=	R
PORTVERSION=	1.7.0
CATEGORIES=	math
MASTER_SITES=	http://cran.r-project.org/src/base/ \
		ftp://cran.r-project.org/pub/R/src/base/ \
		http://cran.at.r-project.org/src/base/ \
		http://cran.au.r-project.org/src/base/ \
		http://cran.ch.r-project.org/src/base/ \
		http://cran.dk.r-project.org/src/base/ \
		http://cran.hu.r-project.org/src/base/ \
		http://cran.uk.r-project.org/src/base/ \
		http://cran.us.r-project.org/src/base/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/base/ \
		http://lib.stat.cmu.edu/R/CRAN/src/base/
PKGNAMESUFFIX=	-${PAPERSIZE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	vangyzen@stat.duke.edu
COMMENT=	A language for statistical computing and graphics

LIB_DEPENDS=	tcl84:${PORTSDIR}/lang/tcl84 \
		tk84:${PORTSDIR}/x11-toolkits/tk84

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_PERL5=	yes
CONFIGURE_ENV=	R_PAPERSIZE=${PAPERSIZE} \
		INSTALL_DATA="${INSTALL} ${COPY} ${_SHROWNGRP} -m 644"

PAPERSIZE?=	letter
.if ${PAPERSIZE} != letter && ${PAPERSIZE} != a4
.BEGIN:
	@${ECHO} "Invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:  a4 and letter."
	@${FALSE}
.endif

MAN1=	R.1

.include <bsd.port.pre.mk>

#.if ${OSVERSION} >= 500113
#BROKEN=         "Does not compile"
#.endif

test check: build
	@(cd ${WRKSRC}; make check)

.include <bsd.port.post.mk>
