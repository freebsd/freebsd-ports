# Created by: Fabian Keil <fk@fabiankeil.de>

PORTNAME=	afl
PORTVERSION=	4.00c
CATEGORIES=	security
PKGNAMESUFFIX=	++-${FLAVOR}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Fast instrumented fuzzer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/docs/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	uses x86-only instrumentation or requires complete LLVM support

BUILD_DEPENDS=	ginstall:sysutils/coreutils

FLAVORS=	llvm gcc
FLAVOR?=	${FLAVORS:[1]}

_LLVM_VER=		13
llvm_BUILD_DEPENDS=	clang${_LLVM_VER}:devel/llvm${_LLVM_VER}
llvm_RUN_DEPENDS=	clang${_LLVM_VER}:devel/llvm${_LLVM_VER}

USES=		gmake shebangfix tar:tgz
.if ${FLAVOR} == gcc
USE_GCC=	yes
.endif
USE_GITHUB=	yes
GH_ACCOUNT=	AFLplusplus
GH_PROJECT=	AFLplusplus
SHEBANG_FILES=	afl-persistent-config

MAKEFILE=	GNUmakefile
MAKE_ARGS=	${${ARCH} != amd64 && ${ARCH} != i386:?AFL_NO_X86=1:} \
		PREFIX="${PREFIX}/${PKGBASE}"
.if ${FLAVOR} == llvm
MAKE_ARGS+=	CC=clang${_LLVM_VER} \
		CXX=clang++${_LLVM_VER} \
		LLVM_CONFIG=llvm-config${_LLVM_VER}
.endif
ALL_TARGET=	distrib
QA_ENV=		IGNORE_QA_stripped=1 # unstripped to keep it functional

DOCSDIR=	${PREFIX}/${PKGBASE}/share/doc/afl
MANDIRS=	${PREFIX}/${PKGBASE}/share/man/man8
BINARY_ALIAS=	install=ginstall
PORTDOCS=	*

OPTIONS_DEFINE=		DEBUG DOCS PYTHON
OPTIONS_DEFAULT=	PYTHON

PYTHON_DESC=	Python mutators support

PYTHON_USES=		gettext-runtime python
PYTHON_BINARY_ALIAS=	python3-config=${PYTHON_CMD}-config \
			python3=${PYTHON_CMD}

post-patch:
	@${REINPLACE_CMD} '/alt_cc/ s,"gcc","gcc${GCC_DEFAULT:S/-devel$//}",' \
		${WRKSRC}/src/afl-cc.c
.if ${FLAVOR} == gcc
	@${REINPLACE_CMD} 's@\(  as_params\[0\] = afl_as ? afl_as : \)\(.*\)@\1(u8*)"${LOCALBASE}/bin/as";@' \
		${WRKSRC}/src/afl-as.c
.elif ${FLAVOR} == llvm
	@${ECHO_CMD} "all:" >${WRKSRC}/GNUmakefile.gcc_plugin
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/man.d
	@${ECHO_CMD} "MANPATH ${PREFIX}/${PKGBASE}/share/man" >${STAGEDIR}${PREFIX}/etc/man.d/${PKGBASE}.conf
	@${ECHO_CMD} "etc/man.d/${PKGBASE}.conf" >>${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; \
		${FIND} ${PKGBASE} -not -path '${PKGBASE}/share/doc/*' -and \( -type f -or -type l \) | \
		${SED} -Ee 's,^afl\+\+-${FLAVOR}/share/man/.*,&.gz,' \
			-e 's,^.*/afl-${${FLAVOR} == gcc:?(clang|llvm):(gcc|g\+\+)}.*,@comment &,'  | \
		${SORT} >> ${TMPPLIST}
	@${CAT} ${TMPPLIST}

.include <bsd.port.mk>
