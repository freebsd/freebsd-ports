PORTNAME=	uuid-utils
DISTVERSION=	0.16.0
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
		autocfg-1.5.0 \
		bitflags-2.5.0 \
		block-buffer-0.10.4 \
		bumpalo-3.19.0 \
		bytemuck-1.23.2 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		cfg_aliases-0.2.1 \
		chacha20-0.10.0 \
		cpufeatures-0.3.0 \
		crypto-common-0.1.6 \
		digest-0.10.7 \
		equivalent-1.0.2 \
		foldhash-0.1.5 \
		generic-array-0.14.7 \
		getrandom-0.3.2 \
		getrandom-0.4.1 \
		hashbrown-0.15.5 \
		hashbrown-0.16.1 \
		heck-0.5.0 \
		id-arena-2.3.0 \
		indexmap-2.13.0 \
		itoa-1.0.17 \
		js-sys-0.3.77 \
		leb128fmt-0.1.0 \
		libc-0.2.171 \
		log-0.4.27 \
		mac_address-1.1.8 \
		md-5-0.10.6 \
		memchr-2.8.0 \
		memoffset-0.9.1 \
		nix-0.29.0 \
		once_cell-1.21.3 \
		portable-atomic-1.6.0 \
		prettyplease-0.2.37 \
		proc-macro2-1.0.106 \
		pyo3-0.28.3 \
		pyo3-build-config-0.28.3 \
		pyo3-ffi-0.28.3 \
		pyo3-macros-0.28.3 \
		pyo3-macros-backend-0.28.3 \
		python3-dll-a-0.2.15 \
		quote-1.0.44 \
		r-efi-5.2.0 \
		rand-0.10.1 \
		rand_core-0.10.0 \
		semver-1.0.27 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.149 \
		sha1_smol-1.0.1 \
		syn-2.0.117 \
		target-lexicon-0.13.5 \
		typenum-1.18.0 \
		unicode-ident-1.0.12 \
		unicode-xid-0.2.6 \
		uuid-1.23.1 \
		version_check-0.9.4 \
		wasi-0.14.2+wasi-0.2.4 \
		wasip2-1.0.2+wasi-0.2.9 \
		wasip3-0.4.0+wasi-0.3.0-rc-2026-01-06 \
		wasm-bindgen-0.2.100 \
		wasm-bindgen-backend-0.2.100 \
		wasm-bindgen-macro-0.2.100 \
		wasm-bindgen-macro-support-0.2.100 \
		wasm-bindgen-shared-0.2.100 \
		wasm-encoder-0.244.0 \
		wasm-metadata-0.244.0 \
		wasmparser-0.244.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wit-bindgen-0.51.0 \
		wit-bindgen-core-0.51.0 \
		wit-bindgen-rt-0.39.0 \
		wit-bindgen-rust-0.51.0 \
		wit-bindgen-rust-macro-0.51.0 \
		wit-component-0.244.0 \
		wit-parser-0.244.0 \
		zerocopy-0.8.26 \
		zerocopy-derive-0.8.26 \
		zmij-1.0.21

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	tests/

# tests as of 0.14.1: 162 passed

.include <bsd.port.mk>
