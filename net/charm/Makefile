# $FreeBSD$

PORTNAME=	charm
DISTVERSION=	6.7.1
CATEGORIES=	net
PKGNAMESUFFIX=	-uiuc
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Message-passing parallel language and runtime system

LICENSE=	CHARMPP_CONVERSE_LICENSE
LICENSE_NAME=	Charm++/Converse License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	no-auto-accept no-dist-mirror no-pkg-mirror # No redistribution is allowed.

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Not clear if it can be built on other architectures

FETCH_DEPENDS=	git:devel/git
BUILD_DEPENDS=	bash:shells/bash

USES=		fortran gmake localbase:ldflags shebangfix tar
SHEBANG_GLOB=	*.sh
SHEBANG_FILES=	src/scripts/*
USE_LDCONFIG=	yes

GIT_URL=	https://charm.cs.illinois.edu/gerrit/charm.git

ARCH_STR=	linux${ARCH:S/amd64/64/:S/i386/32/}

INSTALL_WRKSRC=	${WRKSRC}/${VERSION}-${ARCH_STR}-gfortran-clang/tmp

BINARY_ALIAS=	gfortran=gfortran${GCC_DEFAULT}

OPTIONS_SINGLE=		MULTIPROCESSING
OPTIONS_SINGLE_MULTIPROCESSING=	MULTICORE ETHERNET MPI
OPTIONS_DEFAULT=	MULTICORE
MULTIPROCESSING_DESC=	Multiprocessing
OPTIONS_SUB=		yes

MULTICORE_DESC=		Single-node multicore version
MULTICORE_VARS=		VERSION=multicore

ETHERNET_DESC=		Ethernet version
ETHERNET_VARS=		VERSION=netlrts

MPI_VARS=		VERSION=mpi
MPI_LDFLAGS=		-lmpich
MPI_LIB_DEPENDS=	libmpich.so:net/mpich2

local-makesum: # Workaround: the generic 'make makesum' is broken when custom do-fetch is defined: it calls ${SCRIPTSDIR}/do-fetch.sh.
	@${MAKE} distclean fetch makesum

do-fetch:
	@if ! [ -f "${DISTDIR}/NAMD_2.12_Source.tar.gz" ]; then \
	  ${ECHO} "(!!)"; \
	  ${ECHO} "(!!) Please download the release tarball of the version 2.12 of NAMD (NAMD_2.12_Source.tar.gz)"; \
	  ${ECHO} "(!!) from https://www.ks.uiuc.edu/Development/Download/download.cgi?PackageName=NAMD,"; \
	  ${ECHO} "(!!) put it into ${DISTDIR}, and run 'make' again."; \
	  ${ECHO} "(!!)"; \
	  ${FALSE}; \
	fi
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	@cd ${DISTDIR}/${DIST_SUBDIR} && ${TAR} xf ${DISTDIR}/NAMD_2.12_Source.tar.gz --strip-components 1 NAMD_2.12_Source/charm-${DISTVERSION}.tar

post-patch:
	@${REINPLACE_CMD} 's|which gfortran |which gfortran${GCC_DEFAULT} |' ${WRKSRC}/src/arch/common/conv-mach-gfortran.sh
	@${FIND} ${WRKSRC} -name conv-mach.h | ${XARGS} ${REINPLACE_CMD} 's|CMK_THREADS_ARE_WIN32_FIBERS *1|CMK_THREADS_ARE_WIN32_FIBERS 0|'
	@${FIND} ${WRKSRC} -name "*.c" -o -name "*.C" -o -name "*.h" -o -name "configure" | \
		${XARGS} ${REINPLACE_CMD} -i '' 's|include <malloc\.h>|include <stdlib.h>|; s|include "malloc\.h"|include <stdlib.h>|'
	@${REINPLACE_CMD} -E 's|(CMK_CC)="(.*)"|\1="\2 ${CFLAGS} "|' ${WRKSRC}/src/arch/common/cc-clang.sh
	@${REINPLACE_CMD} -E 's|(CMK_CXX)="(.*)"|\1="\2 ${CXXFLAGS} "|' ${WRKSRC}/src/arch/common/cc-clang.sh
	@${REINPLACE_CMD} -E 's|(CMK_LD)="(.*)"|\1="\2 ${LDFLAGS} "|' ${WRKSRC}/src/arch/common/cc-clang.sh
	@${REINPLACE_CMD} -E 's|/lib/cpp|/usr/bin/cpp|' ${WRKSRC}/src/arch/*/*.sh
	@${REINPLACE_CMD} -E 's|-shared -o libqt\.so|-shared -o libqt.so -Wl,-soname,libqt.so|' ${WRKSRC}/src/QuickThreads/mkfiles/*

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./build charm++ ${VERSION}-${ARCH_STR} clang gfortran --build-shared -j${MAKE_JOBS_NUMBER} ${CFLAGS}

post-install:
.for d in bin include lib
	@cd ${STAGEDIR} && ${MV} ${d}/* ./${PREFIX}/${d} && ${RMDIR} $d
.endfor
	@cd ${STAGEDIR} && ${MV} lib_so/* ./${PREFIX}/lib && ${RMDIR} lib_so

.include <bsd.port.mk>
