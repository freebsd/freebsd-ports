# $FreeBSD$

PORTNAME=	namd
DISTVERSION=	2-12-211
DISTVERSIONSUFFIX=	-gfdf7ea56
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Computer software for molecular dynamics simulation

LICENSE=	NAMD_MOLECULAR_DYNAMICS_LICENSE
LICENSE_NAME=	NAMD Molecular Dynamics Software
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	no-auto-accept no-dist-mirror no-pkg-mirror # No redistribution is allowed.

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Not clear if it can be built on other architectures
BROKEN_i386=	need to fix the fft library handling

FETCH_DEPENDS=	git:devel/git
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
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}" ]; then \
	  ${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
	  cd ${DISTDIR}/${DIST_SUBDIR} && \
	    git clone -q ${GIT_URL} ${PORTNAME}-${DISTVERSIONFULL} && \
	    (cd ${PORTNAME}-${DISTVERSIONFULL} && git reset -q --hard ${DISTVERSIONFULL} && ${RM} -r .git) && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
	    ${FIND} ${PORTNAME}-${DISTVERSIONFULL} -print0 | LC_ALL=C ${SORT} -z | \
	        ${TAR} czf ${PORTNAME}-${DISTVERSIONFULL}${EXTRACT_SUFX} --format=bsdtar --uid 0 --gid 0 --options gzip:!timestamp --no-recursion --null -T - && \
	    ${RM} -r ${PORTNAME}-${DISTVERSIONFULL}; \
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
