# ex: ts=8 sts=0 noet
# New ports collection makefile for:	R (letter)
# Date created:			Fri Feb  9 10:50:25 EST 2001
# Whom:				Maurice Castro <maurice@serc.rmit.edu.au>
#
# $FreeBSD$
#

PORTNAME=	R
PORTVERSION=	1.8.1
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
PKGNAMESUFFIX=	-${PAPERSIZE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	vangyzen@stat.duke.edu
COMMENT=	A language for statistical computing and graphics

CONFLICTS?=	R-a4-*

LIB_DEPENDS=	tcl84:${PORTSDIR}/lang/tcl84 \
		tk84:${PORTSDIR}/x11-toolkits/tk84 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		pcre.0:${PORTSDIR}/devel/pcre

.if defined(WITH_ATLAS)
LIB_DEPENDS+=	f77blas.1:${PORTSDIR}/math/atlas
CONFIGURE_ARGS=	--with-lapack="-lalapack -lcblas" --with-blas="-lf77blas"
.else
LIB_DEPENDS+=	lapack.3:${PORTSDIR}/math/lapack
CONFIGURE_ARGS=	--with-lapack="-llapack" --with-blas="-lblas"
.endif

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_PERL5=	yes
CONFIGURE_ENV=	R_PAPERSIZE=${PAPERSIZE} FFLAGS="${FFLAGS}" \
		INSTALL_DATA="${INSTALL} ${COPY} ${_SHROWNGRP} -m 644"
CONFIGURE_ARGS+=--enable-R-shlib

PAPERSIZE?=	letter
.if ${PAPERSIZE} != letter && ${PAPERSIZE} != a4
.BEGIN:
	@${ECHO} "Invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are: a4 letter"
	@${FALSE}
.endif

MAN1=	R.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Broken pkg-plist"
.endif

test check: build
	@(cd ${WRKSRC}; ${MAKE} check)
check-all: build
	@(cd ${WRKSRC}; ${MAKE} check-all)

.include <bsd.port.post.mk>
