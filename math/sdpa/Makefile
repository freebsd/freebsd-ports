PORTNAME=	sdpa
DISTVERSION=	7.3.17
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME} \
		DEBIAN/pool/main/m/mumps:mumps
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX} \
		mumps_${MUMPS_VERSION}.orig.tar.gz:mumps
DIST_SUBDIR=	sdpa
EXTRACT_ONLY=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Very efficient SDP (semidefinite programming) solver
WWW=		https://sdpa.sourceforge.net/

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fortran gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-blas="-L${LOCALBASE}/lib ${BLASLIB}" \
		--with-lapack="-L${LOCALBASE}/lib ${LAPACKLIB}"

PORTDOCS=	${MANUALFILE}
PLIST_FILES=	bin/sdpa %%DATADIR%%/param.sdpa

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		BLAS
OPTIONS_SINGLE_BLAS=	ATLAS REFERENCE
OPTIONS_DEFAULT=	REFERENCE

ATLAS_USES=		blaslapack:atlas
DOCS_DISTFILES=		${MANUALFILE}
REFERENCE_DESC=		Reference blas implementation
REFERENCE_USES=		blaslapack

MANUALFILE=		sdpa.7.1.1.manual.20080618.pdf

MUMPS_VERSION=		5.5.1

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Type mismatch in argument 's' at (1); passed INTEGER(4) to LOGICAL(4)
CONFIGURE_ARGS+=	FCFLAGS=-fallow-argument-mismatch
.endif

post-extract:
	@(cd ${DISTDIR}/${DIST_SUBDIR} && ${PAX} -rw \
		mumps_${MUMPS_VERSION}.orig.tar.gz ${WRKSRC}/mumps)

post-patch:
# Register missing target dependency to unbreak parallel builds
	@${REINPLACE_CMD} -e 's,^sdpa_DEPENDENCIES =,& $$(lib_LIBRARIES),' \
		${WRKSRC}/Makefile.in
.for i in sdpa.1 sdpa_exe.cpp
	@${REINPLACE_CMD} -e \
		's|/usr/share/sdpa/|${DATADIR}/|' ${WRKSRC}/${i}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdpa ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA}    ${WRKSRC}/param.sdpa ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${MANUALFILE} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
