PORTNAME=	libvmod-fileserver
PORTVERSION=	0.0.9
PORTREVISION=	2
CATEGORIES=	www
PKGNAMEPREFIX=	varnish-

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Varnish Module (vmod) for file server backend
WWW=		https://github.com/gquintard/vmod_fileserver

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	build currently failing

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT} \
		jq>0:textproc/jq \
		rst2man:textproc/py-docutils@${PY_FLAVOR}

USES=		cargo compiler:c++17-lang libtool pkgconfig \
		python:build varnish:7
USE_LDCONFIG=	yes

PLIST_FILES=	lib/varnish/vmods/libvmod_fileserver.so

CARGO_ENV+=	PYTHONDONTWRITEBYTECODE=1
CARGO_CRATES=	aho-corasick-1.1.3 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		autocfg-1.4.0 \
		bindgen-0.70.1 \
		bindgen_helpers-0.4.3 \
		bitflags-2.6.0 \
		block-buffer-0.10.4 \
		bumpalo-3.16.0 \
		cc-1.2.25 \
		cexpr-0.6.0 \
		cfg-if-1.0.0 \
		chrono-0.4.38 \
		clang-sys-1.8.1 \
		convert_case-0.8.0 \
		core-foundation-sys-0.8.7 \
		cpufeatures-0.2.14 \
		crypto-common-0.1.6 \
		darling-0.20.10 \
		darling_core-0.20.10 \
		darling_macro-0.20.10 \
		digest-0.10.7 \
		either-1.13.0 \
		fnv-1.0.7 \
		generic-array-0.14.7 \
		glob-0.3.1 \
		iana-time-zone-0.1.61 \
		iana-time-zone-haiku-0.1.2 \
		ident_case-1.0.1 \
		itertools-0.13.0 \
		itoa-1.0.11 \
		js-sys-0.3.72 \
		libc-0.2.161 \
		libloading-0.8.5 \
		log-0.4.22 \
		memchr-2.7.4 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		num-traits-0.2.19 \
		once_cell-1.20.2 \
		pkg-config-0.3.31 \
		prettyplease-0.2.25 \
		proc-macro2-1.0.89 \
		quote-1.0.37 \
		regex-1.11.1 \
		regex-automata-0.4.8 \
		regex-syntax-0.8.5 \
		rustc-hash-1.1.0 \
		ryu-1.0.18 \
		serde-1.0.213 \
		serde_derive-1.0.213 \
		serde_json-1.0.132 \
		sha2-0.10.8 \
		shlex-1.3.0 \
		strsim-0.11.1 \
		syn-2.0.87 \
		thiserror-2.0.3 \
		thiserror-impl-2.0.3 \
		typenum-1.17.0 \
		unicode-ident-1.0.13 \
		unicode-segmentation-1.12.0 \
		varnish-0.5.0 \
		varnish-macros-0.5.0 \
		varnish-sys-0.5.0 \
		version_check-0.9.5 \
		wasm-bindgen-0.2.95 \
		wasm-bindgen-backend-0.2.95 \
		wasm-bindgen-macro-0.2.95 \
		wasm-bindgen-macro-support-0.2.95 \
		wasm-bindgen-shared-0.2.95 \
		windows-core-0.52.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6

USE_GITHUB=	yes
GH_ACCOUNT=	gquintard
GH_PROJECT=	vmod-fileserver
GH_TAGNAME=	cbd486b

BINARY_ALIAS=	python3=${PYTHON_CMD}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/varnish/vmods/
	${INSTALL_LIB} ${WRKDIR}/target/release/libvmod_fileserver.so ${STAGEDIR}${PREFIX}/lib/varnish/vmods/

.include <bsd.port.mk>
