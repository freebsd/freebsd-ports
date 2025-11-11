PORTNAME=	deno-dom
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.56
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Deno: Browser DOM & HTML parser plugin
WWW=		https://jsr.io/@b-fuze/deno-dom \
		https://github.com/b-fuze/deno-dom

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails, mismatched types, see https://github.com/b-fuze/deno-dom/issues/178
BROKEN_i386=	compilation fails, mismatched types, see https://github.com/b-fuze/deno-dom/issues/178
BROKEN_powerpc=	compilation fails, mismatched types, see https://github.com/b-fuze/deno-dom/issues/178

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	b-fuze

CARGO_CRATES=	bitflags-2.10.0 \
		cfg-if-1.0.4 \
		futf-0.1.5 \
		getrandom-0.1.16 \
		html5ever-0.25.2 \
		itoa-1.0.15 \
		libc-0.2.177 \
		lock_api-0.4.14 \
		log-0.4.28 \
		mac-0.1.1 \
		markup5ever-0.10.1 \
		memchr-2.7.6 \
		new_debug_unreachable-1.0.6 \
		parking_lot-0.12.5 \
		parking_lot_core-0.9.12 \
		phf-0.8.0 \
		phf_codegen-0.8.0 \
		phf_generator-0.8.0 \
		phf_generator-0.11.3 \
		phf_shared-0.8.0 \
		phf_shared-0.11.3 \
		ppv-lite86-0.2.21 \
		precomputed-hash-0.1.1 \
		proc-macro2-1.0.103 \
		quote-1.0.41 \
		rand-0.7.3 \
		rand-0.8.5 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_core-0.6.4 \
		rand_hc-0.2.0 \
		rand_pcg-0.2.1 \
		redox_syscall-0.5.18 \
		ryu-1.0.20 \
		scopeguard-1.2.0 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.145 \
		siphasher-0.3.11 \
		siphasher-1.0.1 \
		smallvec-1.15.1 \
		static_vcruntime-2.0.0 \
		string_cache-0.8.9 \
		string_cache_codegen-0.5.4 \
		syn-1.0.109 \
		syn-2.0.108 \
		tendril-0.4.3 \
		unicode-ident-1.0.20 \
		utf-8-0.7.6 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		windows-link-0.2.1 \
		zerocopy-0.8.27 \
		zerocopy-derive-0.8.27

PLIST_FILES=	lib/deno-plugins/deno_dom.so

do-install:
	# binaries (workaround for error: found a virtual manifest at `xx` instead of a package manifest)
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/deno-plugins
	${INSTALL_LIB} \
		${WRKDIR}/target/release/libplugin.so \
		${STAGEDIR}${PREFIX}/lib/deno-plugins/deno_dom.so

.include <bsd.port.mk>
