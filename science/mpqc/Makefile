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

MAINTAINER=	batman@udel.edu

LIB_DEPENDS=	blas:${PORTSDIR}/math/blas \
		lapack:${PORTSDIR}/math/lapack

USE_BISON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libdirs=-L${LOCALBASE}/lib
USE_PERL5=	yes
USE_GMAKE=	yes
ALL_TARGET=	# empty

post-patch:
	@${PERL} -pi -e "s,-lpthreads,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.include <bsd.port.mk>
