PORTNAME=	lean4
DISTVERSIONPREFIX=	v
DISTVERSION=	4.5.0-rc1
PORTREVISION=	1
CATEGORIES=	math lang devel # lean4 is primarily a math theorem prover, but it is also a language and a development environment

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Theorem prover and functional language for math (new gen)
WWW=		https://lean-lang.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		cmake:noninja,testing compiler:c++14-lang gmake python:build # ninja fails + gmake scripts are included in the project

USE_GITHUB=	yes
GH_ACCOUNT=	leanprover
GH_TUPLE=	leanprover:std4:${DISTVERSIONFULL}:std4

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
	# build the standard library std4
	@${ECHO} "==> Building the Std4 library"
	@cd ${WRKSRC_std4} && \
		${STAGEDIR}${PREFIX}/bin/lake build
		#${SETENV} PATH=${STAGEDIR}${PREFIX}/bin:${PATH} lake build
	# install the standard library std4
	@${ECHO} "==> Installing the Std4 library"
	@cd ${WRKSRC_std4}/.lake/build/lib && \
		${INSTALL_DATA} Std.olean ${STAGEDIR}${PREFIX}/lib/lean && \
		${COPYTREE_SHARE} Std ${STAGEDIR}${PREFIX}/lib/lean

# 6 tests are known to fail due to bugs in the testcase code, see https://github.com/leanprover/lean4/issues/3179

.include <bsd.port.mk>
