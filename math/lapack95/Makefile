# New ports collection makefile for:    lapack95
# Date created:                         5 Feb 2003
# Whom:                                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lapack95
PORTVERSION=	1.0
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/lapack95/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	lapack95

MAINTAINER=	maho@FreeBSD.org
COMMENT=	LAPACK95, Fortran90/95 wrapper for LAPACK

BUILD_DEPENDS=	${LOCALBASE}/intel_fc_80/bin/ifort:${PORTSDIR}/lang/ifc
LIB_DEPENDS=	atlas:${PORTSDIR}/math/atlas

WRKSRC=		${WRKDIR}/LAPACK95
FC=		${LOCALBASE}/intel_fc_80/bin/ifort
FORTRAN_FIXED=
FORTRAN_FREE=	-free
FFOPTFLAGS=	-O3 -tpp7 -xKW -Vaxlib
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,%%FC%%,${FC},g ; \
		 s,%%FORTRAN_FIXED%%,${FORTRAN_FIXED},g ; \
		 s,%%FORTRAN_FREE%%,${FORTRAN_FREE},g ; \
		 s,%%FFOPTFLAGS%%,${FFOPTFLAGS},g ; \
		 s,%%LOCALBASE%%,${LOCALBASE},g' \
		${WRKSRC}/make.inc
do-build:
	cd ${WRKSRC}/SRC; ${MAKE} single_double_complex_dcomplex

do-install:
	${INSTALL_DATA} ${WRKSRC}/lapack95.a ${PREFIX}/lib/liblapack95.a
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/EXAMPLES1
	@${MKDIR} ${EXAMPLESDIR}/EXAMPLES2
	${CP}	${WRKSRC}/make.inc ${EXAMPLESDIR}
	${TAR} cf - -C ${WRKSRC}/EXAMPLES1 . | ${TAR} xf - -C ${EXAMPLESDIR}/EXAMPLES1
	${TAR} cf - -C ${WRKSRC}/EXAMPLES2 . | ${TAR} xf - -C ${EXAMPLESDIR}/EXAMPLES2

.include <bsd.port.mk>
