# ex: ts=8 sts=0 noet
# New ports collection makefile for:	R
# Date created:			Fri Feb  9 10:50:25 EST 2001
# Whom:				Maurice Castro <maurice@serc.rmit.edu.au>
#
# $FreeBSD$
#

PORTNAME=	R
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	math lang
MASTER_SITES=	http://cran.r-project.org/src/base/R-2/ \
		ftp://cran.r-project.org/pub/R/src/base/R-2/ \
		http://cran.at.r-project.org/src/base/R-2/ \
		http://cran.au.r-project.org/src/base/R-2/ \
		http://cran.br.r-project.org/src/base/R-2/ \
		http://cran.ch.r-project.org/src/base/R-2/ \
		http://cran.es.r-project.org/src/base/R-2/ \
		http://cran.dk.r-project.org/src/base/R-2/ \
		http://cran.hu.r-project.org/src/base/R-2/ \
		http://cran.uk.r-project.org/src/base/R-2/ \
		http://cran.us.r-project.org/src/base/R-2/ \
		http://cran.za.r-project.org/src/base/R-2/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/base/R-2/ \
		http://lib.stat.cmu.edu/R/CRAN/src/base/R-2/ \
		http://cran.stat.ucla.edu/src/base/R-2/ \
		http://probability.ca/cran/src/base/R-2/ \
		http://www.ibiblio.org/pub/languages/R/CRAN/src/base/R-2/ \
		http://www.bioconductor.org/CRAN/src/base/R-2/

MAINTAINER=	vangyzen@stat.duke.edu
COMMENT=	A language for statistical computing and graphics

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

MAN1=		R.1

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_PERL5=	yes
CONFIGURE_ENV=	FFLAGS="${FFLAGS}" \
		INSTALL_DATA="${INSTALL} ${COPY} ${_SHROWNGRP} -m 644"
CONFIGURE_ARGS+=--enable-R-shlib --with-bzlib --with-pcre --with-zlib

pre-fetch:
.if !defined(PAPERSIZE)
	@${ECHO}
	@${ECHO} "    The default paper size for printing from R is A4."
	@${ECHO} "    You can change it by setting the PAPERSIZE"
	@${ECHO} "    make variable to one of:"
	@${ECHO} "        a4 letter legal executive"
	@${ECHO} "    For example:"
	@${ECHO} "        # make PAPERSIZE=letter install clean"
	@${ECHO}
.else
CONFIGURE_ENV+=	R_PAPERSIZE=${PAPERSIZE}
.endif

test check: build
	@(cd ${WRKSRC}; ${MAKE} check)
check-all: build
	@(cd ${WRKSRC}; ${MAKE} check-all)

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
CONFIGURE_ARGS+=	--disable-mbcs
.endif

.if ${OSVERSION} < 600000
CONFIGURE_ENV+=	MAKEINFO_CMD=${LOCALBASE}/bin/makeinfo
BUILD_DEPENDS+=	${LOCALBASE}/bin/makeinfo:${PORTSDIR}/print/texinfo
.endif

.include <bsd.port.post.mk>
