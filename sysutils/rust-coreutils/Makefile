PORTNAME=	rust-coreutils
DISTVERSION=	0.13.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Cross-platform Rust rewrite of the GNU coreutils
WWW=		https://crates.io/crates/coreutils

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo cpe ssl
CPE_VENDOR=	uutils
CPE_PRODUCT=	coreutils
USE_GITHUB=	yes
GH_ACCOUNT=	uutils
GH_PROJECT=	coreutils

CARGO_FEATURES=	unix openssl feat_external_libstdbuf uudoc
# Use the base system OpenSSL rather than the bundled openssl-src copy.
CARGO_ENV=	OPENSSL_NO_VENDOR=1
# stdbuf preloads libstdbuf.so from there instead of unpacking a copy of it
# to a temporary directory on every run.
CARGO_ENV+=	LIBSTDBUF_DIR=${PREFIX}/libexec/${BINPREFIX}coreutils
BINPREFIX=	uu-
PLIST_SUB=	BINPREFIX=${BINPREFIX}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

# coreutils-l10n has no 0.13.0 tag.
NLS_GH_TUPLE=	uutils:coreutils-l10n:ba29242:l10n

do-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/coreutils \
		${STAGEDIR}${PREFIX}/bin/${BINPREFIX}coreutils
	for u in $$(${CARGO_TARGET_DIR}/release/coreutils --list); do \
		${RLN} ${STAGEDIR}${PREFIX}/bin/${BINPREFIX}coreutils \
			${STAGEDIR}${PREFIX}/bin/${BINPREFIX}$$u; \
	done
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${BINPREFIX}coreutils
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/release/libstdbuf.so \
		${STAGEDIR}${PREFIX}/libexec/${BINPREFIX}coreutils

# uudoc is only built to generate the manual pages and the shell completions.
# The date of the manual pages is taken from the release instead of the build.
post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	cd ${STAGEDIR}${PREFIX}/share && export PROG_PREFIX=${BINPREFIX} \
		SOURCE_DATE_EPOCH=$$(${STAT} -f %m ${WRKSRC}/LICENSE) && \
	for u in coreutils $$(${CARGO_TARGET_DIR}/release/coreutils --list); do \
		[ "$$u" = "[" ] && continue; \
		p=${BINPREFIX}$$u; uudoc=${CARGO_TARGET_DIR}/release/uudoc; \
		$$uudoc manpage $$u > man/man1/$$p.1 && \
		$$uudoc completion $$u bash > bash-completion/completions/$$p && \
		$$uudoc completion $$u fish > fish/vendor_completions.d/$$p.fish && \
		$$uudoc completion $$u zsh > zsh/site-functions/_$$p || exit 1; \
	done

# The translations from coreutils-l10n are installed first, so that the ones
# shipped with the release win. English is embedded in the binary. chcon and
# runcon need SELinux and are not built, so skip their locales.
post-install-NLS-on:
	for s in ${WRKSRC_l10n} ${WRKSRC}; do \
		cd $$s/src && for d in uucore/locales uucore/locales/errors \
			uu/*/locales; do \
			case $$d in uu/chcon/*|uu/runcon/*) continue;; esac; \
			[ -d $$d ] || continue; \
			t=${STAGEDIR}${PREFIX}/share/locales/$$(${ECHO_CMD} $$d | \
				${SED} -e 's|^uu/||' -e 's|/locales||'); \
			${MKDIR} $$t && ${INSTALL_DATA} $$d/*.ftl $$t; \
		done; \
	done
	${FIND} ${STAGEDIR}${PREFIX}/share/locales -name en-US.ftl -delete

# The tests look for the locales next to the binary they run.
pre-test-NLS-on:
	cd ${STAGEDIR}${PREFIX}/share && \
		${COPYTREE_SHARE} locales ${CARGO_TARGET_DIR}/release

.include <bsd.port.mk>
