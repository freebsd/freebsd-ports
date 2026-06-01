PORTNAME=	rust-coreutils
DISTVERSION=	0.9.0
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Cross-platform Rust rewrite of the GNU coreutils
WWW=		https://crates.io/crates/coreutils

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	uutils
GH_PROJECT=	coreutils

CARGO_FEATURES=	unix
BINPREFIX=	uu-
PLIST_SUB=	BINPREFIX=${BINPREFIX}

# The French locale translation tests are flaky across distributions.
CARGO_TEST_AFTER_ARGS=	--skip test_error_messages_french_translation \
			--skip test_french_colored_error_messages \
			--skip test_help_messages_french_translation

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

do-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/coreutils \
		${STAGEDIR}${PREFIX}/bin/${BINPREFIX}coreutils
	${CARGO_TARGET_DIR}/symlink-install-helper.sh

.include <bsd.port.mk>
