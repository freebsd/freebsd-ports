PORTNAME=	deno-dom
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.48
PORTREVISION=	8
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

CARGO_CRATES=	autocfg-1.4.0 \
		bitflags-2.6.0 \
		byteorder-1.5.0 \
		cfg-if-1.0.0 \
		futf-0.1.5 \
		getrandom-0.1.16 \
		getrandom-0.2.15 \
		html5ever-0.25.2 \
		itoa-1.0.11 \
		libc-0.2.161 \
		lock_api-0.4.12 \
		log-0.4.22 \
		mac-0.1.1 \
		markup5ever-0.10.1 \
		memchr-2.7.4 \
		new_debug_unreachable-1.0.6 \
		once_cell-1.20.2 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		phf-0.8.0 \
		phf_codegen-0.8.0 \
		phf_generator-0.8.0 \
		phf_generator-0.10.0 \
		phf_shared-0.8.0 \
		phf_shared-0.10.0 \
		ppv-lite86-0.2.20 \
		precomputed-hash-0.1.1 \
		proc-macro2-1.0.89 \
		quote-1.0.37 \
		rand-0.7.3 \
		rand-0.8.5 \
		rand_chacha-0.2.2 \
		rand_chacha-0.3.1 \
		rand_core-0.5.1 \
		rand_core-0.6.4 \
		rand_hc-0.2.0 \
		rand_pcg-0.2.1 \
		redox_syscall-0.5.7 \
		ryu-1.0.18 \
		scopeguard-1.2.0 \
		serde-1.0.214 \
		serde_derive-1.0.214 \
		serde_json-1.0.132 \
		siphasher-0.3.11 \
		smallvec-1.13.2 \
		static_vcruntime-2.0.0 \
		string_cache-0.8.7 \
		string_cache_codegen-0.5.2 \
		syn-1.0.109 \
		syn-2.0.87 \
		tendril-0.4.3 \
		unicode-ident-1.0.13 \
		utf-8-0.7.6 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		zerocopy-0.7.35 \
		zerocopy-derive-0.7.35

PLIST_FILES=	lib/deno-plugins/deno_dom.so

do-install:
	# binaries (workaround for error: found a virtual manifest at `xx` instead of a package manifest)
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/deno-plugins
	${INSTALL_LIB} \
		${WRKDIR}/target/release/libplugin.so \
		${STAGEDIR}${PREFIX}/lib/deno-plugins/deno_dom.so

.include <bsd.port.mk>
