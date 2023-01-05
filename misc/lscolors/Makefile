PORTNAME=	lscolors
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.0
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

CARGO_CRATES=	ansi_term-0.12.1 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		crossterm-0.25.0 \
		crossterm_winapi-0.9.0 \
		fastrand-1.8.0 \
		instant-0.1.12 \
		libc-0.2.139 \
		lock_api-0.4.9 \
		log-0.4.17 \
		mio-0.8.5 \
		nu-ansi-term-0.46.0 \
		overload-0.1.1 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.5 \
		redox_syscall-0.2.16 \
		remove_dir_all-0.5.3 \
		scopeguard-1.1.0 \
		signal-hook-0.3.14 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.0 \
		smallvec-1.10.0 \
		tempfile-3.3.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.0 \
		windows_aarch64_msvc-0.42.0 \
		windows_i686_gnu-0.42.0 \
		windows_i686_msvc-0.42.0 \
		windows_x86_64_gnu-0.42.0 \
		windows_x86_64_gnullvm-0.42.0 \
		windows_x86_64_msvc-0.42.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
