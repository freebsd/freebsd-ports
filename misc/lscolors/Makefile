PORTNAME=	lscolors
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.0
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool to colorize paths using LS_COLORS
WWW=		https://github.com/sharkdp/lscolors

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

CARGO_FEATURES=	nu-ansi-term
CARGO_CRATES=	aho-corasick-1.1.4 \
		ansi_term-0.12.1 \
		bitflags-2.10.0 \
		cfg-if-1.0.4 \
		convert_case-0.7.1 \
		crossterm-0.29.0 \
		crossterm_winapi-0.9.1 \
		derive_more-2.0.1 \
		derive_more-impl-2.0.1 \
		document-features-0.2.12 \
		errno-0.3.14 \
		fastrand-2.3.0 \
		getrandom-0.3.4 \
		libc-0.2.177 \
		linux-raw-sys-0.11.0 \
		litrs-1.0.0 \
		lock_api-0.4.14 \
		log-0.4.28 \
		memchr-2.7.6 \
		mio-1.1.0 \
		nu-ansi-term-0.50.3 \
		once_cell-1.21.3 \
		owo-colors-4.2.3 \
		parking_lot-0.12.5 \
		parking_lot_core-0.9.12 \
		proc-macro2-1.0.103 \
		quote-1.0.42 \
		r-efi-5.3.0 \
		redox_syscall-0.5.18 \
		rustix-1.1.2 \
		scopeguard-1.2.0 \
		signal-hook-0.3.18 \
		signal-hook-mio-0.2.5 \
		signal-hook-registry-1.4.7 \
		smallvec-1.15.1 \
		syn-2.0.111 \
		tempfile-3.23.0 \
		unicode-ident-1.0.22 \
		unicode-segmentation-1.12.0 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		wasip2-1.0.1+wasi-0.2.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		wit-bindgen-0.46.0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
