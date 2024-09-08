PORTNAME=	tere
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.1
PORTREVISION=	9
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal file explorer
WWW=		https://github.com/mgunyho/tere

LICENSE=	EUPLv12
LICENSE_NAME=	EUROPEAN UNION PUBLIC LICENCE v. 1.2
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	mgunyho

CARGO_CRATES=	ahash-0.7.6 \
		aho-corasick-1.0.2 \
		anstyle-1.0.1 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bitflags-2.3.3 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		clap-4.3.19 \
		clap_builder-4.3.19 \
		clap_derive-4.3.12 \
		clap_lex-0.5.0 \
		comma-1.0.0 \
		crokey-0.5.1 \
		crokey-proc_macros-0.5.1 \
		crossterm-0.24.0 \
		crossterm_winapi-0.9.1 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		errno-0.3.1 \
		errno-dragonfly-0.1.2 \
		fastrand-2.0.0 \
		getrandom-0.2.10 \
		hashbrown-0.12.3 \
		heck-0.4.1 \
		hermit-abi-0.3.2 \
		io-lifetimes-1.0.11 \
		itoa-1.0.9 \
		libc-0.2.147 \
		linux-raw-sys-0.3.8 \
		linux-raw-sys-0.4.3 \
		lock_api-0.4.10 \
		log-0.4.19 \
		memchr-2.5.0 \
		memoffset-0.6.5 \
		mio-0.8.8 \
		nix-0.25.1 \
		once_cell-1.18.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.8 \
		pin-utils-0.1.0 \
		proc-macro2-1.0.66 \
		quote-1.0.32 \
		redox_syscall-0.2.16 \
		redox_syscall-0.3.5 \
		redox_users-0.4.3 \
		regex-1.9.1 \
		regex-automata-0.3.3 \
		regex-syntax-0.7.4 \
		rexpect-0.5.0 \
		rustix-0.37.23 \
		rustix-0.38.4 \
		rustversion-1.0.14 \
		ryu-1.0.15 \
		scopeguard-1.2.0 \
		serde-1.0.175 \
		serde_derive-1.0.175 \
		serde_json-1.0.103 \
		signal-hook-0.3.17 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.1 \
		smallvec-1.11.0 \
		smawk-0.3.1 \
		strsim-0.10.0 \
		strum-0.24.1 \
		strum_macros-0.24.3 \
		syn-1.0.109 \
		syn-2.0.27 \
		tempfile-3.7.0 \
		terminal_size-0.2.6 \
		textwrap-0.15.2 \
		thiserror-1.0.44 \
		thiserror-impl-1.0.44 \
		unicode-ident-1.0.11 \
		unicode-linebreak-0.1.4 \
		unicode-segmentation-1.10.1 \
		unicode-width-0.1.10 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.1 \
		windows_aarch64_gnullvm-0.48.0 \
		windows_aarch64_msvc-0.48.0 \
		windows_i686_gnu-0.48.0 \
		windows_i686_msvc-0.48.0 \
		windows_x86_64_gnu-0.48.0 \
		windows_x86_64_gnullvm-0.48.0 \
		windows_x86_64_msvc-0.48.0
PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
