PORTNAME=	kalc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.4
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

CARGO_CRATES=	autocfg-1.1.0 \
		az-1.2.1 \
		bitflags-1.3.2 \
		bitflags-2.4.0 \
		byteorder-1.4.3 \
		cfg-if-1.0.0 \
		crossterm-0.27.0 \
		crossterm_winapi-0.9.1 \
		gmp-mpfr-sys-1.6.1 \
		gnuplot-0.0.39 \
		libc-0.2.147 \
		lock_api-0.4.10 \
		log-0.4.20 \
		mio-0.8.8 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.8 \
		redox_syscall-0.3.5 \
		rug-1.20.1 \
		scopeguard-1.2.0 \
		signal-hook-0.3.17 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.1 \
		smallvec-1.11.0 \
		term_size-0.3.2 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.42.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.42.2 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.42.2 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.42.2 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.42.2 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.42.2 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.42.2 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.42.2 \
		windows_x86_64_msvc-0.48.5

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
