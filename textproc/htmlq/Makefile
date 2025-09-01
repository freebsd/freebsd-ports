PORTNAME=	htmlq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	33
CATEGORIES=	textproc

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Command-line HTML processor, similar to jq
WWW=		https://github.com/mgdm/htmlq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	mgdm

CARGO_CRATES=	ansi_term-0.11.0 \
		atty-0.2.14 \
		bitflags-1.3.2 \
		byteorder-1.4.3 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		convert_case-0.4.0 \
		cssparser-0.27.2 \
		cssparser-macros-0.6.0 \
		derive_more-0.99.16 \
		dtoa-0.4.8 \
		dtoa-short-0.3.3 \
		form_urlencoded-1.0.1 \
		futf-0.1.4 \
		fxhash-0.2.1 \
		getrandom-0.1.16 \
		hermit-abi-0.1.19 \
		html5ever-0.25.1 \
		idna-0.2.3 \
		itoa-0.4.8 \
		kuchiki-0.8.1 \
		lazy_static-1.4.0 \
		libc-0.2.101 \
		log-0.4.14 \
		mac-0.1.1 \
		markup5ever-0.10.1 \
		matches-0.1.9 \
		new_debug_unreachable-1.0.4 \
		nodrop-0.1.14 \
		percent-encoding-2.1.0 \
		pest-2.1.3 \
		phf-0.8.0 \
		phf_codegen-0.8.0 \
		phf_generator-0.8.0 \
		phf_macros-0.8.0 \
		phf_shared-0.8.0 \
		ppv-lite86-0.2.10 \
		precomputed-hash-0.1.1 \
		proc-macro-hack-0.5.19 \
		proc-macro2-1.0.29 \
		quote-1.0.9 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_pcg-0.2.1 \
		rustc_version-0.3.3 \
		selectors-0.22.0 \
		semver-0.11.0 \
		semver-parser-0.10.2 \
		serde-1.0.130 \
		servo_arc-0.1.1 \
		siphasher-0.3.7 \
		smallvec-1.6.1 \
		stable_deref_trait-1.2.0 \
		string_cache-0.8.1 \
		string_cache_codegen-0.5.1 \
		strsim-0.8.0 \
		syn-1.0.76 \
		tendril-0.4.2 \
		textwrap-0.11.0 \
		thin-slice-0.1.1 \
		tinyvec-1.3.1 \
		tinyvec_macros-0.1.0 \
		ucd-trie-0.1.3 \
		unicode-bidi-0.3.6 \
		unicode-normalization-0.1.19 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		url-2.2.2 \
		utf-8-0.7.6 \
		vec_map-0.8.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
