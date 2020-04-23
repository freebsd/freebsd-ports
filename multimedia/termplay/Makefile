# $FreeBSD$

PORTNAME=	termplay
DISTVERSION=	2.0.5
PORTREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	CRATESIO
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool that converts images to ANSI sequences, plays videos in terminals

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsixel.so:graphics/libsixel

USES=		cargo gnome
USE_GNOME=	glib20
USE_GSTREAMER1=	yes

CARGO_FEATURES=	bin
CARGO_CRATES=	\
		adler32-1.0.2 \
		ansi_term-0.11.0 \
		arrayvec-0.4.7 \
		atty-0.2.11 \
		backtrace-0.3.8 \
		backtrace-sys-0.1.23 \
		bitflags-1.0.3 \
		byteorder-1.2.3 \
		cc-1.0.17 \
		cfg-if-0.1.3 \
		clap-2.33.0 \
		color_quant-1.0.0 \
		crossbeam-deque-0.2.0 \
		crossbeam-epoch-0.3.1 \
		crossbeam-utils-0.2.2 \
		deflate-0.7.18 \
		either-1.5.0 \
		failure-0.1.1 \
		failure_derive-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		gif-0.10.0 \
		glib-0.5.0 \
		glib-sys-0.6.0 \
		gobject-sys-0.6.0 \
		gstreamer-0.11.2 \
		gstreamer-app-0.11.2 \
		gstreamer-app-sys-0.5.0 \
		gstreamer-base-0.11.0 \
		gstreamer-base-sys-0.5.0 \
		gstreamer-sys-0.5.0 \
		image-0.19.0 \
		inflate-0.4.2 \
		jpeg-decoder-0.1.14 \
		lazy_static-1.0.1 \
		libc-0.2.49 \
		lzw-0.10.0 \
		memoffset-0.2.1 \
		muldiv-0.1.1 \
		nodrop-0.1.12 \
		num-derive-0.2.2 \
		num-integer-0.1.38 \
		num-iter-0.1.37 \
		num-rational-0.1.42 \
		num-traits-0.2.4 \
		num_cpus-1.8.0 \
		pkg-config-0.3.11 \
		png-0.12.0 \
		proc-macro2-0.4.4 \
		quote-0.3.15 \
		quote-0.6.3 \
		rand-0.4.2 \
		rayon-1.0.1 \
		rayon-core-1.4.0 \
		redox_syscall-0.1.56 \
		redox_termios-0.1.1 \
		rustc-demangle-0.1.8 \
		scoped_threadpool-0.1.9 \
		scopeguard-0.3.3 \
		strsim-0.8.0 \
		syn-0.11.11 \
		syn-0.14.1 \
		synom-0.11.3 \
		synstructure-0.6.1 \
		termion-1.5.1 \
		textwrap-0.11.0 \
		unicode-width-0.1.5 \
		unicode-xid-0.0.4 \
		unicode-xid-0.1.0 \
		vec_map-0.8.1 \
		winapi-0.3.4 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
