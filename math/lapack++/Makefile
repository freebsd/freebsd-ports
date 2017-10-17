# Created by: NAKATA Maho <chat95@mbox.kyoto-inet.or.jp>
# $FreeBSD$

PORTNAME=	lapack++
PORTVERSION=	2.5.4
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	SF/lapackpp \
		http://math.nist.gov/lapack++/:doc
DISTNAME=	lapackpp-${PORTVERSION}
DIST_SUBDIR=	lapackpp
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Linear Algebra PACKage in C++, a wrapper for LAPACK

USES=		fortran gmake pathfix libtool

OPTIONS_DEFINE=	DOCS

OPTIONS_RADIO=  BLAS
OPTIONS_RADIO_BLAS=     OPENBLAS NETLIB ATLAS
OPTIONS_DEFAULT=        OPENBLAS

OPENBLAS_USES=  blaslapack:openblas
NETLIB_USES=    blaslapack:netlib
ATLAS_USES=     blaslapack:atlas

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
BLAS_LIB=	-L${LOCALBASE}/lib ${BLASLIB}
LAPACK_LIB=	-L${LOCALBASE}/lib ${LAPACKLIB}

#lapack++ forces to use atlas when detected, so we should disable here.
CONFIGURE_ARGS+=	--with-blas="${BLAS_LIB}" --with-lapack="${LAPACK_LIB}" --disable-atlas --enable-static

DOCS_DISTFILES=	lapack++.ps.gz:doc lapackpp1_1.ps.gz:doc lapackppman1_1.ps.gz:doc lapack++_install.ps.gz:doc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapack++.ps.gz ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapack++_install.ps.gz ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapackpp1_1.ps.gz ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/lapackppman1_1.ps.gz ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
