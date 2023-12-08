PORTNAME=	lscolors
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.0
PORTREVISION=	3
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
		bitflags-2.3.3 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		crossterm-0.26.1 \
		crossterm_winapi-0.9.1 \
		errno-0.3.1 \
		errno-dragonfly-0.1.2 \
		fastrand-2.0.0 \
		libc-0.2.147 \
		linux-raw-sys-0.4.3 \
		lock_api-0.4.10 \
		log-0.4.19 \
		mio-0.8.8 \
		nu-ansi-term-0.49.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.8 \
		redox_syscall-0.3.5 \
		rustix-0.38.4 \
		scopeguard-1.2.0 \
		signal-hook-0.3.17 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.1 \
		smallvec-1.11.0 \
		tempfile-3.7.0 \
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
