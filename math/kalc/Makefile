PORTNAME=	kalc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	3
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
		bitflags-2.9.0 \
		cfg-if-1.0.0 \
		convert_case-0.7.1 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		crossterm-0.29.0 \
		crossterm_winapi-0.9.1 \
		derive_more-2.0.1 \
		derive_more-impl-2.0.1 \
		dirs-6.0.0 \
		dirs-sys-0.5.0 \
		document-features-0.2.11 \
		either-1.15.0 \
		errno-0.3.11 \
		fastrand-2.3.0 \
		getrandom-0.2.16 \
		gmp-mpfr-sys-1.6.5 \
		itoa-1.0.15 \
		kalc-lib-1.5.0 \
		libc-0.2.172 \
		libm-0.2.13 \
		libredox-0.1.3 \
		linux-raw-sys-0.9.4 \
		litrs-0.4.1 \
		lock_api-0.4.12 \
		log-0.4.27 \
		memchr-2.7.4 \
		mio-1.0.3 \
		option-ext-0.2.0 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		proc-macro2-1.0.95 \
		quote-1.0.40 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		redox_syscall-0.5.11 \
		redox_users-0.5.0 \
		rug-1.27.0 \
		rustix-1.0.5 \
		ryu-1.0.20 \
		scopeguard-1.2.0 \
		serde-1.0.219 \
		serde_derive-1.0.219 \
		serde_json-1.0.140 \
		signal-hook-0.3.17 \
		signal-hook-mio-0.2.4 \
		signal-hook-registry-1.4.5 \
		smallvec-1.15.0 \
		syn-2.0.100 \
		term_size-0.3.2 \
		thiserror-2.0.12 \
		thiserror-impl-2.0.12 \
		unicode-ident-1.0.18 \
		unicode-segmentation-1.12.0 \
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
