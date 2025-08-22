PORTNAME=	lean4
DISTVERSIONPREFIX=	v
DISTVERSION=	4.22.0
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
		cadical:math/cadical
LIB_DEPENDS=	libgmp.so:math/gmp \
		libuv.so:devel/libuv
RUN_DEPENDS=	cadical:math/cadical

USES=		cmake:noninja,testing compiler:c++14-lang gmake pkgconfig python:build # ninja fails + gmake scripts are included in the project

USE_GITHUB=	yes
GH_ACCOUNT=	leanprover

CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC

CMAKE_OFF=	USE_MIMALLOC

#MAKE_ARGS+=	V=1 VERBOSE=1
#MAKE_JOBS_UNSAFE=     yes
MAKE_ENV=	LD_LIBRARY_PATH=${BUILD_WRKSRC}/stage0/lib/lean

BINARY_ALIAS=	make=${GMAKE} python=${PYTHON_CMD}

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

post-install:
	# remove empty dirs
	@${FIND} ${STAGEDIR}${DATADIR} -type d -empty -delete
	# remove stray files
	@${RM} ${STAGEDIR}${PREFIX}/LICENSE*
	# remove bin/cadical, workaround for https://github.com/leanprover/lean4/issues/5603
	@${RM} ${STAGEDIR}${PREFIX}/bin/cadical
	# strip binaries
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} \
		bin/lake \
		bin/lean \
		bin/leanc \
		lib/lean/libInit_shared.so \
		lib/lean/libleanshared.so

tests as of 4.20.0: 99% tests passed, 16 tests failed out of 2594, see https://github.com/leanprover/lean4/issues/8628

.include <bsd.port.mk>
