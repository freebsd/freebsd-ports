PORTNAME=	gap
DISTVERSION=	4.16.1
CATEGORIES=	math
MASTER_SITES=	https://github.com/gap-system/gap/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	System for computational discrete algebra
WWW=		https://www.gap-system.org/ \
		https://github.com/gap-system/gap

LICENSE=	GPLv2+

BUILD_DEPENDS=	autoconf:devel/autoconf \
		automake:devel/automake \
		bash:shells/bash \
		libtool:devel/libtool
# attempt to fix the intermittent failure: WARNING: 'automake-1.16' is missing on your system.
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		gmake libtool localbase perl5 readline shebangfix
USE_PERL5=	run
USE_LDCONFIG=	yes

BROKEN_powerpc64=	compilation fails: error: static assertion failed due to requirement 'sizeof(struct GAPState) < 32768': GAPState is too big
BROKEN_powerpc64le=	compilation fails: error: static assertion failed due to requirement 'sizeof(struct GAPState) < 32768': GAPState is too big

SHEBANG_FILES=	. -not -name '*.ac' -not -name '*.am' -not -name '*.m4'

GNU_CONFIGURE=	yes

PLIST_SUB+=	CONFIGURE_TARGET=${CONFIGURE_TARGET}

MAKEFILE=	GNUmakefile

ACLOCVER=	1.18	# Truncated version of aclocal / automake

COMPILED_PACKAGES=	ace anupq browse caratinterface cddinterface cohomolo crypting curlinterface cvec datastructures \
			deepthought digraphs edim example ferret float fplsa gauss grape guava \
			io json kbmag normalizinterface nq orb profiling semigroups simpcomp xgap \
			zeromqinterface

OPTIONS_GROUP=			EXTRA_PACKAGES
OPTIONS_SUB=			yes

EXTRA_PACKAGES_DESC=		Extra packages (requiring compilation)

.for p in ${COMPILED_PACKAGES}
OPTIONS_GROUP_EXTRA_PACKAGES+=	${p:tu}
OPTIONS_DEFAULT+=		${p:tu}
${p:tu}_DESC=			${p} package

post-build-${p:tu}-on:
	@${ECHO} "==> Build for package ${p}"
	@cd ${WRKSRC}/pkg/${p} && \
		${CHMOD} +x configure && \
		./configure ${${p:tu}_CONFIGURE_ARGS} && \
		${SETENV} ${MAKE_ENV} ${GMAKE}
.endfor

ANUPQ_CONFIGURE_ARGS=			--with-gmp=${LOCALBASE}

NQ_CONFIGURE_ARGS=			--with-gmp=${LOCALBASE}

CDDINTERFACE_LIB_DEPENDS=		libcddgmp.so:math/cddlib
CDDINTERFACE_CONFIGURE_ARGS=		--with-cddlib=${LOCALBASE}

CURLINTERFACE_LIB_DEPENDS=		libcurl.so:ftp/curl

FLOAT_LIB_DEPENDS=			libmpc.so:math/mpc \
					libmpfi.so:math/mpfi \
					libmpfr.so:math/mpfr
FLOAT_CONFIGURE_ARGS=			--with-mpfr=${LOCALBASE}

NORMALIZINTERFACE_LIB_DEPENDS=		libflint.so:math/flint2 \
					libgmp.so:math/gmp \
					libnauty.so:math/nauty \
					libnormaliz.so:math/libnormaliz
NORMALIZINTERFACE_CONFIGURE_ARGS=	--with-normaliz=${LOCALBASE}

SEMIGROUPS_LIB_DEPENDS=			libfmt.so:devel/libfmt \
					libsemigroups.so:math/libsemigroups
SEMIGROUPS_CONFIGURE_ARGS=		--with-external-libsemigroups

ZEROMQINTERFACE_LIB_DEPENDS=		libzmq.so:net/libzmq4
ZEROMQINTERFACE_CONFIGURE_ARGS=		--with-zmq=${LOCALBASE}

XGAP_USES=				xorg
XGAP_USE=				XORG=x11,xaw,xt
XGAP_CONFIGURE_ARGS=			--x-includes=${LOCALBASE}/include --x-libraries=${LOCALBASE}/lib

