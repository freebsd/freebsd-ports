# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	afl
PORTVERSION=	2.58c
CATEGORIES=	security
PKGNAMESUFFIX=	++

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Fast instrumented fuzzer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/docs/COPYING

# In theory afl supports non-x86 architectures with the LLVM plugin.
# This has only been run tested on aarch64 so far.
ONLY_FOR_ARCHS=	aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	uses x86-only instrumentation or requires complete LLVM support

USES=		gmake tar:tgz
USE_GITHUB=	yes
GH_ACCOUNT=	vanhauser-thc
GH_PROJECT=	AFLplusplus

ALL_TARGET=	all libdislocator
TEST_TARGET=	test_build

CONFLICTS_INSTALL=	afl

OPTIONS_DEFINE=		DEBUG DOCS LLVM
OPTIONS_DEFAULT=	LLVM
# On non-x86 architectures LLVM is mandatory
OPTIONS_SLAVE=		${ARCH:Namd64:Ni386:S/${ARCH}/LLVM/}
OPTIONS_SUB=		yes

LLVM_DESC=	LLVM-based instrumentation

LLVM_BUILD_DEPENDS=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
LLVM_RUN_DEPENDS=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
LLVM_MAKE_ARGS=		LLVM_CONFIG=llvm-config${LLVM_DEFAULT}
LLVM_ALL_TARGET=	llvm_mode
LLVM_TEST_TARGET=	test_llvm_mode
LLVM_BINARY_ALIAS=	llvm-config=llvm-config${LLVM_DEFAULT}
LLVM_VARS=		CC=clang${LLVM_DEFAULT} \
			CXX=clang++${LLVM_DEFAULT}

.include <bsd.port.options.mk>

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
PLIST_SUB+=	X86=""
.else
MAKE_ARGS+=	AFL_NO_X86=1
PLIST_SUB+=	X86="@comment "
.endif

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
		${WRKSRC}/src/afl-as.c
.endif
	@${CAT} ${FILESDIR}/Makefile.extra >> ${WRKSRC}/Makefile

post-patch-LLVM-on:
	@${REINPLACE_CMD} \
		-e 's|"clang"|"clang${LLVM_DEFAULT}"|g' \
		-e 's|"clang\+\+"|"clang\+\+${LLVM_DEFAULT}"|g' \
		${WRKSRC}/llvm_mode/afl-clang-fast.c

post-install:
.for script in afl-cmin afl-plot afl-whatsup
	${INSTALL_SCRIPT} ${WRKSRC}/${script} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/afl/afl-as
.for prog in afl-analyze afl-fuzz afl-gcc afl-gotcpu afl-showmap afl-tmin
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${prog}
.endfor
	${INSTALL_LIB} ${WRKSRC}/libdislocator.so \
		${STAGEDIR}${PREFIX}/lib/afl
	${MKDIR} ${STAGEDIR}${DOCSDIR}/libdislocator
	${INSTALL_MAN} ${WRKSRC}/libdislocator/README.md \
		${STAGEDIR}${DOCSDIR}/libdislocator

post-install-LLVM-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/afl/*.so \
		${STAGEDIR}${PREFIX}/bin/afl-clang-fast
	${MKDIR} ${STAGEDIR}${DOCSDIR}/llvm_mode
	${INSTALL_MAN} ${WRKSRC}/llvm_mode/README.* \
		${STAGEDIR}${DOCSDIR}/llvm_mode

.include <bsd.port.mk>
