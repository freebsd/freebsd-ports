PORTNAME=	kalc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
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

CARGO_CRATES=	autocfg-1.2.0 \
		az-1.2.1 \
		bitflags-1.3.2 \
		bitflags-2.5.0 \
		byteorder-1.5.0 \
		cfg-if-1.0.0 \
		crossterm-0.27.0 \
		crossterm_winapi-0.9.1 \
		dirs-5.0.1 \
		dirs-sys-0.4.1 \
		errno-0.3.8 \
		fastrand-2.0.2 \
		getrandom-0.2.14 \
		gmp-mpfr-sys-1.6.2 \
		gnuplot-0.0.43 \
		libc-0.2.153 \
		libm-0.2.8 \
		libredox-0.1.3 \
		linux-raw-sys-0.4.13 \
		lock_api-0.4.11 \
		log-0.4.21 \
		mio-0.8.11 \
		option-ext-0.2.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.9 \
		proc-macro2-1.0.79 \
		quote-1.0.35 \
		redox_syscall-0.4.1 \
		redox_users-0.4.5 \
		rug-1.24.1 \
		rustix-0.38.32 \
		scopeguard-1.2.0 \
		signal-hook-0.3.17 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.1 \
		smallvec-1.13.2 \
		syn-2.0.58 \
		tempfile-3.10.1 \
		term_size-0.3.2 \
		thiserror-1.0.58 \
		thiserror-impl-1.0.58 \
		unicode-ident-1.0.12 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.4 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.4 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.4 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.4 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.4 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.4 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.4 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.4

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
