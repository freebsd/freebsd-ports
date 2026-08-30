PORTNAME=	pass-cli
DISTVERSION=	2.3.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITES_PROTON_ME}
PKGNAMEPREFIX=	proton-
DISTFILES=	${DISTFILES_PROTON_ME}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Command-line interface for Proton Pass
WWW=		https://protonpass.github.io/pass-cli/ \
		https://github.com/protonpass/pass-cli

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	protoc:devel/protobuf

USES=		cargo ssl

USE_GITHUB=	yes
GH_ACCOUNT=	protonpass

CARGO_CONFIGURE=	no
CARGO_DOT_DIR=		${WRKSRC}/${CARGO_SRC_SUBDIR}/../.cargo
CARGO_ENV=		GIT_HASH=${GIT_HASH_SHORT} \
			OPENSSL_NO_VENDOR=1

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

MASTER_SITES_PROTON_ME_TEMPLATE=	\
		https://rust-registry.proton.me/downloads/%%NAME%%@%%VERSION%%.crate?dummy=/:%%INDEX%%
DISTFILES_PROTON_ME_TEMPLATE=	\
		${CARGO_DIST_SUBDIR}/protom.me/%%NAME%%-%%VERSION%%${CARGO_CRATE_EXT}:%%INDEX%%
# tomlq -r '.package[] | select(.source == "sparse+https://rust-registry.proton.me/index/") | "\(.name):\(.version)"' ${WRKSRC}/Cargo.lock
CRATES_PROTON_ME_TUPLE=	\
		gopenpgp-sys:0.3.7 \
		muon:2.6.1 \
		muon-proc:0.6.0 \
		muon-proc:0.7.0 \
		muon-rest:0.1.0 \
		muon-test:1.1.0 \
		muon-test-server:0.1.2 \
		proton-crypto:0.13.2 \
		proton-crypto-account:0.19.2 \
		proton-os-interface:0.2.7 \
		proton-rpgp:0.5.0 \
		proton-srp:0.8.3
CRATES_PROTON_ME=	${CRATES_PROTON_ME_TUPLE:S/:/-/}
.for name version in ${CRATES_PROTON_ME_TUPLE:S/:/ /}
MASTER_SITES_PROTON_ME:=	\
		${MASTER_SITES_PROTON_ME} \
		${MASTER_SITES_PROTON_ME_TEMPLATE:S/%%NAME%%/${name}/:S/%%VERSION%%/${version}/:S/%%INDEX%%/${name:S/-/_/g}_${version:S/./_/g}/}
DISTFILES_PROTON_ME:=	\
		${DISTFILES_PROTON_ME} \
		${DISTFILES_PROTON_ME_TEMPLATE:S/%%NAME%%/${name}/:S/%%VERSION%%/${version}/:S/%%INDEX%%/${name:S/-/_/g}_${version:S/./_/g}/}
.endfor

GIT_HASH_SHORT=	51a4c9b

post-extract:
.for crate in ${CRATES_PROTON_ME}
	@${MV} ${WRKDIR}/${crate} ${CARGO_VENDOR_DIR}/${crate}
	@${PRINTF} '{"package":"%s","files":{}}' \
		$$(${SHA256} -q ${DISTDIR}/${CARGO_DIST_SUBDIR}/protom.me/${crate}${CARGO_CRATE_EXT}) > \
		${CARGO_VENDOR_DIR}/${crate}/.cargo-checksum.json
	@if [ -r ${CARGO_VENDOR_DIR}/${crate}/Cargo.toml.orig ]; then \
		${MV} ${CARGO_VENDOR_DIR}/${crate}/Cargo.toml.orig \
			${CARGO_VENDOR_DIR}/${crate}/Cargo.toml.orig-cargo; \
	fi
.endfor

post-configure:
	@${SETENV} CC="${CC}" OPSYS="${OPSYS}" OSVERSION="${OSVERSION}" WRKDIR="${WRKDIR}" \
		${SH} ${SCRIPTSDIR}/rust-compat11-canary.sh
	@${ECHO_MSG} "===>   Cargo config:"
	@${MKDIR} ${CARGO_DOT_DIR}
	@: > ${CARGO_DOT_DIR}/config.toml
	@${ECHO_CMD} "[source.cargo]" >> ${CARGO_DOT_DIR}/config.toml
	@${ECHO_CMD} "directory = '${CARGO_VENDOR_DIR}'" >> ${CARGO_DOT_DIR}/config.toml
	@${ECHO_CMD} "[source.crates-io]" >> ${CARGO_DOT_DIR}/config.toml
	@${ECHO_CMD} "replace-with = 'cargo'" >> ${CARGO_DOT_DIR}/config.toml
	@${ECHO_CMD} "[source.proton-me]" >> ${CARGO_DOT_DIR}/config.toml
	@${ECHO_CMD} "registry = \"sparse+https://rust-registry.proton.me/index/\"" >> ${CARGO_DOT_DIR}/config.toml
	@${ECHO_CMD} "replace-with = 'cargo'" >> ${CARGO_DOT_DIR}/config.toml
	@${_CARGO_AWK} ${SCRIPTSDIR}/cargo-crates-git-configure.awk \
		/dev/null >> ${CARGO_DOT_DIR}/config.toml
	@${CAT} ${CARGO_DOT_DIR}/config.toml
	@if ! ${GREP} -qF '[profile.release]' ${CARGO_CARGOTOML}; then \
		${ECHO_CMD} "" >> ${CARGO_CARGOTOML}; \
		${ECHO_CMD} "[profile.release]" >> ${CARGO_CARGOTOML}; \
		${ECHO_CMD} "opt-level = 2" >> ${CARGO_CARGOTOML}; \
		${ECHO_CMD} "debug = false" >> ${CARGO_CARGOTOML}; \
		${ECHO_CMD} 'strip = "symbols"' >> ${CARGO_CARGOTOML}; \
	fi
	@${ECHO_MSG} "===>   Updating Cargo.lock"
	@${CARGO_CARGO_RUN} update \
		--manifest-path ${CARGO_CARGOTOML} \
		--verbose \
		--verbose \
		${CARGO_UPDATE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/*/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
