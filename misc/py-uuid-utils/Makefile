PORTNAME=	uuid-utils
DISTVERSION=	0.12.0
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
		atomic-0.6.1 \
		autocfg-1.1.0 \
		bitflags-2.5.0 \
		block-buffer-0.10.4 \
		bumpalo-3.19.0 \
		bytemuck-1.23.2 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		cfg_aliases-0.2.1 \
		crypto-common-0.1.6 \
		digest-0.10.7 \
		generic-array-0.14.7 \
		getrandom-0.3.2 \
		heck-0.5.0 \
		indoc-2.0.5 \
		js-sys-0.3.77 \
		libc-0.2.171 \
		log-0.4.27 \
		mac_address-1.1.8 \
		md-5-0.10.6 \
		memoffset-0.9.0 \
		nix-0.29.0 \
		once_cell-1.21.3 \
		portable-atomic-1.6.0 \
		ppv-lite86-0.2.17 \
		proc-macro2-1.0.86 \
		pyo3-0.27.2 \
		pyo3-build-config-0.27.2 \
		pyo3-ffi-0.27.2 \
		pyo3-macros-0.27.2 \
		pyo3-macros-backend-0.27.2 \
		python3-dll-a-0.2.13 \
		quote-1.0.36 \
		r-efi-5.2.0 \
		rand-0.9.2 \
		rand_chacha-0.9.0 \
		rand_core-0.9.3 \
		rustversion-1.0.22 \
		sha1_smol-1.0.1 \
		syn-2.0.68 \
		target-lexicon-0.13.2 \
		typenum-1.18.0 \
		unicode-ident-1.0.12 \
		unindent-0.2.3 \
		uuid-1.18.1 \
		version_check-0.9.4 \
		wasi-0.14.2+wasi-0.2.4 \
		wasm-bindgen-0.2.100 \
		wasm-bindgen-backend-0.2.100 \
		wasm-bindgen-macro-0.2.100 \
		wasm-bindgen-macro-support-0.2.100 \
		wasm-bindgen-shared-0.2.100 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wit-bindgen-rt-0.39.0 \
		zerocopy-0.8.26 \
		zerocopy-derive-0.8.26

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 0.12.0: 41 passed in 0.35s

.include <bsd.port.mk>
