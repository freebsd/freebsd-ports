PORTNAME=	lean4
DISTVERSIONPREFIX=	v
DISTVERSION=	4.6.0
CATEGORIES=	math lang devel # lean4 is primarily a math theorem prover, but it is also a language and a development environment

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Theorem prover and functional language for math (new gen)
WWW=		https://lean-lang.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	linking fails: INTERNAL PANIC: out of memory (during: Linking runLinter)

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		cmake:noninja,testing compiler:c++14-lang gmake python:build # ninja fails + gmake scripts are included in the project

USE_GITHUB=	yes
GH_ACCOUNT=	leanprover

CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC

BINARY_ALIAS=	make=${GMAKE} python=${PYTHON_CMD}

post-install:
	# remove empty dirs
	@${FIND} ${STAGEDIR}${DATADIR} -type d -empty -delete
	# remove stray files
	@${RM} ${STAGEDIR}${PREFIX}/LICENSE*
	# strip binaries
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} \
		bin/lake \
		bin/lean \
		bin/leanc \
		lib/lean/libleanshared.so

# 6 tests are known to fail due to bugs in the testcase code, see https://github.com/leanprover/lean4/issues/3179

.include <bsd.port.mk>
