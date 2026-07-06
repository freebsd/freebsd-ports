PORTNAME=	lean4
DISTVERSIONPREFIX=	v
DISTVERSION=	4.31.0
CATEGORIES=	math lang devel # lean4 is primarily a math theorem prover, but it is also a language and a development environment

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Theorem prover and functional language for math (new gen)
WWW=		https://lean-lang.org/ \
		https://github.com/leanprover/lean4

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails: ../../.build/stage1/lib/temp/Init/Coe.depend: No such file or directory
BROKEN_i386=	linking fails: INTERNAL PANIC: out of memory (during: Linking runLinter)

BUILD_DEPENDS=	bash:shells/bash \
		cadical:math/cadical \
		leantar:math/leangz
LIB_DEPENDS=	libgmp.so:math/gmp \
		libuv.so:devel/libuv
RUN_DEPENDS=	cadical:math/cadical \
		leantar:math/leangz
TEST_DEPENDS=	gtail:sysutils/coreutils

USES=		cmake:noninja,testing compiler:c++14-lang gmake pkgconfig python:build # ninja fails + gmake scripts are included in the project

USE_GITHUB=	yes
GH_ACCOUNT=	leanprover

CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC

CMAKE_OFF=	USE_MIMALLOC \
		INSTALL_LEANTAR

#MAKE_ARGS+=	V=1 VERBOSE=1
MAKE_ENV=	LD_LIBRARY_PATH=${BUILD_WRKSRC}/stage0/lib/lean

BINARY_ALIAS=	make=${GMAKE} \
		python=${PYTHON_CMD}

.include <bsd.port.pre.mk>

CMAKE_ARGS+=	-DLEANTAR=${LOCALBASE}/bin/leantar

post-configure:
	# Copy leantar to build bin directories for tests (INSTALL_LEANTAR=OFF disables the built-in copy)
	@${MKDIR} ${BUILD_WRKSRC}/stage0/bin ${BUILD_WRKSRC}/stage1/bin
	@${CP} ${LOCALBASE}/bin/leantar ${BUILD_WRKSRC}/stage0/bin/
	@${CP} ${LOCALBASE}/bin/leantar ${BUILD_WRKSRC}/stage1/bin/

# fails to build on 14 w/out this:
.if ${OSREL:R} <= 14
BINARY_ALIAS+=	ar=llvm-ar
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Please note that build Lean requires /proc to be mounted."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  The usual way to do this is to add this line to /etc/fstab:"
	@${ECHO_MSG} "  proc /proc procfs rw 0 0"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  and then run this command as root:"
	@${ECHO_MSG} "  # mount /proc"
	@${ECHO_MSG} ""

post-patch:
	# Add weakLeancArgs = ["-fPIC"] to all test lakefile.toml files
	# Skip inputFile test: its translate-config test expects exact TOML-to-Lean output
	@${FIND} ${WRKSRC}/tests -name "lakefile.toml" -not -path "*/inputFile/*" | while read f; do \
		${GREP} -q "weakLeancArgs" "$$f" || \
		( ${PRINTF} 'weakLeancArgs = ["-fPIC"]\n\n' | ${CAT} - "$$f" > "$$f.tmp" && ${MV} "$$f.tmp" "$$f" ); \
	done
	# Add weakLeancArgs to lakefile.lean files that define packages
	@${FIND} ${WRKSRC}/tests -name "lakefile.lean" | while read f; do \
		if ${GREP} -q "^package .* where" "$$f" && ! ${GREP} -q "weakLeancArgs" "$$f"; then \
			${AWK} '/^package .* where$$/ {print; print "  weakLeancArgs := #[\"-fPIC\"]"; next} 1' "$$f" > "$$f.tmp" && ${MV} "$$f.tmp" "$$f"; \
		fi; \
	done

post-install:
	# remove empty dirs
	@${FIND} ${STAGEDIR}${DATADIR} -type d -empty -delete
	# remove stray files
	@${RM} ${STAGEDIR}${PREFIX}/LICENSE*
	# remove bin/cadical, workaround for https://github.com/leanprover/lean4/issues/5603
	@${RM} ${STAGEDIR}${PREFIX}/bin/cadical
	# remove bin/leantar (we use the one from math/leangz)
	@${RM} ${STAGEDIR}${PREFIX}/bin/leantar
	# strip binaries
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} \
		bin/lake \
		bin/lean \
		bin/leanc \
		bin/leanir \
		lib/lean/libInit_shared.so \
		lib/lean/libleanshared.so \
		lib/lean/libleanshared_1.so \
		lib/lean/libleanshared_2.so \
		lib/lean/libLake_shared.so

# tests as of 4.25.2-20251201: 100% tests passed, 0 tests failed out of 3367
# tests as of 4.29.0-rc2: 99% tests passed, 12 tests failed out of 3584, see https://github.com/leanprover/lean4/issues/12721
# tests as of 4.29.0: 99% tests passed, 18 tests failed out of 3582, see https://github.com/leanprover/lean4/issues/13174
# tests as of 4.29.1: 99% tests passed, 24 tests failed out of 3584
# tests as of 4.30.0: 100% tests passed, 0 tests failed out of 3678
# tests as of 4.31.0: 99% tests passed, 2 tests failed out of 3858
# 2 failures are not port issues: cache/test.sh, ltar/test.sh: leantar panic (math/leangz bug, see reproducer-leangz/)

.include <bsd.port.post.mk>
