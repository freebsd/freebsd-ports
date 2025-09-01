PORTNAME=	rsclock
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.12
PORTREVISION=	4
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple terminal clock written in Rust
WWW=		https://github.com/valebes/rsClock

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	valebes
GH_PROJECT=	rsClock

CARGO_CRATES=	android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		autocfg-0.1.6 \
		bitflags-2.4.1 \
		bumpalo-3.12.1 \
		cc-1.0.79 \
		cfg-if-1.0.0 \
		chrono-0.4.39 \
		codespan-reporting-0.11.1 \
		core-foundation-sys-0.8.4 \
		cxx-1.0.94 \
		cxx-build-1.0.94 \
		cxxbridge-flags-1.0.94 \
		cxxbridge-macro-1.0.94 \
		iana-time-zone-0.1.56 \
		iana-time-zone-haiku-0.1.1 \
		js-sys-0.3.61 \
		libc-0.2.142 \
		libredox-0.1.3 \
		link-cplusplus-1.0.8 \
		log-0.4.17 \
		num-traits-0.2.8 \
		numtoa-0.2.4 \
		once_cell-1.17.1 \
		proc-macro2-1.0.56 \
		quote-1.0.26 \
		redox_syscall-0.5.8 \
		redox_termios-0.1.3 \
		scratch-1.0.5 \
		syn-1.0.109 \
		syn-2.0.15 \
		termcolor-1.2.0 \
		termion-4.0.3 \
		unicode-ident-1.0.8 \
		unicode-width-0.1.10 \
		wasm-bindgen-0.2.84 \
		wasm-bindgen-backend-0.2.84 \
		wasm-bindgen-macro-0.2.84 \
		wasm-bindgen-macro-support-0.2.84 \
		wasm-bindgen-shared-0.2.84 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-0.48.0 \
		windows-targets-0.48.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.48.0 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.48.0 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.48.0 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.48.0 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.48.0 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.48.0 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.48.0 \
		windows_x86_64_msvc-0.52.6

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
