PORTNAME=	herdr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
CATEGORIES=	sysutils
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Terminal workspace manager for AI coding agents
WWW=		https://github.com/herdrdev/herdr

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo zig
USE_GITHUB=	yes
GH_ACCOUNT=	herdrdev

# build.rs drives "zig build" for the vendored libghostty-vt (Zig 0.16).
CARGO_ENV+=	LIBGHOSTTY_VT_ZIG_SYSTEM_DIR=${ZIG_DEPSDIR} \
		ZIG=${LOCALBASE}/bin/zig \
		ZIG_GLOBAL_CACHE_DIR=${WRKDIR}/zig-cache \
		ZIG_LOCAL_CACHE_DIR=${WRKDIR}/zig-local-cache

PLIST_FILES=	bin/${PORTNAME} \
		share/bash-completion/completions/${PORTNAME} \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

# USES=zig replaces the _USES_extract list, dropping the USES=cargo crate
# vendoring step, so run it explicitly.
post-extract: cargo-extract

# USES=zig provides no-op do-build/do-install for zig-only ports, which would
# shadow the USES=cargo targets, so spell out the cargo steps here.
do-build:
	@${CARGO_CARGO_RUN} build \
		--manifest-path ${CARGO_CARGOTOML} \
		--verbose \
		${CARGO_BUILD_ARGS}

do-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} completion bash > \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/${PORTNAME}
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} completion fish > \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/${PORTNAME}.fish
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} completion zsh > \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
