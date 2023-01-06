PORTNAME=	tere
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal file explorer
WWW=		https://github.com/mgunyho/tere

#LICENSE=	EUPL

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	mgunyho

CARGO_CRATES=	aho-corasick-0.7.18 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		clap-3.2.17 \
		clap_lex-0.2.4 \
		crokey-0.5.0 \
		crokey-proc_macros-0.4.0 \
		crossterm-0.24.0 \
		crossterm_winapi-0.9.0 \
		dirs-4.0.0 \
		dirs-sys-0.3.6 \
		getrandom-0.2.4 \
		hashbrown-0.11.2 \
		heck-0.4.0 \
		indexmap-1.8.0 \
		itoa-1.0.1 \
		libc-0.2.126 \
		lock_api-0.4.7 \
		log-0.4.14 \
		memchr-2.4.1 \
		mio-0.8.4 \
		once_cell-1.13.1 \
		os_str_bytes-6.0.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.3 \
		proc-macro2-1.0.43 \
		quote-1.0.21 \
		redox_syscall-0.2.10 \
		redox_users-0.4.0 \
		regex-1.6.0 \
		regex-syntax-0.6.27 \
		rustversion-1.0.9 \
		ryu-1.0.9 \
		scopeguard-1.1.0 \
		serde-1.0.144 \
		serde_derive-1.0.144 \
		serde_json-1.0.85 \
		signal-hook-0.3.13 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.0 \
		smallvec-1.8.0 \
		smawk-0.3.1 \
		strsim-0.10.0 \
		strum-0.24.1 \
		strum_macros-0.24.3 \
		syn-1.0.99 \
		terminal_size-0.1.17 \
		textwrap-0.15.0 \
		unicode-ident-1.0.3 \
		unicode-linebreak-0.1.2 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.36.1 \
		windows_aarch64_msvc-0.36.1 \
		windows_i686_gnu-0.36.1 \
		windows_i686_msvc-0.36.1 \
		windows_x86_64_gnu-0.36.1 \
		windows_x86_64_msvc-0.36.1

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
