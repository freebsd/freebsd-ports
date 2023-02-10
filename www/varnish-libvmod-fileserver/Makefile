PORTNAME=	libvmod-fileserver
PORTVERSION=	0.0.5
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	varnish-

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Varnish Module (vmod) for file server backend
WWW=		https://github.com/gquintard/vmod_fileserver

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT} \
		jq>0:textproc/jq \
		rst2man:textproc/py-docutils@${PY_FLAVOR}

USES=		cargo compiler:c++17-lang libtool pkgconfig \
		python:3.5+,build varnish:7
USE_LDCONFIG=	yes

PLIST_FILES=	lib/varnish/vmods/libvmod_fileserver.so

CARGO_ENV+=	PYTHONDONTWRITEBYTECODE=1
CARGO_CRATES=	aho-corasick-0.7.18 \
		android_system_properties-0.1.5 \
		ansi_term-0.12.1 \
		anyhow-1.0.57 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bindgen-0.59.2 \
		bitflags-1.3.2 \
		bumpalo-3.11.1 \
		cc-1.0.78 \
		cexpr-0.6.0 \
		cfg-if-1.0.0 \
		chrono-0.4.23 \
		clang-sys-1.3.0 \
		clap-2.34.0 \
		codespan-reporting-0.11.1 \
		core-foundation-sys-0.8.3 \
		cxx-1.0.68 \
		cxx-build-1.0.68 \
		cxxbridge-flags-1.0.68 \
		cxxbridge-macro-1.0.68 \
		either-1.6.1 \
		env_logger-0.9.0 \
		glob-0.3.0 \
		hermit-abi-0.1.19 \
		humantime-2.1.0 \
		iana-time-zone-0.1.53 \
		iana-time-zone-haiku-0.1.1 \
		itoa-1.0.1 \
		js-sys-0.3.58 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.139 \
		libloading-0.7.2 \
		link-cplusplus-1.0.8 \
		log-0.4.14 \
		memchr-2.4.1 \
		minimal-lexical-0.2.1 \
		nom-7.1.0 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		once_cell-1.9.0 \
		peeking_take_while-0.1.2 \
		pkg-config-0.3.22 \
		proc-macro2-1.0.32 \
		quote-1.0.10 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		rustc-hash-1.1.0 \
		ryu-1.0.9 \
		scratch-1.0.3 \
		serde-1.0.133 \
		serde_derive-1.0.133 \
		serde_json-1.0.74 \
		shlex-1.1.0 \
		strsim-0.8.0 \
		syn-1.0.85 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		time-0.1.45 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		varnish-0.0.12 \
		varnish-sys-0.0.12 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.81 \
		wasm-bindgen-backend-0.2.81 \
		wasm-bindgen-macro-0.2.81 \
		wasm-bindgen-macro-support-0.2.81 \
		wasm-bindgen-shared-0.2.81 \
		which-4.2.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

USE_GITHUB=	yes
GH_ACCOUNT=	gquintard
GH_PROJECT=	vmod_fileserver
GH_TAGNAME=	f6a6587

post-extract:
	${REINPLACE_CMD} 's|python3|${PYTHON_VERSION}|g' ${WRKSRC}/cargo-crates/varnish-*/src/lib.rs

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/varnish/vmods/
	${INSTALL_LIB} ${WRKDIR}/target/*freebsd/release/libvmod_fileserver.so ${STAGEDIR}${PREFIX}/lib/varnish/vmods/

.include <bsd.port.mk>
