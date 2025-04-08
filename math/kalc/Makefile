PORTNAME=	kalc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	math
PKGNAMESUFFIX=	-calculator

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Calculator for real and complex numbers, 2d/3d graphing, etc
WWW=		https://github.com/bgkillas/kalc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails: error: Oops, mp_limb_t is 32 bits, but the assembler code in this configuration expects 64 bits

RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	bgkillas

CARGO_CRATES=	autocfg-1.4.0 \
		az-1.2.1 \
		bitflags-2.8.0 \
		cfg-if-1.0.0 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		crossterm-0.28.1 \
		crossterm_winapi-0.9.1 \
		dirs-6.0.0 \
		dirs-sys-0.5.0 \
		either-1.13.0 \
		errno-0.3.10 \
		fastrand-2.3.0 \
		getrandom-0.2.15 \
		gmp-mpfr-sys-1.6.4 \
		libc-0.2.169 \
		libm-0.2.11 \
		libredox-0.1.3 \
		linux-raw-sys-0.4.15 \
		lock_api-0.4.12 \
		log-0.4.25 \
		mio-1.0.3 \
		option-ext-0.2.0 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		proc-macro2-1.0.93 \
		quote-1.0.38 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		redox_syscall-0.5.8 \
		redox_users-0.5.0 \
		rug-1.27.0 \
		rustix-0.38.44 \
		scopeguard-1.2.0 \
		signal-hook-0.3.17 \
		signal-hook-mio-0.2.4 \
		signal-hook-registry-1.4.2 \
		smallvec-1.14.0 \
		syn-2.0.98 \
		term_size-0.3.2 \
		thiserror-2.0.11 \
		thiserror-impl-2.0.11 \
		unicode-ident-1.0.17 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
