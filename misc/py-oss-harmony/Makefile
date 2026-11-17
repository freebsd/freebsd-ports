PORTNAME=	oss-harmony
DISTVERSION=	0.0.12
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Response format library for the gpt-oss open-weight model series
WWW=		https://github.com/openai/openai-oss-harmony

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.8<2:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydantic2>=2.11.7:devel/py-pydantic2@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	pep517 autoplist pytest

WRKSRC=		${WRKDIR}/${DISTNAME}

CARGO_CARGOTOML=	${WRKSRC}/Cargo.toml
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_CRATES=	aho-corasick-1.1.4 \
		android_system_properties-0.1.5 \
		anyhow-1.0.102 \
		autocfg-1.5.0 \
		base64-0.22.1 \
		bit-set-0.5.3 \
		bit-vec-0.6.3 \
		block-buffer-0.10.4 \
		bs58-0.5.1 \
		bstr-1.12.1 \
		bumpalo-3.20.2 \
		cc-1.2.62 \
		cfg-if-1.0.4 \
		chrono-0.4.44 \
		core-foundation-sys-0.8.7 \
		cpufeatures-0.2.17 \
		crypto-common-0.1.7 \
		darling-0.23.0 \
		darling_core-0.23.0 \
		darling_macro-0.23.0 \
		deranged-0.5.8 \
		diff-0.1.13 \
		digest-0.10.7 \
		dyn-clone-1.0.20 \
		equivalent-1.0.2 \
		fancy-regex-0.13.0 \
		find-msvc-tools-0.1.9 \
		futures-core-0.3.32 \
		futures-task-0.3.32 \
		futures-util-0.3.32 \
		generic-array-0.14.7 \
		getrandom-0.3.4 \
		hashbrown-0.12.3 \
		hashbrown-0.17.1 \
		heck-0.5.0 \
		hex-0.4.3 \
		iana-time-zone-0.1.65 \
		iana-time-zone-haiku-0.1.2 \
		ident_case-1.0.1 \
		indexmap-1.9.3 \
		indexmap-2.14.0 \
		itoa-1.0.18 \
		jobserver-0.1.34 \
		js-sys-0.3.98 \
		libc-0.2.186 \
		log-0.4.29 \
		memchr-2.8.0 \
		num-conv-0.2.1 \
		num-traits-0.2.19 \
		once_cell-1.21.4 \
		pin-project-lite-0.2.17 \
		pkg-config-0.3.33 \
		portable-atomic-1.13.1 \
		powerfmt-0.2.0 \
		pretty_assertions-1.4.1 \
		proc-macro2-1.0.106 \
		pyo3-0.29.0 \
		pyo3-build-config-0.29.0 \
		pyo3-ffi-0.29.0 \
		pyo3-macros-0.29.0 \
		pyo3-macros-backend-0.29.0 \
		quote-1.0.45 \
		r-efi-5.3.0 \
		ref-cast-1.0.25 \
		ref-cast-impl-1.0.25 \
		regex-automata-0.4.14 \
		regex-syntax-0.8.10 \
		rustc-hash-1.1.0 \
		rustversion-1.0.22 \
		schemars-0.9.0 \
		schemars-1.2.1 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.149 \
		serde_with-3.21.0 \
		serde_with_macros-3.21.0 \
		sha2-0.10.9 \
		shlex-1.3.0 \
		slab-0.4.12 \
		strsim-0.11.1 \
		syn-2.0.117 \
		target-lexicon-0.13.5 \
		thiserror-2.0.18 \
		thiserror-impl-2.0.18 \
		time-0.3.47 \
		time-core-0.1.8 \
		time-macros-0.2.27 \
		tinyvec-1.11.0 \
		tinyvec_macros-0.1.1 \
		typenum-1.20.0 \
		unicode-ident-1.0.24 \
		version_check-0.9.5 \
		wasip2-1.0.3+wasi-0.2.9 \
		wasm-bindgen-0.2.121 \
		wasm-bindgen-macro-0.2.121 \
		wasm-bindgen-macro-support-0.2.121 \
		wasm-bindgen-shared-0.2.121 \
		windows-core-0.62.2 \
		windows-implement-0.60.2 \
		windows-interface-0.59.3 \
		windows-link-0.2.1 \
		windows-result-0.4.1 \
		windows-strings-0.5.1 \
		wit-bindgen-0.57.1 \
		yansi-1.0.1 \
		zmij-1.0.21 \
		zstd-0.14.3 \
		zstd-safe-8.2.0 \
		zstd-sys-2.1.2+zstd.1.5.7

TEST_ARGS=	--disable-plugin-autoload

# tests as of 0.0.12: 42 passed in 3.49s

.include <bsd.port.mk>
