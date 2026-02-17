PORTNAME=	arpack-ng
DISTVERSION=	3.9.1
PORTREVISION=	5
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Revised Argand library for solving large-scale eigenvalue problems
WWW=		https://forge.scilab.org/index.php/p/arpack-ng/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpich.so:net/mpich # MPI is incremental: it adds the libparpack.so lib, it is a candidate for a sub-package

USES=		autoreconf fortran libtool localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	opencollab
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-blas="${BLASLIB}" \
		--with-lapack="${LAPACKLIB}" \
		--enable-mpi \
		--disable-static \
		--enable-icb
TEST_TARGET=	check
USE_LDCONFIG=	yes

PIE_UNSAFE=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

CONFLICTS_INSTALL=	arpack

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_SINGLE=		BLASLIB

OPTIONS_SINGLE_BLASLIB=	ATLAS NETLIB OPENBLAS
OPTIONS_DEFAULT=	NETLIB
ATLAS_USES=		blaslapack:atlas
NETLIB_USES=		blaslapack:netlib
OPENBLAS_USES=		blaslapack:openblas

pre-configure:
	cd ${WRKSRC} && ./bootstrap

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*arpack.so.*.*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/DOCUMENTS && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/EXAMPLES && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
