PORTNAME=	gap
DISTVERSION=	4.13.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/gap-system/gap/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	System for computational discrete algebra
WWW=		https://www.gap-system.org/

LICENSE=	GPLv2+

BUILD_DEPENDS=	bash:shells/bash
BUILD_DEPENDS+=	automake:devel/automake # attempt to fix the intermittent failure: WARNING: 'automake-1.16' is missing on your system.
LIB_DEPENDS=	libgmp.so:math/gmp

BROKEN_powerpc64=	compilation fails: error: static assertion failed due to requirement 'sizeof(struct GAPState) < 32768': GAPState is too big
BROKEN_powerpc64le=	compilation fails: error: static assertion failed due to requirement 'sizeof(struct GAPState) < 32768': GAPState is too big

USES=		gmake libtool localbase perl5 readline shebangfix
USE_PERL5=	run
USE_LDCONFIG=	yes

SHEBANG_FILES=	. -not -name '*.ac' -not -name '*.am' -not -name '*.m4'

GNU_CONFIGURE=	yes

MAKEFILE=	GNUmakefile

ACLOCVER=	1.16	# Truncated version of aclocal / automake

pre-configure:
# Avoid conflict with C++20 <version> by ignoring <...> under WRKSRC
	${REINPLACE_CMD} -i .c++20 's/-I/-iquote/' \
		${WRKSRC}/pkg/*/Makefile.in
.for f in aclocal.m4 configure
	${FIND} ${WRKSRC} -name ${f} | ${XARGS} ${REINPLACE_CMD} -i ''	\
		-e "s|am__api_version='1.15'|am__api_version='${ACLOCVER}'|"
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
	# remove empty directories
	@${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete
	# strip binaries
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/lib/gap/gap \
		${STAGEDIR}${PREFIX}/lib/libgap.so.9

do-test:
	@cd ${WRKSRC} && ./gap ${FILESDIR}/test.g

.include <bsd.port.mk>
