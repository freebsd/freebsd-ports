# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	afl
PORTVERSION=	2.51
DISTVERSIONSUFFIX=	b
CATEGORIES=	security
MASTER_SITES=	http://lcamtuf.coredump.cx/afl/releases/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Fast instrumented fuzzer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/docs/COPYING

# In theory afl supports other architectures with the LLVM plugin.
# It has to be compiled with AFL_NO_X86=1 in that case.
ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Uses binary instrumentation

USES=	gmake tar:tgz

ALL_TARGET=	all libdislocator
TEST_TARGET=	test_build

OPTIONS_DEFINE=	DEBUG DOCS LLVM
OPTIONS_DEFAULT=	LLVM
OPTIONS_SUB=	yes

LLVM_DESC=	LLVM-based instrumentation

LLVM_VERSION=	40

LLVM_ALL_TARGET=	llvm_mode
LLVM_BUILD_DEPENDS=	clang${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
LLVM_RUN_DEPENDS=	clang${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
LLVM_TEST_TARGET=	test_llvm_mode
LLVM_VARS=	CC=clang${LLVM_VERSION} CXX=clang++${LLVM_VERSION} \
		MAKE_ARGS=LLVM_CONFIG=llvm-config${LLVM_VERSION}

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
# Clang i386 emits .cfi_sections which base as(1) doesn't understand
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
RUN_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
.endif

post-patch:
# Disable the instrumentation tests to make sure building packages in
# jails works by default.  afl needs shmget() which usually isn't
# available in jails.
	@${REINPLACE_CMD} 's@^\(all.*\) test_build@\1@' \
		${WRKSRC}/Makefile ${WRKSRC}/llvm_mode/Makefile
.if ${ARCH} == "i386"
	@${REINPLACE_CMD} 's@\(  as_params\[0\] = afl_as ? afl_as : \)\(.*\)@\1(u8*)"${LOCALBASE}/bin/as";@' \
		${WRKSRC}/afl-as.c
.endif
	@${CAT} ${FILESDIR}/Makefile.extra >> ${WRKSRC}/Makefile

post-patch-LLVM-on:
	@${REINPLACE_CMD} \
		-e 's|"clang"|"clang${LLVM_VERSION}"|g' \
		-e 's|"clang\+\+"|"clang\+\+${LLVM_VERSION}"|g' \
		${WRKSRC}/llvm_mode/afl-clang-fast.c

post-install:
.for script in afl-cmin afl-plot afl-whatsup
	${INSTALL_SCRIPT} ${WRKSRC}/${script} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/afl/afl-as
.for prog in afl-analyze afl-fuzz afl-gcc afl-gotcpu afl-showmap afl-tmin
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${prog}
.endfor
	${INSTALL_LIB} ${WRKSRC}/libdislocator/libdislocator.so \
		${STAGEDIR}${PREFIX}/lib/afl
	${INSTALL_DATA} ${WRKSRC}/libdislocator/README.dislocator \
		${STAGEDIR}${DOCSDIR}

post-install-LLVM-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/afl/afl-llvm-pass.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/afl-clang-fast
	${INSTALL_DATA} ${WRKSRC}/llvm_mode/README.llvm \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
