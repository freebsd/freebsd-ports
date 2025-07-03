PORTNAME=	vivid
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
PORTREVISION=	32
CATEGORIES=	sysutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Themeable LS_COLORS generator with a rich filetype datebase
WWW=		https://github.com/sharkdp/vivid

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

CARGO_CRATES=	ansi_colours-1.0.4 \
		ansi_term-0.12.1 \
		atty-0.2.14 \
		bitflags-1.3.2 \
		block-buffer-0.9.0 \
		cc-1.0.72 \
		cfg-if-1.0.0 \
		clap-2.34.0 \
		cpufeatures-0.2.1 \
		digest-0.9.0 \
		dirs-4.0.0 \
		dirs-sys-0.3.6 \
		generic-array-0.14.5 \
		getrandom-0.2.4 \
		hermit-abi-0.1.19 \
		lazy_static-1.4.0 \
		libc-0.2.116 \
		linked-hash-map-0.5.4 \
		opaque-debug-0.3.0 \
		proc-macro2-1.0.36 \
		quote-1.0.15 \
		redox_syscall-0.2.10 \
		redox_users-0.4.0 \
		rust-embed-6.3.0 \
		rust-embed-impl-6.2.0 \
		rust-embed-utils-7.1.0 \
		same-file-1.0.6 \
		sha2-0.9.9 \
		strsim-0.8.0 \
		syn-1.0.86 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		typenum-1.15.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		walkdir-2.3.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yaml-rust-0.4.5

PLIST_FILES=	bin/vivid

.include <bsd.port.mk>
