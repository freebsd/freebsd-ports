PORTNAME=	gitlab-code-parser
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.1
CATEGORIES=	textproc

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Rust-based code parser used by GitLab
WWW=		https://gitlab.com/gitlab-org/rust/gitlab-code-parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/libclang.so:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libonig.so:devel/oniguruma \
		libzstd.so:archivers/zstd

USES=		cargo ssl

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
GL_PROJECT=	rust/gitlab-code-parser
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}

PLIST_FILES=	bin/parser-cli \
		include/parser-c-bindings.h \
		lib/libchunker.rlib \
		lib/libparser_c_bindings.a \
		lib/libparser_c_bindings.so \
		lib/libparser_core.rlib \
		lib/libtesting.rlib

# update the crates file with: make cargo-crates > Makefile.crates

do-install:
	@${INSTALL_DATA} ${CARGO_TARGET_DIR}/include/*.h ${STAGEDIR}${PREFIX}/include
	@${INSTALL_LIB} ${CARGO_TARGET_DIR}/release/*.so ${STAGEDIR}${PREFIX}/lib
	@${INSTALL_DATA} ${CARGO_TARGET_DIR}/release/*.a ${STAGEDIR}${PREFIX}/lib
	@${INSTALL_DATA} ${CARGO_TARGET_DIR}/release/*.rlib ${STAGEDIR}${PREFIX}/lib
	@${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/parser-cli ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
