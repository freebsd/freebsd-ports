# $FreeBSD$

PORTNAME=	namd
DISTVERSION=	2.12
CATEGORIES=	science
DISTNAME=	${PORTNAME:tu}_${DISTVERSION}_Source

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Computer software for molecular dynamics simulation

LICENSE=	NAMD_MOLECULAR_DYNAMICS_LICENSE
LICENSE_NAME=	NAMD Molecular Dynamics Software
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	no-auto-accept no-dist-mirror no-pkg-mirror # No redistribution is allowed.

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Not clear if it can be built on other architectures
BROKEN_i386=	need to fix the fft library handling

BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libck.so:net/charm \
		libfftw3f.so:math/fftw3-float

USES=		fortran gmake localbase:ldflags python:build shebangfix tcl
SHEBANG_FILES=	config

GIT_URL=	https://charm.cs.illinois.edu/gerrit/namd.git

ARCH_STR=	Linux-${ARCH:S/amd64/x86_64/:S/i386/x86/}-g++
ARCH_STR_CHARM=	linux${ARCH:S/amd64/64/:S/i386/32/}

PATCH_WRKSRC=	${WRKSRC}
BUILD_WRKSRC=	${WRKSRC}/${ARCH_STR}

CFLAGS+=	-D_NO_MALLOC_H -D_NO_ALLOCA_H
CXXFLAGS+=	-D_NO_MALLOC_H -D_NO_ALLOCA_H

BINARY_ALIAS=	gcc=${CC} g++=${CXX}

PLIST_FILES=	bin/flipbinpdb \
		bin/flipdcd \
		bin/namd2 \
		bin/psfgen \
		bin/sortreplicas

local-makesum: # Workaround: the generic 'make makesum' is broken when custom do-fetch is defined: it calls ${SCRIPTSDIR}/do-fetch.sh.
	@${MAKE} distclean fetch makesum

do-fetch:
	@if ! [ -f "${DISTDIR}/${DISTFILES}" ]; then \
	  ${ECHO} "(!!)"; \
	  ${ECHO} "(!!) Please download the release tarball of the version ${DISTVERSION} (${DISTFILES})"; \
	  ${ECHO} "(!!) from https://www.ks.uiuc.edu/Development/Download/download.cgi?PackageName=NAMD,"; \
	  ${ECHO} "(!!) put it into ${DISTDIR}, and run 'make' again."; \
	  ${ECHO} "(!!)"; \
	  ${FALSE}; \
	fi

do-configure:
	@cd ${WRKSRC} && ${ECHO} "CHARMBASE=${LOCALBASE}" > Make.config
	@cd ${WRKSRC} && ./config ${ARCH_STR} --charm-arch multicore-${ARCH_STR_CHARM} ${ARCH:S/amd64/--with-fftw3/:S/${ARCH}//}
	@${REINPLACE_CMD} 's|CHARMBASE = .*|CHARMBASE = ${LOCALBASE}|' ${WRKSRC}/Make.charm
	@${REINPLACE_CMD} '\
		s|FFTDIR=.*|FFTDIR=${LOCALBASE}|; \
		s|-lsfftw|-lfft3f|; \
		s|-lsrfftw|-lrfft3f|; \
		s|TCLDIR=.*|TCLDIR=${LOCALBASE}/include/tcl8.6|; \
		s|TCLINCL=.*|TCLINCL=-I${LOCALBASE}/include/tcl8.6|; \
		s|TCLLIB=.*|TCLLIB=-L${LOCALBASE}/lib -ltcl86 -lpthread|' \
		${WRKSRC}/arch/Linux*

do-install:
.for e in namd2 flipbinpdb flipdcd psfgen sortreplicas
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${e} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
