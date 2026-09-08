PORTNAME=	qh3
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	www python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightway and fast implementation of QUIC and HTTP/3
WWW=		https://qh3.readthedocs.io/en/latest/ \
		https://github.com/jawah/qh3

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilaton fails: error[E0080]: attempt to compute `16_usize - 20_usize`, which would overflow

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.14:devel/py-maturin@${PY_FLAVOR} \
		bash:shells/bash \
		cmake:devel/cmake-core
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.3.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.15.1:devel/py-pytest-mock@${PY_FLAVOR}

USES=		cargo llvm:build python shebangfix
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	jawah
GH_TUPLE=	litespeedtech:ls-qpack:8ff2bf6:ls_qpack/../ls-qpack-rs-86a836850b45593a1635e757439e291214573828/ls-qpack-sys/deps/ls-qpack # workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=279865

SHEBANG_GLOB=	*.sh

CARGO_CRATES=	aes-0.8.4 \
		aho-corasick-1.1.5 \
		asn1-rs-0.7.2 \
		asn1-rs-derive-0.6.0 \
		asn1-rs-impl-0.2.0 \
		autocfg-1.5.1 \
		aws-lc-fips-sys-0.14.2 \
		aws-lc-rs-1.18.0 \
		aws-lc-sys-0.44.0 \
		base64ct-1.8.3 \
		bincode-1.3.3 \
		bindgen-0.72.1 \
		bitflags-2.13.1 \
		block-buffer-0.10.4 \
		block-padding-0.3.3 \
		cbc-0.1.2 \
		cc-1.4.4 \
		cexpr-0.6.0 \
		cfg-if-1.0.4 \
		cfg_aliases-0.2.2 \
		cipher-0.4.4 \
		clang-sys-1.9.1 \
		cmake-0.1.58 \
		const-oid-0.9.6 \
		cpufeatures-0.2.17 \
		crypto-common-0.1.7 \
		curve25519-dalek-4.1.3 \
		curve25519-dalek-derive-0.1.1 \
		data-encoding-2.11.1 \
		der-0.7.10 \
		der-parser-10.0.0 \
		der_derive-0.7.3 \
		deranged-0.5.8 \
		digest-0.10.7 \
		displaydoc-0.2.7 \
		dsa-0.6.3 \
		dunce-1.0.5 \
		ed25519-2.2.3 \
		ed25519-dalek-2.2.0 \
		either-1.18.0 \
		fiat-crypto-0.2.9 \
		find-msvc-tools-0.1.11 \
		flagset-0.4.7 \
		fs_extra-1.3.0 \
		generic-array-0.14.7 \
		getrandom-0.2.17 \
		getrandom-0.4.3 \
		glob-0.3.4 \
		heck-0.5.0 \
		hmac-0.12.1 \
		icu_collections-2.3.0 \
		icu_locale_core-2.3.0 \
		icu_normalizer-2.3.0 \
		icu_normalizer_data-2.3.0 \
		icu_properties-2.3.0 \
		icu_properties_data-2.3.0 \
		icu_provider-2.3.1 \
		idna-1.1.0 \
		idna_adapter-1.2.2 \
		inout-0.1.4 \
		itertools-0.13.0 \
		jobserver-0.1.35 \
		lazy_static-1.5.0 \
		libc-0.2.189 \
		libloading-0.8.9 \
		libm-0.2.16 \
		litemap-0.8.3 \
		log-0.4.34 \
		ls-qpack-rs-0.3.2 \
		ls-qpack-rs-sys-0.3.2 \
		memchr-2.8.3 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		num-bigint-0.4.8 \
		num-bigint-dig-0.8.6 \
		num-conv-0.2.2 \
		num-integer-0.1.47 \
		num-iter-0.1.46 \
		num-traits-0.2.19 \
		oid-registry-0.8.1 \
		once_cell-1.21.4 \
		pbkdf2-0.12.2 \
		pem-rfc7468-0.7.0 \
		pin-project-lite-0.2.17 \
		pkcs1-0.7.5 \
		pkcs5-0.7.1 \
		pkcs8-0.10.2 \
		pkg-config-0.3.34 \
		portable-atomic-1.15.0 \
		potential_utf-0.1.6 \
		powerfmt-0.2.0 \
		ppv-lite86-0.2.21 \
		prettyplease-0.2.37 \
		proc-macro2-1.0.107 \
		pyo3-0.28.3 \
		pyo3-build-config-0.28.3 \
		pyo3-ffi-0.28.3 \
		pyo3-macros-0.28.3 \
		pyo3-macros-backend-0.28.3 \
		python3-dll-a-0.2.15 \
		quinn-udp-0.6.1 \
		quote-1.0.47 \
		r-efi-6.0.0 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		regex-1.13.1 \
		regex-automata-0.4.18 \
		regex-syntax-0.8.11 \
		rfc6979-0.4.0 \
		ring-0.17.14 \
		rsa-0.9.10 \
		rustc-hash-2.1.3 \
		rustc_version-0.4.1 \
		rusticata-macros-4.1.0 \
		rustls-0.23.43 \
		rustls-pemfile-2.2.0 \
		rustls-pki-types-1.15.1 \
		rustls-webpki-0.103.15 \
		salsa20-0.10.2 \
		scrypt-0.11.0 \
		semver-1.0.28 \
		serde-1.0.229 \
		serde_core-1.0.229 \
		serde_derive-1.0.229 \
		sha1-0.10.7 \
		sha2-0.10.9 \
		shlex-1.3.0 \
		shlex-2.0.1 \
		signature-2.2.0 \
		smallvec-1.16.0 \
		socket2-0.6.5 \
		spin-0.9.9 \
		spki-0.7.3 \
		stable_deref_trait-1.2.1 \
		subtle-2.6.1 \
		syn-2.0.119 \
		syn-3.0.4 \
		synstructure-0.13.2 \
		target-lexicon-0.13.5 \
		thiserror-2.0.20 \
		thiserror-impl-2.0.20 \
		time-0.3.55 \
		time-core-0.1.9 \
		time-macros-0.2.32 \
		tinystr-0.8.4 \
		tls_codec-0.4.2 \
		tls_codec_derive-0.4.2 \
		tracing-0.1.44 \
		tracing-core-0.1.36 \
		typenum-1.20.1 \
		unicode-ident-1.0.24 \
		untrusted-0.9.0 \
		utf8_iter-1.0.4 \
		version_check-0.9.5 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		windows-link-0.2.1 \
		windows-sys-0.52.0 \
		windows-sys-0.61.2 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		writeable-0.6.4 \
		x509-cert-0.2.5 \
		x509-ocsp-0.2.1 \
		x509-parser-0.18.1 \
		yoke-0.8.3 \
		yoke-derive-0.8.2 \
		zerocopy-0.8.56 \
		zerocopy-derive-0.8.56 \
		zerofrom-0.1.8 \
		zerofrom-derive-0.1.7 \
		zeroize-1.9.0 \
		zeroize_derive-1.5.0 \
		zerotrie-0.2.5 \
		zerovec-0.11.8 \
		zerovec-derive-0.11.6

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/target

TEST_ARGS=	--import-mode=importlib \
		--disable-plugin-autoload -p asyncio -p pytest_mock --asyncio-mode=auto
TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

# tests as of 2.0.3: 466 passed in 20.05s

.include <bsd.port.mk>
