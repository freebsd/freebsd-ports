PORTNAME=	mcp-inspector
DISTVERSION=	2.8.0
CATEGORIES=	misc # machine-learning
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Model Context Protocol inspector
WWW=		https://github.com/modelcontextprotocol/inspector \
		https://modelcontextprotocol.io/docs/2026-07-28/tools/inspector

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi
#LICENSE_FILE=	${WRKSRC}/node_modules/${PACKAGE_NAME}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	distinfo was only generated for these architectures # feel free to add more architectures

FETCH_DEPENDS=	npm:www/npm \
		jq:textproc/jq \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
LIB_DEPENDS=	libdbus-1.so:devel/dbus
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		cargo nodejs:run pkgconfig

WRKSRC=		${WRKDIR}/inspector-${DISTVERSION}

PACKAGE_NAME=	@modelcontextprotocol/inspector

JS_ARCH=	${ARCH:S/amd64/x64/:S/aarch64/arm64/:S/i386/ia32/:S/powerpc64le/ppc64le/:S/powerpc64/ppc64/:C/armv[67]/arm/} # modeled after electron.mk
PLIST_SUB=	JS_ARCH=${JS_ARCH}

DD=		${DISTDIR}/${DIST_SUBDIR}

FETCH_SCRIPT=	${PORTSDIR}/Tools/scripts/npmjs-fetch-with-dependencies.sh

# @napi-rs/keyring, @rolldown/binding and lightningcss are native Rust/napi
# addons. Upstream only publishes prebuilt binaries for freebsd-x64 (never
# freebsd-arm64), which is why this port previously failed on aarch64. To
# avoid depending on unverifiable prebuilt binaries on any architecture, we
# always fetch their Rust source and rebuild them ourselves with cargo, on
# every architecture, the same way.
RUST_KEYRING_VERSION=		1.3.0
RUST_LIGHTNINGCSS_VERSION=	1.33.0
RUST_ROLLDOWN_VERSION=		1.2.11

USE_GITHUB=	nodefault
GH_TUPLE=	Brooooooklyn:keyring-node:v${RUST_KEYRING_VERSION}:keyring \
		parcel-bundler:lightningcss:v${RUST_LIGHTNINGCSS_VERSION}:lightningcss \
		rolldown:rolldown:v${RUST_ROLLDOWN_VERSION}:rolldown

# The 3 Rust projects above are independent cargo projects (not a single
# workspace, and none of them is at ${WRKSRC}), so the automatic
# cargo build/install/configure hooks from USES=cargo do not apply; we
# build/install them ourselves below. They share one vendored crates
# directory and one .cargo/config.toml written in post-extract, placed at
# ${WRKDIR} which is their common parent directory.
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_CONFIGURE=	no
CARGO_VENDOR_DIR=	${WRKDIR}/cargo-vendor

.include <bsd.port.pre.mk>

DIST_SUBDIR=	${PORTNAME}/${ARCH}
DISTINFO_FILE=	${.CURDIR}/distinfo.${ARCH}

.include "Makefile.crates"

pre-fetch:
	@if ! [ -f ${DD}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${MKDIR} ${DD} && \
		${ECHO} "====> Fetching ${DISTNAME}${EXTRACT_SUFX}" && \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} ${FETCH_SCRIPT} \
			${PACKAGE_NAME} ${DISTVERSION} \
			${FILESDIR}/package-lock.json \
			${DD}/${DISTNAME}${EXTRACT_SUFX}; \
	fi

post-extract:
	# keyring-node does not ship a Cargo.lock, use the one we generated
	@${CP} ${FILESDIR}/Cargo.lock.keyring ${WRKSRC_keyring}/Cargo.lock
	# single vendored-sources config shared by the 3 cargo projects above
	@${MKDIR} ${WRKDIR}/.cargo
	@${ECHO_CMD} '[source.crates-io]' > ${WRKDIR}/.cargo/config.toml
	@${ECHO_CMD} 'replace-with = "vendored-sources"' >> ${WRKDIR}/.cargo/config.toml
	@${ECHO_CMD} '[source.vendored-sources]' >> ${WRKDIR}/.cargo/config.toml
	@${ECHO_CMD} 'directory = "${CARGO_VENDOR_DIR}"' >> ${WRKDIR}/.cargo/config.toml

