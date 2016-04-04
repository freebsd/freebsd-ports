# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	afl
PORTVERSION=	2.07b
CATEGORIES=	security
MASTER_SITES=	http://lcamtuf.coredump.cx/afl/releases/

MAINTAINER=	t@tobik.me
COMMENT=	Fast instrumented fuzzer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/docs/COPYING

USES=	compiler gmake tar:tgz

OPTIONS_DEFINE=		DEBUG DOCS MINIMIZE_CORPUS LLVM TEST_INSTRUMENTATION
MINIMIZE_CORPUS_DESC=	Install afl-cmin. Adds bash dependency
TEST_INSTRUMENTATION_DESC=	Execute tests (expected to fail in jails)
LLVM_DESC=	LLVM-based instrumentation (broken on 9.x)
OPTIONS_DEFAULT=	DOCS LLVM MINIMIZE_CORPUS

OPTIONS_SUB=	yes

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Uses binary instrumentation

LLVM_BUILD_DEPENDS=	clang37:devel/llvm37
LLVM_RUN_DEPENDS=	clang37:devel/llvm37
MINIMIZE_CORPUS_RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000013
# Broken on FreeBSD 9
PLIST_SUB+=	LLVM_SUB="@comment "
.else
PLIST_SUB+=	LLVM_SUB=""
.endif

.if ${ARCH} == "i386"
# Clang i386 emits .cfi_sections which base as(1) doesn't understand
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
RUN_DEPENDS+=	${LOCALBASE}/bin/as:devel/binutils
.endif

MAKE_ARGS=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

post-patch-TEST_INSTRUMENTATION-off:
# afl needs shmget() which usually isn't available in jails. Disabling
# the instrumentation tests makes sure building packages in jails works
# by default anyway.
	${REINPLACE_CMD} -e 's@^\(all.*\) test_build@\1@' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's@^\(all.*\) test_build@\1@' ${WRKSRC}/llvm_mode/Makefile

post-patch:
.if ${ARCH} == "i386"
	${REINPLACE_CMD} -e 's@\(  as_params\[0\] = afl_as ? afl_as : \)\(.*\)@\1(u8*)"${LOCALBASE}/bin/as";@' \
		${WRKSRC}/afl-as.c
.endif

.if ! ${OSVERSION} < 1000013
# Broken on FreeBSD 9
post-build-LLVM-on:
	@(cd ${WRKSRC}/llvm_mode; ${SETENV} \
		CC=clang37 \
		CXX=clang++37 \
		LLVM_CONFIG=llvm-config37 \
		CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" \
		${GMAKE})
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/COPYING ${STAGEDIR}${DOCSDIR}/

.for afl_script in afl-cmin afl-plot afl-whatsup
	${INSTALL_SCRIPT} ${WRKSRC}/${afl_script} ${STAGEDIR}${PREFIX}/bin/
.endfor

post-install-MINIMIZE_CORPUS-on:
	${INSTALL_SCRIPT} ${WRKSRC}/afl-cmin ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
