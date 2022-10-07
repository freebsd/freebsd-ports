PORTNAME=	gap
DISTVERSION=	4.12.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/gap-system/gap/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	System for computational discrete algebra
WWW=		https://www.gap-system.org/

LICENSE=	GPLv2+

BROKEN_aarch64=		fails to link: undefined reference to SyAllocBags
BROKEN_riscv64=		fails to link: undefined reference to SyAllocBags

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		gmake libtool localbase perl5 readline shebangfix
USE_PERL5=	run

SHEBANG_FILES=	.

GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	all
INSTALL_TARGET=	install-headers install-libgap
USE_LDCONFIG=	yes

ACLOCVER=	1.16	# Truncated version of aclocal / automake

.include <bsd.port.options.mk>

pre-configure:
# Avoid conflict with C++20 <version> by ignoring <...> under WRKSRC
	${REINPLACE_CMD} -i .c++20 's/-I/-iquote/' \
		${WRKSRC}/pkg/*/Makefile.in
.for f in aclocal.m4 configure
	${FIND} ${WRKSRC} -name ${f} | ${XARGS} ${REINPLACE_CMD} -i ''	\
		-e "s|am__api_version='1.15'|am__api_version='${ACLOCVER}'|"
.endfor

post-build:
	@cd ${WRKSRC}/pkg/simpcomp && \
		${SETENV} ${CONFIGURE_ENV} ${SH} configure \
			${CONFIGURE_ARGS:N--with-*} && \
		${MAKE} ${MAKEFLAGS} && \
		${MAKE} ${MAKEFLAGS} install-strip && \
		${RM} bistellar

post-install:
	# install gap binary
	${INSTALL_PROGRAM} ${WRKSRC}/gap ${STAGEDIR}${PREFIX}/bin/gap-bin
	## install gac executable - GAC is disabled since the project can't install it properly
	#${INSTALL_SCRIPT} ${WRKSRC}/gac ${STAGEDIR}${PREFIX}/bin/gac
	#${REINPLACE_CMD} -i '' -e 's|^\. "${WRKSRC}/sysinfo.gap"|. "${DATADIR}/sysinfo.gap"|' ${STAGEDIR}${PREFIX}/bin/gac
	# prepare and install wrapper
	@${CAT} ${WRKSRC}/bin/gap.sh | ${SED} -e ' \
		s:${WRKSRC}:${GAP_LIBDIR}:; \
		s:GAP_DIR=.*:GAP_DIR=${DATADIR}:; \
		s:GAP_EXE=.*:GAP_EXE=${PREFIX}/bin/gap-bin:; \
		/^exec/s:/gap::; \
		' > ${WRKSRC}/bin/gap
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gap ${STAGEDIR}${PREFIX}/bin
	## min-builddir
	#${MKDIR} ${STAGEDIR}${DATADIR}/min-builddir
	#${INSTALL_SCRIPT} ${WRKSRC}/libtool ${STAGEDIR}${DATADIR}/min-builddir
	#${RLN} ${STAGEDIR}${PREFIX}/bin/gap ${STAGEDIR}${DATADIR}/min-builddir/gap
	#cd ${WRKSRC}/build && ${COPYTREE_SHARE} obj ${STAGEDIR}${DATADIR}/min-builddir/
	# install files/directories
.for f in doc etc grp lib tst sysinfo.gap
	${CP} -R ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}/
.endfor
	# install packages
	cd ${WRKSRC} && ${COPYTREE_SHARE} pkg ${STAGEDIR}${DATADIR}
	# correct paths in sysinfo.gap
	${REINPLACE_CMD} -i '' -e ' \
		s|^GAP=.*|GAP="${PREFIX}/bin/gap"|; \
		s|^GAC=.*|GAP="${PREFIX}/bin/gac"|; \
		s|^GAP_CXXFLAGS=.*|GAP_CXXFLAGS="-I"|; \
		s| -isystem ${PREFIX}/include |&-I${PREFIX}/include/gap |; \
		' ${STAGEDIR}${DATADIR}/sysinfo.gap
	# remove redundant files
	${RM} ${STAGEDIR}${DATADIR}/pkg/patternclass/lib/.DS_Store

do-test:
	@cd ${WRKSRC} && ./gap ${FILESDIR}/test.g

.include <bsd.port.mk>