NM_NESTED=	${WRKSRC}/node_modules/${PACKAGE_NAME}/node_modules

do-build:
	@${ECHO_MSG} "====> Building @napi-rs/keyring native addon..."
	@cd ${WRKSRC_keyring} && \
		${SETENV} ${CARGO_ENV} CARGO_NET_OFFLINE=true CARGO_TARGET_DIR=${WRKDIR}/target-keyring \
			${CARGO} build --release --locked
	@${MKDIR} ${NM_NESTED}/@napi-rs/keyring-freebsd-${JS_ARCH}
	@${CP} ${WRKDIR}/target-keyring/release/libnapi_keyring.so \
		${NM_NESTED}/@napi-rs/keyring-freebsd-${JS_ARCH}/keyring.freebsd-${JS_ARCH}.node
	@${SED} -e 's/@JSARCH@/${JS_ARCH}/g' -e 's/@KEYRING_VERSION@/${RUST_KEYRING_VERSION}/g' \
		${FILESDIR}/package-keyring-freebsd.json.in \
		> ${NM_NESTED}/@napi-rs/keyring-freebsd-${JS_ARCH}/package.json
	@${ECHO_MSG} "====> Building lightningcss native addon..."
	@cd ${WRKSRC_lightningcss}/node && \
		${SETENV} ${CARGO_ENV} CARGO_NET_OFFLINE=true CARGO_TARGET_DIR=${WRKDIR}/target-lightningcss \
			${CARGO} build --release --locked
	@${MKDIR} ${NM_NESTED}/lightningcss-freebsd-${JS_ARCH}
	@${CP} ${WRKDIR}/target-lightningcss/release/liblightningcss_node.so \
		${NM_NESTED}/lightningcss-freebsd-${JS_ARCH}/lightningcss.freebsd-${JS_ARCH}.node
	@${SED} -e 's/@JSARCH@/${JS_ARCH}/g' -e 's/@LIGHTNINGCSS_VERSION@/${RUST_LIGHTNINGCSS_VERSION}/g' \
		${FILESDIR}/package-lightningcss-freebsd.json.in \
		> ${NM_NESTED}/lightningcss-freebsd-${JS_ARCH}/package.json
	@${CP} ${WRKSRC_lightningcss}/LICENSE \
		${NM_NESTED}/lightningcss-freebsd-${JS_ARCH}/LICENSE
	@${ECHO_MSG} "====> Building @rolldown/binding native addon..."
	@cd ${WRKSRC_rolldown} && \
		${SETENV} ${CARGO_ENV} CARGO_NET_OFFLINE=true CARGO_TARGET_DIR=${WRKDIR}/target-rolldown \
			${CARGO} build --release --locked -p rolldown_binding
	@${MKDIR} ${NM_NESTED}/@rolldown/binding-freebsd-${JS_ARCH}
	@${CP} ${WRKDIR}/target-rolldown/release/librolldown_binding.so \
		${NM_NESTED}/@rolldown/binding-freebsd-${JS_ARCH}/rolldown-binding.freebsd-${JS_ARCH}.node
	@${SED} -e 's/@JSARCH@/${JS_ARCH}/g' -e 's/@ROLLDOWN_VERSION@/${RUST_ROLLDOWN_VERSION}/g' \
		${FILESDIR}/package-rolldown-binding-freebsd.json.in \
		> ${NM_NESTED}/@rolldown/binding-freebsd-${JS_ARCH}/package.json

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/lib
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib
	${FIND} ${STAGEDIR}${PREFIX}/lib -type f -and -name "README.md" -delete
	@${REINPLACE_CMD} -i '' \
		-e "s|#!/usr/bin/env node|#!${PREFIX}/bin/node|" \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/clients/launcher/build/index.js
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/clients/launcher/build/index.js
	@${LN} -s ${PREFIX}/lib/node_modules/.bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	# remove stray file
	@${RM} \
		${STAGEDIR}${LOCALBASE}/lib/package.json \
		${STAGEDIR}${LOCALBASE}/lib/package-lock.json
	# strip native addons
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules -name "*.node" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.post.mk>
