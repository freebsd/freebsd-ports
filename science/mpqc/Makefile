# New ports collection makefile for:	mpqc
# Date created:				27 April 2001
# Whom:					batman <batman@udel.edu>
#
# $FreeBSD$
#

PORTNAME=	mpqc
PORTVERSION=	2.1.1
CATEGORIES=	science
MASTER_SITES=	http://aros.ca.sandia.gov/~cljanss/mpqc/distrib/

MAINTAINER=	chat95@mbox.kyoto-inet.or.jp

LIB_DEPENDS=	lapack:${PORTSDIR}/math/lapack \
		atlas:${PORTSDIR}/math/atlas

USE_BISON=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--with-libdirs=-L${PREFIX}/lib \
		--with-blas="-lf77blas -latlas" \
		--with-lapack="-lalapack -lcblas" \
		--with-coptflags="${CFLAGS}" \
		--with-cxxoptflags="${CFLAGS}" \
		--with-f77optflags="${FFLAGS}"
USE_PERL5=	yes
USE_GMAKE=	yes
ALL_TARGET=	# empty

pre-configure:
	@${ECHO} "You can override and CFLAGS on the command line."
	@${ECHO} "Following is a recommended one."
	@${ECHO} "make CFLAGS=\"-malign-double -fexpensive-optimizations -O4 -ffast-math -funroll-loops\""

.include <bsd.port.mk>
