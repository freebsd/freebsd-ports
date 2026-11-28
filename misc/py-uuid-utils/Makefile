PORTNAME=	uuid-utils
DISTVERSION=	1.3.0
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
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-benchmark>0:devel/py-pytest-benchmark@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	aminalaee

CARGO_CRATES=	autocfg-1.5.1 \
		bitflags-2.13.2 \
		block-buffer-0.10.4 \
		bumpalo-3.20.4 \
		cfg-if-1.0.5 \
		cfg_aliases-0.2.2 \
		chacha20-0.10.2 \
		cpufeatures-0.3.1 \
		crypto-common-0.1.7 \
		digest-0.10.7 \
		futures-core-0.3.34 \
		futures-task-0.3.34 \
		futures-util-0.3.34 \
		generic-array-0.14.7 \
		getrandom-0.4.3 \
		heck-0.5.0 \
		js-sys-0.3.107 \
		libc-0.2.191 \
		mac_address-1.2.1 \
		md-5-0.10.6 \
		memoffset-0.9.1 \
		nix-0.31.4 \
		once_cell-1.21.4 \
		pin-project-lite-0.2.18 \
		portable-atomic-1.15.0 \
		proc-macro2-1.0.107 \
		pyo3-0.30.1 \
		pyo3-build-config-0.30.1 \
		pyo3-ffi-0.30.1 \
		pyo3-macros-0.30.1 \
		pyo3-macros-backend-0.30.1 \
		quote-1.0.47 \
		r-efi-6.0.0 \
		rand-0.10.4 \
		rand_core-0.10.1 \
		rustversion-1.0.23 \
		sha1_smol-1.0.1 \
		slab-0.4.12 \
		syn-3.0.10 \
		target-lexicon-0.13.6 \
		typenum-1.20.1 \
		unicode-ident-1.0.27 \
		uuid-1.29.3 \
		version_check-0.9.5 \
		wasm-bindgen-0.2.130 \
		wasm-bindgen-macro-0.2.130 \
		wasm-bindgen-macro-support-0.2.130 \
		wasm-bindgen-shared-0.2.130 \
		windows-link-0.2.1 \
		windows-sys-0.61.2

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload -p pytest_benchmark.plugin --benchmark-disable \
		tests/

# tests as of 1.3.0: 101 passed, 12 skipped, 1 xpassed in 0.05s

.include <bsd.port.mk>
