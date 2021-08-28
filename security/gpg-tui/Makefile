PORTNAME=	gpg-tui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.4
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	se@FreeBSD.org
COMMENT=	Terminal User Interface for GnuPG

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gpgme>=1.7.0:security/gpgme
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libxcb.so:x11/libxcb
RUN_DEPENDS=	gpg:security/gnupg \
		gpgme>=1.7.0:security/gpgme

USES=		cargo python:build
USE_GITHUB=	yes
GH_ACCOUNT=	orhun

CARGO_CRATES=	ansi_term-0.11.0 \
		ansi_term-0.12.1 \
		anyhow-1.0.42 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		block-0.1.6 \
		block-buffer-0.9.0 \
		bytemuck-1.5.1 \
		byteorder-1.4.3 \
		cassowary-0.3.0 \
		cc-1.0.66 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		clipboard-win-3.1.1 \
		color_quant-1.1.0 \
		colorsys-0.6.3 \
		conv-0.3.3 \
		copypasta-0.7.1 \
		copypasta-ext-0.3.7 \
		cpufeatures-0.1.5 \
		crossterm-0.20.0 \
		crossterm_winapi-0.8.0 \
		cstr-argument-0.1.1 \
		ctor-0.1.16 \
		custom_derive-0.1.7 \
		diff-0.1.12 \
		digest-0.9.0 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		dlib-0.4.2 \
		downcast-rs-1.2.0 \
		generic-array-0.14.4 \
		getrandom-0.2.2 \
		gpg-error-0.5.2 \
		gpgme-0.10.0 \
		gpgme-sys-0.10.0 \
		heck-0.3.2 \
		hermit-abi-0.1.17 \
		hex-literal-0.3.3 \
		image-0.23.14 \
		instant-0.1.9 \
		jpeg-decoder-0.1.22 \
		lazy-bytes-cast-5.0.1 \
		lazy_static-1.4.0 \
		libc-0.2.98 \
		libgpg-error-sys-0.5.2 \
		libloading-0.6.7 \
		lock_api-0.4.2 \
		log-0.4.11 \
		malloc_buf-0.0.6 \
		memchr-2.3.4 \
		memmap2-0.1.0 \
		mio-0.7.6 \
		miow-0.3.6 \
		nix-0.18.0 \
		nom-6.1.0 \
		ntapi-0.3.6 \
		num-integer-0.1.44 \
		num-iter-0.1.42 \
		num-rational-0.3.2 \
		num-traits-0.2.14 \
		objc-0.2.7 \
		objc-foundation-0.1.1 \
		objc_id-0.1.1 \
		once_cell-1.5.2 \
		opaque-debug-0.3.0 \
		output_vt100-0.1.2 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.2 \
		pkg-config-0.3.19 \
		pretty_assertions-0.7.2 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.24 \
		quote-1.0.8 \
		redox_syscall-0.1.57 \
		redox_syscall-0.2.6 \
		redox_users-0.4.0 \
		rust-embed-6.0.0 \
		rust-embed-impl-6.0.0 \
		rust-embed-utils-6.0.0 \
		same-file-1.0.6 \
		scoped-tls-1.0.0 \
		scopeguard-1.1.0 \
		sha2-0.9.5 \
		shellexpand-2.1.0 \
		signal-hook-0.3.9 \
		signal-hook-mio-0.2.1 \
		signal-hook-registry-1.4.0 \
		smallvec-1.5.1 \
		smithay-client-toolkit-0.12.2 \
		smithay-clipboard-0.6.3 \
		socket2-0.3.19 \
		static_assertions-1.1.0 \
		strsim-0.8.0 \
		structopt-0.3.22 \
		structopt-derive-0.4.15 \
		syn-1.0.55 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		thiserror-1.0.23 \
		thiserror-impl-1.0.23 \
		time-0.1.44 \
		tui-0.16.0 \
		typenum-1.13.0 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		version_check-0.9.2 \
		walkdir-2.3.2 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wayland-client-0.28.3 \
		wayland-commons-0.28.3 \
		wayland-cursor-0.28.3 \
		wayland-protocols-0.28.3 \
		wayland-scanner-0.28.3 \
		wayland-sys-0.28.3 \
		which-4.0.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.7.0 \
		winreg-0.9.0 \
		x11-clipboard-0.5.1 \
		xcb-0.9.0 \
		xcursor-0.3.3 \
		xml-rs-0.8.3

BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_FILES=	bin/completions \
		bin/gpg-tui \
		man/man1/gpg-tui.1.gz

post-install:
		${INSTALL_DATA} ${WRKSRC}/man/gpg-tui.1 ${STAGEDIR}${MANPREFIX}/man/man1/
		${STRIP_CMD} ${STAGEDIR}${MANPREFIX}/bin/completions
		${STRIP_CMD} ${STAGEDIR}${MANPREFIX}/bin/gpg-tui

.include <bsd.port.mk>
