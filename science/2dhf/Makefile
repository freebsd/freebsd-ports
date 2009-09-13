# New ports collection makefile for:	2dhf
# Date created:				24 July 2003
# Whom:					NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	2dhf
PORTVERSION=	2005.05
PORTREVISION=	4
CATEGORIES=	science
MASTER_SITES=	http://www.fizyka.umk.pl/~jkob/2dhf/
DISTNAME=	${PORTNAME}-05.05
EXTRACT_SUFX=	.tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A Numerical Hartree-Fock Program for Diatomic Molecules

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
.if defined(WITH_INTEL)
USE_FORTRAN=	ifort
BUILD_DEPENDS+=  ${LOCALBASE}/intel_cc_80/bin/icc:${PORTSDIR}/lang/icc
.endif

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
.endif

USE_FORTRAN=	yes

.if defined(WITH_OPTIMIZED_FLAGS)
FFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double
.if (${MACHINE_ARCH} == "i386")
FFLAGS+=	-mfancy-math-387
.endif # i386
.endif

.if defined(WITH_INTEL)
FC=		${LOCALBASE}/intel_fc_80/bin/ifort
CC=		${LOCALBASE}/intel_cc_80/bin/icc
FFLAGS=		-O3 -tpp7 -xKW -Vaxlib
FFLAGS_ADD=	-w -132
CFLAGS=		-O3 -tpp7 -xKW -Vaxlib
BLAS+=		-lg2c -lm
.else
FFLAGS_ADD=	-w -ffixed-line-length-none
.endif
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
ALL_TARGET=	all

pre-everything::
	@${ECHO_CMD} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."

do-extract:
	${MKDIR} ${WRKSRC}
	@(cd ${WRKSRC} ;  ${TAR} xfz ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})

post-patch:
	@${REINPLACE_CMD} -e 's,%%FC%%,${FC},g ; \
	s,%%FFLAGS%%,${FFLAGS},g ; \
	s,%%FFLAGS_ADD%%,${FFLAGS_ADD},g ; \
	s,%%CC%%,${CC},g ; \
	s,%%CFLAGS%%,${CFLAGS},g ; \
	s,%%LOCALBASE%%,${LOCALBASE},g ;\
	s,%%BLAS%%,${BLAS},g' \
	 ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
	 ${WRKSRC}/bin/xhf

do-install:
	@cd ${WRKSRC} ; ${INSTALL_PROGRAM} bin/x2dhf ${PREFIX}/bin/x2dhf
	@cd ${WRKSRC} ; ${INSTALL_SCRIPT}  bin/xhf   ${PREFIX}/bin/xhf
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc ; ${INSTALL_DATA} 2dhf.pdf users-guide.pdf users-guide.html ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples/ ; ${TAR} -chf - . | \
		${TAR} -xf - -C ${EXAMPLESDIR}
.endif
.include <bsd.port.mk>
