PORTNAME=	rust-coreutils
DISTVERSION=	0.12.0
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Cross-platform Rust rewrite of the GNU coreutils
WWW=		https://crates.io/crates/coreutils

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	uutils
GH_PROJECT=	coreutils
GH_TUPLE=	uutils:coreutils-l10n:${DISTVERSION}:l10n

CARGO_FEATURES=	unix openssl
# Use the base system OpenSSL rather than the bundled openssl-src copy.
CARGO_ENV=	OPENSSL_NO_VENDOR=1
BINPREFIX=	uu-
PLIST_SUB=	BINPREFIX=${BINPREFIX}

post-build:
	${INSTALL_SCRIPT} ${FILESDIR}/symlink-install-helper.sh.in ${CARGO_TARGET_DIR}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%GREP%%|${GREP}|g' \
		${CARGO_TARGET_DIR}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%CARGO_TARGET_DIR%%|${CARGO_TARGET_DIR}|g' \
		${CARGO_TARGET_DIR}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%SED%%|${SED}|g' \
		${CARGO_TARGET_DIR}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%TR%%|${TR}|g' \
		${CARGO_TARGET_DIR}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%RLN%%|${RLN}|g' \
		${CARGO_TARGET_DIR}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%STAGEDIR%%|${STAGEDIR}|g' \
		${CARGO_TARGET_DIR}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${CARGO_TARGET_DIR}/symlink-install-helper.sh
	@${REINPLACE_CMD} -e 's|%%BINPREFIX%%|${BINPREFIX}|g' \
		${CARGO_TARGET_DIR}/symlink-install-helper.sh

# The translations from coreutils-l10n are installed first, so that the ones
# shipped with the release win. English is embedded in the binary. chcon and
# runcon need SELinux and are not built, so skip their locales.
do-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/coreutils \
		${STAGEDIR}${PREFIX}/bin/${BINPREFIX}coreutils
	${CARGO_TARGET_DIR}/symlink-install-helper.sh
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
pre-test:
	cd ${STAGEDIR}${PREFIX}/share && \
		${COPYTREE_SHARE} locales ${CARGO_TARGET_DIR}/release

.include <bsd.port.mk>
