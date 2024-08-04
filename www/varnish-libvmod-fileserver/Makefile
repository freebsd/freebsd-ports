PORTNAME=	libvmod-fileserver
PORTVERSION=	0.0.5
PORTREVISION=	18
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
CARGO_CRATES=	android_system_properties-0.1.5 \
		autocfg-1.1.0 \
		bindgen-0.64.0 \
		bitflags-1.3.2 \
		bumpalo-3.12.0 \
		cc-1.0.79 \
		cexpr-0.6.0 \
		cfg-if-1.0.0 \
		chrono-0.4.24 \
		clang-sys-1.6.0 \
		codespan-reporting-0.11.1 \
		core-foundation-sys-0.8.3 \
		cxx-1.0.93 \
		cxx-build-1.0.93 \
		cxxbridge-flags-1.0.93 \
		cxxbridge-macro-1.0.93 \
		either-1.8.1 \
		glob-0.3.1 \
		iana-time-zone-0.1.53 \
		iana-time-zone-haiku-0.1.1 \
		js-sys-0.3.61 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.140 \
		libloading-0.7.4 \
		link-cplusplus-1.0.8 \
		log-0.4.17 \
		memchr-2.5.0 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		once_cell-1.17.1 \
		peeking_take_while-0.1.2 \
		pkg-config-0.3.26 \
		proc-macro2-1.0.52 \
		quote-1.0.26 \
		regex-1.7.1 \
		regex-syntax-0.6.28 \
		rustc-hash-1.1.0 \
		scratch-1.0.5 \
		serde-1.0.157 \
		serde_derive-1.0.157 \
		shlex-1.1.0 \
		syn-1.0.109 \
		syn-2.0.2 \
		termcolor-1.2.0 \
		time-0.1.45 \
		unicode-ident-1.0.8 \
		unicode-width-0.1.10 \
		varnish-0.0.17 \
		varnish-sys-0.0.17 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.84 \
		wasm-bindgen-backend-0.2.84 \
		wasm-bindgen-macro-0.2.84 \
		wasm-bindgen-macro-support-0.2.84 \
		wasm-bindgen-shared-0.2.84 \
		which-4.4.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

USE_GITHUB=	yes
GH_ACCOUNT=	gquintard
GH_PROJECT=	vmod_fileserver
GH_TAGNAME=	20ef23b

BINARY_ALIAS=	python3=${PYTHON_CMD}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/varnish/vmods/
	${INSTALL_LIB} ${WRKDIR}/target/*freebsd/release/libvmod_fileserver.so ${STAGEDIR}${PREFIX}/lib/varnish/vmods/

.include <bsd.port.mk>
