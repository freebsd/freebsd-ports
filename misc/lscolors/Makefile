PORTNAME=	lscolors
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.0
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
CARGO_CRATES=	aho-corasick-1.1.3 \
		ansi_term-0.12.1 \
		autocfg-1.3.0 \
		bitflags-2.6.0 \
		cfg-if-1.0.0 \
		crossterm-0.27.0 \
		crossterm_winapi-0.9.1 \
		errno-0.3.9 \
		fastrand-2.1.0 \
		libc-0.2.158 \
		linux-raw-sys-0.4.14 \
		lock_api-0.4.12 \
		log-0.4.22 \
		memchr-2.7.4 \
		mio-0.8.11 \
		nu-ansi-term-0.50.1 \
		once_cell-1.19.0 \
		owo-colors-4.0.0 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		redox_syscall-0.5.3 \
		rustix-0.38.34 \
		scopeguard-1.2.0 \
		signal-hook-0.3.17 \
		signal-hook-mio-0.2.4 \
		signal-hook-registry-1.4.2 \
		smallvec-1.13.2 \
		tempfile-3.12.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
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
		windows_x86_64_msvc-0.52.6

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
