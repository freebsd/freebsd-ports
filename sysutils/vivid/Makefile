PORTNAME=	vivid
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
PORTREVISION=	5
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

CARGO_CRATES=	ansi_colours-1.0.2 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		bitflags-1.2.1 \
		cc-1.0.68 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		dirs-3.0.2 \
		dirs-sys-0.3.6 \
		getrandom-0.2.3 \
		hermit-abi-0.1.18 \
		lazy_static-1.4.0 \
		libc-0.2.97 \
		linked-hash-map-0.5.4 \
		proc-macro2-1.0.27 \
		quote-1.0.9 \
		redox_syscall-0.2.8 \
		redox_users-0.4.0 \
		rust-embed-5.9.0 \
		rust-embed-impl-5.9.0 \
		rust-embed-utils-5.1.0 \
		same-file-1.0.6 \
		strsim-0.8.0 \
		syn-1.0.73 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		walkdir-2.3.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yaml-rust-0.4.5

PLIST_FILES=	bin/vivid

.include <bsd.port.mk>
