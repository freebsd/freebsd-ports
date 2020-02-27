# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	afl
PORTVERSION=	2.61c
CATEGORIES=	security
PKGNAMESUFFIX=	++

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Fast instrumented fuzzer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/docs/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc64
ONLY_FOR_ARCHS_REASON=	uses x86-only instrumentation or requires complete LLVM support

TEST_DEPENDS=	bash:shells/bash

USES=		gmake tar:tgz
USE_GITHUB=	yes
GH_ACCOUNT=	vanhauser-thc
GH_PROJECT=	AFLplusplus

MAKE_ARGS=	STRIP_CMD="${STRIP_CMD}"
ALL_TARGET=	all libtokencap
INSTALL_TARGET=	install-strip
TEST_TARGET=	test_build

CONFLICTS_INSTALL=	afl

OPTIONS_DEFINE=		DEBUG DOCS EXAMPLES GCC LIBDISLOCATOR LLVM PYTHON
OPTIONS_DEFAULT=	GCC LIBDISLOCATOR LLVM PYTHON

# libdislocator fails to build on FreeBSD 11.x
# error: typedef redefinition with different types ('struct max_align_t' vs '__max_align_t')
OPTIONS_EXCLUDE_FreeBSD_11=	LIBDISLOCATOR

# On non-x86 architectures LLVM is mandatory
OPTIONS_SLAVE=	${ARCH:Namd64:Ni386:S/${ARCH}/LLVM/}
OPTIONS_SUB=	yes

GCC_DESC=		Build GCC plugin and afl-gcc-fast
LIBDISLOCATOR_DESC=	Abusive allocator for uncovering heap-related bugs
LLVM_DESC=		LLVM-based instrumentation
PYTHON_DESC=		Python mutators support

GCC_BUILD_DEPENDS=	gcc${GCC_DEFAULT}>0:lang/gcc${GCC_DEFAULT}
GCC_RUN_DEPENDS=	gcc${GCC_DEFAULT}>0:lang/gcc${GCC_DEFAULT}
GCC_MAKE_ARGS=		GCC=gcc${GCC_DEFAULT:S/-devel$//} \
			GXX=g++${GCC_DEFAULT:S/-devel$//}
GCC_ALL_TARGET=		gcc_plugin
GCC_TEST_TARGET=	test_gcc_plugin

LIBDISLOCATOR_ALL_TARGET=	libdislocator

LLVM_BUILD_DEPENDS=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
LLVM_RUN_DEPENDS=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
LLVM_MAKE_ARGS=		CC=clang${LLVM_DEFAULT} \
			CXX=clang++${LLVM_DEFAULT} \
			LLVM_CONFIG=llvm-config${LLVM_DEFAULT}
LLVM_ALL_TARGET=	llvm_mode
LLVM_TEST_TARGET=	test_llvm_mode
LLVM_BINARY_ALIAS=	llvm-config=llvm-config${LLVM_DEFAULT}

PYTHON_USES=		gettext-runtime python:3.7
PYTHON_MAKE_ARGS_OFF=	PYTHON_INCLUDE=/nonexistent

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
		${WRKSRC}/Makefile \
		${WRKSRC}/gcc_plugin/Makefile \
		${WRKSRC}/llvm_mode/Makefile
.if ${ARCH} == "i386"
	@${REINPLACE_CMD} 's@\(  as_params\[0\] = afl_as ? afl_as : \)\(.*\)@\1(u8*)"${LOCALBASE}/bin/as";@' \
		${WRKSRC}/src/afl-as.c
.endif
	@${REINPLACE_CMD} '/export AFL_CC/d' ${WRKSRC}/test/test.sh
	@${ECHO_CMD} "include ${FILESDIR}/Makefile.extra" >> ${WRKSRC}/Makefile

post-patch-LLVM-on:
	@${REINPLACE_CMD} \
		-e 's|"clang"|"clang${LLVM_DEFAULT}"|g' \
		-e 's|"clang\+\+"|"clang\+\+${LLVM_DEFAULT}"|g' \
		${WRKSRC}/llvm_mode/afl-clang-fast.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/libtokencap
	${INSTALL_MAN} ${WRKSRC}/libtokencap/README.md \
		${STAGEDIR}${DOCSDIR}/libtokencap
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} lib/afl -name 'argvfuzz*.so' -or -name 'socketfuzz*.so' \
		>> ${TMPPLIST}

post-install-GCC-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/gcc_plugin
	${INSTALL_MAN} ${WRKSRC}/gcc_plugin/README.* \
		${STAGEDIR}${DOCSDIR}/gcc_plugin

post-install-LIBDISLOCATOR-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/libdislocator
	${INSTALL_MAN} ${WRKSRC}/libdislocator/README.md \
		${STAGEDIR}${DOCSDIR}/libdislocator

post-install-LLVM-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/llvm_mode
	${INSTALL_MAN} ${WRKSRC}/llvm_mode/README.* \
		${STAGEDIR}${DOCSDIR}/llvm_mode

post-install-PYTHON-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/python_mutators
	@cd ${WRKSRC}/examples && \
		${COPYTREE_SHARE} python_mutators ${STAGEDIR}${EXAMPLESDIR}

post-test:
# libtokencap test might require security.bsd.unprivileged_proc_debug=1
	@cd ${WRKSRC}/test && ./test.sh

.include <bsd.port.mk>
