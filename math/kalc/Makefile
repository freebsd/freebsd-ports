PORTNAME=	kalc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.3
PORTREVISION=	2
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

CARGO_CRATES=	autocfg-1.3.0 \
		az-1.2.1 \
		bitflags-2.6.0 \
		cfg-if-1.0.0 \
		crossterm-0.28.1 \
		crossterm_winapi-0.9.1 \
		dirs-5.0.1 \
		dirs-sys-0.4.1 \
		errno-0.3.9 \
		fastrand-2.1.1 \
		getrandom-0.2.15 \
		gmp-mpfr-sys-1.6.4 \
		hermit-abi-0.3.9 \
		libc-0.2.158 \
		libm-0.2.8 \
		libredox-0.1.3 \
		linux-raw-sys-0.4.14 \
		lock_api-0.4.12 \
		log-0.4.22 \
		mio-1.0.2 \
		option-ext-0.2.0 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		proc-macro2-1.0.86 \
		quote-1.0.37 \
		redox_syscall-0.5.4 \
		redox_users-0.4.6 \
		rug-1.26.1 \
		rustix-0.38.37 \
		scopeguard-1.2.0 \
		signal-hook-0.3.17 \
		signal-hook-mio-0.2.4 \
		signal-hook-registry-1.4.2 \
		smallvec-1.13.2 \
		syn-2.0.77 \
		term_size-0.3.2 \
		thiserror-1.0.64 \
		thiserror-impl-1.0.64 \
		unicode-ident-1.0.13 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
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

.include <bsd.port.mk>
