PORTNAME=	tuckr
DISTVERSION=	0.9.0
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Super-powered replacement for GNU Stow
WWW=		https://github.com/RaphGL/Tuckr

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	RaphGL
GH_PROJECT=	Tuckr

CARGO_CRATES=	aead-0.5.2 \
		ansi-str-0.5.0 \
		ansitok-0.2.0 \
		anstream-0.6.15 \
		anstyle-1.0.8 \
		anstyle-parse-0.2.5 \
		anstyle-query-1.1.1 \
		anstyle-wincon-3.0.4 \
		arrayvec-0.5.2 \
		bitflags-2.6.0 \
		block-buffer-0.10.4 \
		bytecount-0.6.8 \
		cfg-if-1.0.0 \
		chacha20-0.9.1 \
		chacha20poly1305-0.10.1 \
		cipher-0.4.4 \
		clap-4.5.11 \
		clap_builder-4.5.11 \
		clap_derive-4.5.11 \
		clap_lex-0.7.2 \
		colorchoice-1.0.2 \
		cpufeatures-0.2.12 \
		crypto-common-0.1.6 \
		digest-0.10.7 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		fnv-1.0.7 \
		generic-array-0.14.7 \
		getrandom-0.2.15 \
		heck-0.4.1 \
		heck-0.5.0 \
		inout-0.1.3 \
		is_terminal_polyfill-1.70.1 \
		libc-0.2.155 \
		libredox-0.1.3 \
		memchr-2.7.4 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		opaque-debug-0.3.1 \
		owo-colors-3.5.0 \
		papergrid-0.7.1 \
		poly1305-0.8.0 \
		ppv-lite86-0.2.17 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.86 \
		quote-1.0.36 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_users-0.4.5 \
		rpassword-7.3.1 \
		rtoolbox-0.0.2 \
		same-file-1.0.6 \
		sha2-0.10.8 \
		strsim-0.11.1 \
		subtle-2.6.1 \
		syn-1.0.109 \
		syn-2.0.72 \
		tabled-0.10.0 \
		tabled_derive-0.5.0 \
		thiserror-1.0.63 \
		thiserror-impl-1.0.63 \
		typenum-1.17.0 \
		unicode-ident-1.0.12 \
		unicode-width-0.1.13 \
		universal-hash-0.5.1 \
		utf8parse-0.2.2 \
		version_check-0.9.5 \
		vte-0.10.1 \
		vte_generate_state_changes-0.1.2 \
		walkdir-2.5.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.8 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.6 \
		zeroize-1.8.1

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
