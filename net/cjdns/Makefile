PORTNAME=	cjdns
DISTVERSIONPREFIX=	cjdns-v
DISTVERSION=	22.3
CATEGORIES=	net security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Routing engine designed for security, scalability, speed
WWW=		https://github.com/cjdelisle/cjdns

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		cargo gmake llvm nodejs:build
USE_GITHUB=	yes
GH_ACCOUNT=	cjdelisle
USE_RC_SUBR=	cjdns
SUB_FILES=	cjdns pkg-message
SUB_LIST=	LOCALBASE=${LOCALBASE}
MAKE_ENV=	LIBCLANG_PATH=${LLVM_PREFIX}/lib \
		SODIUM_USE_PKG_CONFIG=1
CARGO_INSTALL=	no
CARGO_BUILD_ARGS=	-p cjdns_sys --bin cjdroute \
		-p cjdnstool --bin cjdnstool
CFLAGS+=	-fPIC
RUSTFLAGS+=	-Asemicolon_in_expressions_from_macros
PLIST_FILES=	bin/cjdnstool \
		bin/cjdroute \
		bin/run-cjdroute \
		share/man/man1/cjdroute.1.gz \
		share/man/man5/cjdroute.conf.5.gz

BORINGTUN_COMMIT=	f288b2f461e7322a278b63b1ddc4ab705b5b7462
BORINGTUN_WRKSRC=	${WRKDIR}/boringtun-${BORINGTUN_COMMIT}

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/etc/|${LOCALBASE}/etc/|g' \
		${WRKSRC}/contrib/sh/run-cjdroute.sh
	@${REINPLACE_CMD} -e 's/target_os = "ios")))]/target_os = "ios", target_os = "freebsd")))]/' \
		${BORINGTUN_WRKSRC}/src/lib.rs
	@${REINPLACE_CMD} -e 's|throw new Error("Unable to find a path to libsodium headers");|builder.config.includeDirs.push("${LOCALBASE}/include"); foundSodium = true;|' \
		${WRKSRC}/node_build/make.js
	@${REINPLACE_CMD} -e "s|builder.config.includeDirs.push('node_build/dependencies/libuv/src/');|builder.config.includeDirs.push('node_build/dependencies/libuv/src/');\\n        builder.config.includeDirs.push('cargo-crates/ring-0.16.20/include');|" \
		${WRKSRC}/node_build/make.js

do-build:
	@${CARGO_CARGO_RUN} build \
		--manifest-path ${CARGO_CARGOTOML} \
		--verbose \
		--verbose \
		${CARGO_BUILD_ARGS}

do-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/cjdnstool ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/cjdroute ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/sh/run-cjdroute.sh ${STAGEDIR}${PREFIX}/bin/run-cjdroute
	${INSTALL_MAN} ${WRKSRC}/doc/man/cjdroute.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/cjdroute.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5

# tests as of 22.3: cjdns_sys: 15 passed, 0 failed, 5 ignored; cjdnstool: 2 passed, 0 failed, 0 ignored; doc-tests: 1 ignored

.include <bsd.port.mk>
