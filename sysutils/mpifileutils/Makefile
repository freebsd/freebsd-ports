PORTNAME=	mpifileutils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12
CATEGORIES=	sysutils parallel
MASTER_SITES=	https://github.com/hpc/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	rikka.goering@outlook.de
COMMENT=	MPI-based parallel file utilities (dcp, dcmp, ddup, dtar, etc.)
WWW=		https://hpc.github.io/mpifileutils/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/${PORTNAME}/LICENSE

LIB_DEPENDS=	libcircle.so:devel/libcircle \
		libdtcmp.so:devel/dtcmp

USES=		cmake localbase:ldflags mpi:openmpi pkgconfig ssl tar:tgz
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_C_COMPILER=${MPICC} \
		-DCMAKE_CXX_COMPILER=${MPICXX}
CMAKE_OFF=	ENABLE_GPFS ENABLE_LUSTRE ENABLE_XATTRS

LDFLAGS+=	-lcircle -ldtcmp

EXTRACT_AFTER_ARGS=	--exclude dtcmp \
			--exclude libcircle \
			--exclude lwgrp \
			--no-same-owner --no-same-permissions

PORTDOCS=	AUTHORS CONTRIBUTING.md DAOS-Support.md NOTICE README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/${PORTNAME}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
