# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	getdp
PORTVERSION=	2.2.1
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://www.geuz.org/getdp/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
EXTRACT_SUFX=	.tgz

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	A rather general finite element solver using mixed finite elements

LIB_DEPENDS=	gsl:${PORTSDIR}/math/gsl	\
		lapack.4:${PORTSDIR}/math/lapack

USE_GMAKE=	yes
USE_FORTRAN=	yes
GNU_CONFIGURE=	yes
# Using --enable-sparskit instead of math/petsc.  The maintainer couldn't get
# the math/petsc to work.  This is a bmake/gmake clash.
CONFIGURE_ARGS=	--with-gsl-prefix=${LOCALBASE}	\
		--with-blas-lapack-prefix=${LOCALBASE} \
		--enable-sparskit
WANT_PERL=	yes
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		getdp.1

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc && ${FIND} -s ${WRKSRC}/doc/* | ${SED} -e 's#${WRKSRC}/doc/##' | ${CPIO} -pmud -R ${BINOWN}:${BINGRP} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC}/demos && ${FIND} -s ${WRKSRC}/demos/* | ${SED} -e 's#${WRKSRC}/demos/##' | ${CPIO} -pmud -R ${BINOWN}:${BINGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.pre.mk>

.if defined(MAINTAINER_MODE)
regression-test:	install
	cd ${WRKSRC}/demos && yes "" | ${PORTNAME} magnet.pro -solve MagSta_phi
.endif

.include <bsd.port.post.mk>
