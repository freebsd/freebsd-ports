# Ports collection Makefile for:	jags
# Date created:				21 April 2004
# Whom:					Eric van Gyzen <vangyzen@stat.duke.edu>
#
# $FreeBSD$
#

PORTNAME=	jags
PORTVERSION=	0.50
CATEGORIES=	math
MASTER_SITES=	http://www-fis.iarc.fr/~martyn/software/jags/
DISTNAME=	${PORTNAME:U}-${PORTVERSION}
.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} bugs-examples.tar.gz manual.pdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	vangyzen@stat.duke.edu
COMMENT=	Just Another Gibbs Sampler

LIB_DEPENDS=	Rmath.0:${PORTSDIR}/math/libRmath

.if defined(WITH_ATLAS)
LIB_DEPENDS+=	f77blas.1:${PORTSDIR}/math/atlas
CONFIGURE_ARGS=	--with-lapack=-lalapack --with-blas=-lf77blas
.else
LIB_DEPENDS+=	lapack.3:${PORTSDIR}/math/lapack
CONFIGURE_ARGS=	--with-lapack=-llapack --with-blas=-lblas
.endif

USE_BISON=	yes

DIST_SUBDIR=	${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${PREFIX}/include LDFLAGS=-L${PREFIX}/lib

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/manual.pdf ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	( cd ${EXAMPLESDIR}; \
	  ${PAX} -rzf ${DISTDIR}/${DIST_SUBDIR}/bugs-examples.tar.gz \
	    -s ':^bugs-examples/*::' )
.endif

.include <bsd.port.mk>
