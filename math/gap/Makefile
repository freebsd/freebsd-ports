PORTNAME=	gap
DISTVERSION=	4.12.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://github.com/gap-system/gap/releases/download/v${DISTVERSION}/

PATCH_SITES=	https://github.com/gap-system/gap/commit/
PATCHFILES=	adc76841750e3b0d39edf1315b5258bae119a928.diff:-p1 # Don't attempt to install the 'dev' manual, see https://github.com/gap-system/gap/pull/5091

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
USE_LDCONFIG=	yes

SHEBANG_FILES=	.

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

post-build:
	@cd ${WRKSRC}/pkg/simpcomp && \
		${SETENV} ${CONFIGURE_ENV} ${SH} configure \
			${CONFIGURE_ARGS:N--with-*} && \
		${MAKE} ${MAKEFLAGS} && \
		${MAKE} ${MAKEFLAGS} install-strip && \
		${RM} bistellar

post-install:
	# install packages
	cd ${WRKSRC} && ${COPYTREE_SHARE} pkg ${STAGEDIR}${DATADIR}
	# remove redundant files
	${RM} ${STAGEDIR}${DATADIR}/pkg/patternclass/lib/.DS_Store
	# strip binary
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgap.so.8.0.0

do-test:
	@cd ${WRKSRC} && ./gap ${FILESDIR}/test.g

.include <bsd.port.mk>
