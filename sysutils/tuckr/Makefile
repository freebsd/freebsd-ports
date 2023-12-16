PORTNAME=	tuckr
DISTVERSION=	0.8.1
PORTREVISION=	4
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
		anstream-0.3.2 \
		anstyle-1.0.1 \
		anstyle-parse-0.2.1 \
		anstyle-query-1.0.0 \
		anstyle-wincon-1.0.1 \
		arrayvec-0.5.2 \
		bitflags-1.3.2 \
		block-buffer-0.10.4 \
		bytecount-0.6.3 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		chacha20-0.9.1 \
		chacha20poly1305-0.10.1 \
		cipher-0.4.4 \
		clap-4.3.8 \
		clap_builder-4.3.8 \
		clap_derive-4.3.2 \
		clap_lex-0.5.0 \
		colorchoice-1.0.0 \
		cpufeatures-0.2.8 \
		crypto-common-0.1.6 \
		digest-0.10.7 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		errno-0.3.1 \
		errno-dragonfly-0.1.2 \
		fnv-1.0.7 \
		generic-array-0.14.7 \
		getrandom-0.2.10 \
		heck-0.4.1 \
		hermit-abi-0.3.1 \
		inout-0.1.3 \
		io-lifetimes-1.0.11 \
		is-terminal-0.4.7 \
		libc-0.2.147 \
		linux-raw-sys-0.3.8 \
		memchr-2.5.0 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		once_cell-1.18.0 \
		opaque-debug-0.3.0 \
		owo-colors-3.5.0 \
		papergrid-0.7.1 \
		poly1305-0.8.0 \
		ppv-lite86-0.2.17 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.63 \
		quote-1.0.28 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		rpassword-7.2.0 \
		rtoolbox-0.0.1 \
		rustix-0.37.20 \
		same-file-1.0.6 \
		sha2-0.10.7 \
		strsim-0.10.0 \
		subtle-2.5.0 \
		syn-1.0.109 \
		syn-2.0.22 \
		tabled-0.10.0 \
		tabled_derive-0.5.0 \
		thiserror-1.0.40 \
		thiserror-impl-1.0.40 \
		typenum-1.16.0 \
		unicode-ident-1.0.9 \
		unicode-width-0.1.10 \
		universal-hash-0.5.1 \
		utf8parse-0.2.1 \
		version_check-0.9.4 \
		vte-0.10.1 \
		vte_generate_state_changes-0.1.1 \
		walkdir-2.3.3 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.0 \
		windows_aarch64_gnullvm-0.48.0 \
		windows_aarch64_msvc-0.48.0 \
		windows_i686_gnu-0.48.0 \
		windows_i686_msvc-0.48.0 \
		windows_x86_64_gnu-0.48.0 \
		windows_x86_64_gnullvm-0.48.0 \
		windows_x86_64_msvc-0.48.0 \
		zeroize-1.6.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