pre-configure:
# Avoid conflict with C++20 <version> by ignoring <...> under WRKSRC
	${REINPLACE_CMD} -i .c++20 's/-I/-iquote/' \
		${WRKSRC}/pkg/*/Makefile.in
# Fix autoconf 2.73 overquoted AC_SUBST in semigroups in case the patch is not applied
	${REINPLACE_CMD} -i '' -e 's/AC_SUBST(SYS_IS_CYGWIN, yes)/AC_SUBST([SYS_IS_CYGWIN], [yes])/' \
		${WRKSRC}/pkg/semigroups/configure.ac
.for f in aclocal.m4 configure
	${FIND} ${WRKSRC} -name ${f} | ${XARGS} ${REINPLACE_CMD} -i ''	\
		-e "s|am__api_version='1.15'|am__api_version='${ACLOCVER}'|" \
		-e "s|am__api_version='1.16'|am__api_version='${ACLOCVER}'|"
.endfor
# Regenerate autotools for packages that ship configure.ac so their macros match the installed automake/autoconf
.for p in ${COMPILED_PACKAGES}
	@if test -f ${WRKSRC}/pkg/${p}/configure.ac && test "${p}" != "semigroups"; then \
		${ECHO} "autoreconf: ${p}" ; \
		cd ${WRKSRC}/pkg/${p} && ${LOCALBASE}/bin/autoreconf -fi || exit 1; \
	fi
.endfor

post-build: # it is unclear why is this needed, see the question here: https://github.com/gap-system/gap/issues/5599
	# there are intermittend failures in this build step: configure.ac:3: error: version mismatch.  This is Automake 1.16.5,
	@${ECHO} "Build in pkg/simpcomp"
	@cd ${WRKSRC}/pkg/simpcomp && \
		${SETENV} ${CONFIGURE_ENV} ${SH} configure \
			${CONFIGURE_ARGS:N--with-*} && \
		${MAKE} ${MAKEFLAGS} && \
		${MAKE} ${MAKEFLAGS} install-strip && \
		${MAKE} ${MAKEFLAGS} distclean

post-install:
	# install packages
	cd ${WRKSRC} && ${COPYTREE_SHARE} pkg ${STAGEDIR}${DATADIR}
	# remove redundant files
	@${RM} \
		${STAGEDIR}${DATADIR}/pkg/agt/doc/mathjax \
		${STAGEDIR}${DATADIR}/pkg/atlasrep/gap/utils.gi.new \
		${STAGEDIR}${DATADIR}/pkg/*/examples/.gitkeep
	# remove build artifacts and generated autotools files from compiled packages
.for p in ${COMPILED_PACKAGES}
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type d -name autom4te.cache -exec ${RM} -rf {} +
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type d -name .deps -exec ${RM} -rf {} +
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type f -name .dirstamp -delete
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type f -name config.log -delete
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type f -name config.status -delete
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type f -name configure~ -delete
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type f -name config.h -delete
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type f -name stamp-h1 -delete
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type f -name '*.hin~' -delete
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type f -name '*.in~' -delete
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type f -name '*.o' -delete
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type f -name '*.Po' -delete
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type f -name '*.Plo' -delete
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type f -name '*.lo' -delete
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type f -name '*.d' ! -path '*/FlameGraph/dev/*' -delete
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type f -name '*.a' -delete
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type f \( -name '*.la' -o -name '*.lai' \) -delete
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -type f -name Makefile -delete
	@${FIND} ${STAGEDIR}${DATADIR}/pkg/${p} -path '*/lib/pkgconfig/*.pc' -delete
.endfor
	# remove source-tree duplicates of compiled binaries
	@${RM} -f \
		${STAGEDIR}${DATADIR}/pkg/ace/src/ace \
		${STAGEDIR}${DATADIR}/pkg/anupq/pq \
		${STAGEDIR}${DATADIR}/pkg/nq/nq \
		${STAGEDIR}${DATADIR}/pkg/xgap/xgap.sh
	# remove empty directories
	@${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete
	# strip binaries

do-test:
	@cd ${WRKSRC} && ./gap ${FILESDIR}/test.g

# tests as of 4.16.1: all tests pass

.include <bsd.port.mk>
