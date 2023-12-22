PORTNAME=	lscolors
#DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
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
CARGO_CRATES=	ansi_term-0.12.1 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bitflags-2.4.1 \
		cfg-if-1.0.0 \
		crossterm-0.27.0 \
		crossterm_winapi-0.9.1 \
		errno-0.3.8 \
		fastrand-2.0.1 \
		libc-0.2.151 \
		linux-raw-sys-0.4.12 \
		lock_api-0.4.11 \
		log-0.4.20 \
		mio-0.8.10 \
		nu-ansi-term-0.49.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.9 \
		redox_syscall-0.4.1 \
		rustix-0.38.28 \
		scopeguard-1.2.0 \
		signal-hook-0.3.17 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.1 \
		smallvec-1.11.2 \
		tempfile-3.8.1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.0 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.0 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.0 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.0 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.0 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.0 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.0 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
