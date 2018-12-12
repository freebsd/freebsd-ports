# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	PETSc
DISTVERSION=	3.10.2
PORTREVISION=	1
CATEGORIES=	science devel
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/petsc/release-snapshots/
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Suite of data structures and routines from Argonne National Laboratory

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to build: MPI compiler wrappers do not work. See http://www.mcs.anl.gov/petsc/documentation/faq.html#mpi-compilers
BROKEN_armv6=		fails to build: MPI compiler wrappers do not work. See http://www.mcs.anl.gov/petsc/documentation/faq.html#mpi-compilers
BROKEN_armv7=		fails to build: MPI compiler wrappers do not work. See http://www.mcs.anl.gov/petsc/documentation/faq.html#mpi-compilers
BROKEN_powerpc64=	fails to build: MPI compiler wrappers do not work. See http://www.mcs.anl.gov/petsc/documentation/faq.html#mpi-compilers

LIB_DEPENDS=	libmpich.so:net/mpich

USES=		blaslapack fortran gmake python:2.7 shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-shared-libraries=1 \
		--with-mpi-dir=${LOCALBASE} \
		CFLAGS="${CFLAGS} -msse2" CXXFLAGS="${CXXFLAGS} -msse2" CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" LIBS=""
USE_XORG=	x11
MAKEFILE=	makefile
SHEBANG_FILES=	lib/petsc/bin/*.py lib/petsc/bin/saws/SAWs.py lib/petsc/bin/saws/*.bash config/*.py
USE_LDCONFIG=	yes
TEST_TARGET=	test
BINARY_ALIAS=	python=${PYTHON_CMD}

LDFLAGS+=	${LOCALBASE}/lib/libmpi.so

DATADIR=	${PREFIX}/share/${PORTNAME:tl}
PLIST_SUB=	SHLIB=${DISTVERSION} SHL=${DISTVERSION:C/\.[0-9]$//}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpetsc.so.${DISTVERSION}
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.html" -delete
	@cd ${STAGEDIR}${PREFIX} && ${RM} -r bin/win32fe lib/petsc/conf/uninstall.py
	@${REINPLACE_CMD} -i '' -e 's|^PYTHON = .*|PYTHON = ${PYTHON_CMD}|' ${STAGEDIR}${PREFIX}/lib/petsc/conf/petscvariables
	@${REINPLACE_CMD} -i '' -e 's|#!/.*|#!${PYTHON_CMD}|' ${STAGEDIR}${PREFIX}/lib/petsc/conf/reconfigure-arch-*-c-debug.py
	@${RM} -r ${STAGEDIR}${DATADIR}/examples # examples are a mess as installed

.include <bsd.port.mk>
