# $FreeBSD$

PORTNAME=	vivid
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	sysutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Themeable LS_COLORS generator with a rich filetype datebase

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

CARGO_CRATES=	ansi_colours-1.0.1 \
		ansi_term-0.11.0 \
		arrayref-0.3.6 \
		arrayvec-0.5.1 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.12.3 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.10 \
		cc-1.0.60 \
		cfg-if-0.1.10 \
		clap-2.33.3 \
		constant_time_eq-0.1.5 \
		crossbeam-utils-0.7.2 \
		dirs-3.0.1 \
		dirs-sys-0.3.5 \
		getrandom-0.1.15 \
		hermit-abi-0.1.15 \
		lazy_static-1.4.0 \
		libc-0.2.77 \
		linked-hash-map-0.5.3 \
		proc-macro2-1.0.21 \
		quote-1.0.7 \
		redox_syscall-0.1.57 \
		redox_users-0.3.5 \
		rust-argon2-0.8.2 \
		rust-embed-5.6.0 \
		rust-embed-impl-5.6.0 \
		rust-embed-utils-5.0.0 \
		same-file-1.0.6 \
		strsim-0.8.0 \
		syn-1.0.41 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vec_map-0.8.2 \
		walkdir-2.3.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yaml-rust-0.4.4

PLIST_FILES=	bin/vivid

.include <bsd.port.mk>
