PORTNAME=	PETSc
DISTVERSION=	3.22.4
PORTREVISION=	1
CATEGORIES=	science devel
MASTER_SITES=	https://web.cels.anl.gov/projects/petsc/download/release-snapshots/
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Suite of data structures and routines from Argonne National Laboratory
WWW=		https://petsc.org/release/ \
		https://gitlab.com/petsc/petsc \
		https://github.com/petsc/petsc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblis.so:math/blis \
		libmpich.so:net/mpich

USES=		blaslapack cmake:indirect fortran gmake python shebangfix xorg
USE_LDCONFIG=	yes
USE_XORG=	x11

SHEBANG_FILES=	configure lib/petsc/bin/*.py lib/petsc/bin/saws/SAWs.py lib/petsc/bin/saws/*.bash config/*.py	\
		lib/petsc/bin/petscnagfor share/petsc/chkerrconvert.py

XARCH!=		uname -p

GNU_CONFIGURE=	yes
CONFIGURE_LOG=	configure.log
CONFIGURE_ARGS=	--with-shared-libraries=1 \
		--with-mpi-dir=${LOCALBASE} \
		--with-python=1 --with-python-pkg-config=${LOCALBASE}/libdata/pkgconfig \
		FCFLAGS="${FCFLAGS}" FFLAGS="${FCFLAGS}"	\
		${CONFIGURE_ARGS_${ARCH}} CPPFLAGS="${CPPFLAGS}" \
		AR=${AR} RANLIB=${RANLIB} \
		MAKEFLAGS="${MAKEFLAGS}" LDFLAGS="${LDFLAGS}" LIBS=""
CONFIGURE_ARGS_amd64=	CFLAGS="${CFLAGS} -msse2" CXXFLAGS="${CXXFLAGS} -msse2"
CONFIGURE_ARGS_i386=	CFLAGS="${CFLAGS} -msse2" CXXFLAGS="${CXXFLAGS} -msse2"
.if ${XARCH:M*64*} # match IDXTYPEWIDTH being set to 64 in math/metis
CONFIGURE_ARGS+=	--with-64-bit-indices # as opposed to 32-bit indices that are default
.endif

MAKEFILE=	makefile
TEST_TARGET=	test # 152 of 11396 tests (1.3%) fail due to missing files like /usr/local/share/petsc/datafiles/meshes/square_periodic.msh (tests expect the packe to be installed)

LDFLAGS+=	${LOCALBASE}/lib/libmpi.so

DATADIR=	${PREFIX}/share/${PORTNAME:tl}
BINARY_ALIAS=	python=${PYTHON_CMD}

PLIST_SUB=	SHLIB=${DISTVERSION} SHL=${DISTVERSION:C/\.[0-9]$//}

OPTIONS_DEFINE=		METIS
OPTIONS_DEFAULT=	METIS

METIS_DESC=		Enable metis support for graph partitioning algorithms

METIS_LIB_DEPENDS=	libmetis.so:math/metis
METIS_CONFIGURE_ON=	--with-metis=1 # --with-parmetis=1 to use include/parmetis.h

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpetsc.so.${DISTVERSION}
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.html" -delete
	@cd ${STAGEDIR}${PREFIX} && ${RM} -r bin/win32fe lib/petsc/conf/uninstall.py
	@${REINPLACE_CMD} -i '' -e 's|^PYTHON = .*|PYTHON = ${PYTHON_CMD}|' ${STAGEDIR}${PREFIX}/lib/petsc/conf/petscvariables
	@${REINPLACE_CMD} -i '' -e 's|#!/.*|#!${PYTHON_CMD}|' ${STAGEDIR}${PREFIX}/lib/petsc/conf/reconfigure-arch-*-c-debug.py
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/petsc/bin/__pycache__ # stray directory

# the file /usr/local/share/petsc/examples/config/gmakegen.py is expected by some dependencies, at least by math/slepc

.include <bsd.port.mk>
