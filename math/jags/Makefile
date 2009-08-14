# vim: tabstop=8 softtabstop=0 noexpandtab
# Ports collection Makefile for:	jags
# Date created:		21 April 2004
# Whom:			Eric van Gyzen <vangyzen@stat.duke.edu>
#
# $FreeBSD$
#

PORTNAME=	jags
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www-fis.iarc.fr/~martyn/software/jags/
DISTNAME=	${PORTNAME:U}-${PORTVERSION}
.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} classic-bugs.tar.gz jags_user_manual.pdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	bf1783@gmail.com
COMMENT=	Just Another Gibbs Sampler

LIB_DEPENDS=	Rmath.0:${PORTSDIR}/math/libRmath

.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
CONFIGURE_ARGS=	--with-lapack=-lalapack --with-blas=-lf77blas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
CONFIGURE_ARGS=	--with-lapack=-llapack --with-blas=-lblas
.endif

DIST_SUBDIR=	${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS=-L${LOCALBASE}/lib
USE_FORTRAN=	yes
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/etc/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/jags_user_manual.pdf \
		${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	( cd ${EXAMPLESDIR}; \
	  ${PAX} -rzf ${DISTDIR}/${DIST_SUBDIR}/classic-bugs.tar.gz \
	    -s ':^classic-bugs/*::' )
.endif

.include <bsd.port.mk>
