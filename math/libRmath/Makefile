# vim: tabstop=8 softtabstop=0 noexpandtab
# Ports collection makefile for:	libRmath
# Date created:		14 May 2004
# Whom:			Eric van Gyzen <vangyzen@stat.duke.edu>
#
# $FreeBSD$
#

PORTNAME=	libRmath
PORTVERSION=	2.9.1
PORTREVISION=	1
CATEGORIES=	math
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
DISTNAME=	R-${PORTVERSION}

MAINTAINER=	bf1783@gmail.com
COMMENT=	The standalone math library from R

USE_PERL5_BUILD=	yes
USE_FORTRAN=		yes
GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes
CONFIGURE_ARGS+=--with-readline=no --with-x=no --disable-mbcs --disable-nls --with-tcltk=no --with-cairo=no \
		--with-libpng=no --with-jpeglib=no --with-iconv=no --with-ICU=no --without-libintl-prefix
BUILD_WRKSRC=		${WRKSRC}/src/nmath/standalone

PLIST_FILES=	include/Rmath.h lib/libRmath.a lib/libRmath.so lib/libRmath.so.0

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/src/nmath/standalone/Makefile.in
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" \
		${WRKSRC}/configure \
		${WRKSRC}/config.site

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/include/Rmath.h ${PREFIX}/include
	${INSTALL_DATA} ${BUILD_WRKSRC}/libRmath.a ${PREFIX}/lib
	${INSTALL_DATA} ${BUILD_WRKSRC}/libRmath.so \
		${PREFIX}/lib/libRmath.so.0
	(cd ${PREFIX}/lib; ${LN} -sf libRmath.so.0 libRmath.so)

test: install
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} test && ${BUILD_WRKSRC}/test)

.include <bsd.port.mk>
