PORTNAME=	uuid-utils
DISTVERSION=	0.16.1
PORTREVISION=	0
CATEGORIES=	misc python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
#DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Drop-in replacement for Python UUID
WWW=		https://aminalaee.github.io/uuid-utils/ \
		https://github.com/aminalaee/uuid-utils

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1:devel/py-maturin@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	aminalaee

CARGO_CRATES=	ahash-0.8.12 \
		anyhow-1.0.102 \
		atomic-0.6.1 \
		autocfg-1.5.1 \
		bitflags-2.13.0 \
		block-buffer-0.10.4 \
		bumpalo-3.20.3 \
		bytemuck-1.25.0 \
		cfg-if-1.0.4 \
		cfg_aliases-0.2.1 \
		chacha20-0.10.0 \
		cpufeatures-0.3.0 \
		crypto-common-0.1.7 \
		digest-0.10.7 \
		equivalent-1.0.2 \
		foldhash-0.1.5 \
		futures-core-0.3.32 \
		futures-task-0.3.32 \
		futures-util-0.3.32 \
		generic-array-0.14.7 \
		getrandom-0.3.4 \
		getrandom-0.4.2 \
		hashbrown-0.15.5 \
		hashbrown-0.17.1 \
		heck-0.5.0 \
		id-arena-2.3.0 \
		indexmap-2.14.0 \
		itoa-1.0.18 \
		js-sys-0.3.102 \
		leb128fmt-0.1.0 \
		libc-0.2.186 \
		log-0.4.32 \
		mac_address-1.1.8 \
		md-5-0.10.6 \
		memchr-2.8.2 \
		memoffset-0.9.1 \
		nix-0.29.0 \
		once_cell-1.21.4 \
		pin-project-lite-0.2.17 \
		portable-atomic-1.13.1 \
		prettyplease-0.2.37 \
		proc-macro2-1.0.106 \
		pyo3-0.29.0 \
		pyo3-build-config-0.29.0 \
		pyo3-ffi-0.29.0 \
		pyo3-macros-0.29.0 \
		pyo3-macros-backend-0.29.0 \
		quote-1.0.45 \
		r-efi-5.3.0 \
		r-efi-6.0.0 \
		rand-0.10.1 \
		rand_core-0.10.1 \
		rustversion-1.0.22 \
		semver-1.0.28 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.150 \
		sha1_smol-1.0.1 \
		slab-0.4.12 \
		syn-2.0.117 \
		target-lexicon-0.13.5 \
		typenum-1.20.1 \
		unicode-ident-1.0.24 \
		unicode-xid-0.2.6 \
		uuid-1.23.3 \
		version_check-0.9.5 \
		wasip2-1.0.4+wasi-0.2.12 \
		wasip3-0.4.0+wasi-0.3.0-rc-2026-01-06 \
		wasm-bindgen-0.2.125 \
		wasm-bindgen-macro-0.2.125 \
		wasm-bindgen-macro-support-0.2.125 \
		wasm-bindgen-shared-0.2.125 \
		wasm-encoder-0.244.0 \
		wasm-metadata-0.244.0 \
		wasmparser-0.244.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wit-bindgen-0.51.0 \
		wit-bindgen-0.57.1 \
		wit-bindgen-core-0.51.0 \
		wit-bindgen-rust-0.51.0 \
		wit-bindgen-rust-macro-0.51.0 \
		wit-component-0.244.0 \
		wit-parser-0.244.0 \
		zerocopy-0.8.52 \
		zerocopy-derive-0.8.52 \
		zmij-1.0.21

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	tests/

# tests as of 0.14.1: 162 passed

.include <bsd.port.mk>
