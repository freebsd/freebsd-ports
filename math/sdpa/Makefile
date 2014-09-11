# Created by: NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdpa
PORTVERSION=	7.3.1
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	http://sdpa.indsys.chuo-u.ac.jp/sdpa/files/
DISTNAME=	${PORTNAME}.${PORTVERSION}.src-${SRCDATE}
DIST_SUBDIR=	sdpa

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very efficient SDP (semidefinite programming) solver

USES=		fortran gmake

SRCDATE=	20090729
MANUALFILE=	sdpa7-manual.pdf
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}.src
OPTIONS_DEFINE=	DOCS

.if exists(${LOCALBASE}/lib/libgoto2.so)
WITH_BLAS?=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

. if ${WITH_BLAS} == reference
LIB_DEPENDS+=	libblas.so:${PORTSDIR}/math/blas
LIB_DEPENDS+=	liblapack.so:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${WITH_BLAS} == gotoblas
LIB_DEPENDS+=	libgoto2.so:${PORTSDIR}/math/gotoblas
LIB_DEPENDS+=	liblapack.so:${PORTSDIR}/math/lapack
BLAS=		-lgoto2p
LAPACK=
.elif ${WITH_BLAS} == atlas
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas
LAPACK=		-lalapack -lptcblas
.endif

CONFIGURE_ARGS+=--with-blas="-L${LOCALBASE}/lib ${BLAS}" --with-lapack="-L${LOCALBASE}/lib ${LAPACK}"

PLIST_SUB+=	MANUALFILE=${MANUALFILE}

post-patch:
# Register missing target dependency to unbreak parallel builds
	@${REINPLACE_CMD} -e 's,^sdpa_DEPENDENCIES =,& $$(lib_LIBRARIES),' \
		${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdpa ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA}    ${WRKSRC}/param.sdpa ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${MANUALFILE} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
