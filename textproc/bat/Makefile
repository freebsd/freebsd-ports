# $FreeBSD$

PORTNAME=	bat
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
CATEGORIES=	textproc

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Clone of cat with syntax highlighting

LICENSE=	APACHE20

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

PLIST_FILES=	bin/bat

CARGO_CRATES=	aho-corasick-0.6.4 \
		ansi_term-0.10.2 \
		ansi_term-0.11.0 \
		atty-0.2.10 \
		base64-0.8.0 \
		bincode-1.0.0 \
		bitflags-1.0.3 \
		byteorder-1.2.2 \
		bytes-0.4.7 \
		cc-1.0.15 \
		cfg-if-0.1.3 \
		chrono-0.4.2 \
		clap-2.31.2 \
		clicolors-control-0.2.0 \
		cmake-0.1.31 \
		console-0.6.1 \
		directories-0.10.0 \
		dtoa-0.4.2 \
		duct-0.10.0 \
		error-chain-0.11.0 \
		flate2-1.0.1 \
		fnv-1.0.6 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		gcc-0.3.54 \
		git2-0.7.1 \
		idna-0.1.4 \
		iovec-0.1.2 \
		itoa-0.4.1 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.11 \
		lazy_static-1.0.0 \
		lazycell-0.6.0 \
		libc-0.2.40 \
		libgit2-sys-0.7.1 \
		libz-sys-1.0.18 \
		linked-hash-map-0.5.1 \
		log-0.4.1 \
		matches-0.1.6 \
		memchr-2.0.1 \
		miniz-sys-0.1.10 \
		nix-0.10.0 \
		num-integer-0.1.36 \
		num-traits-0.2.2 \
		onig-3.2.2 \
		onig_sys-68.0.1 \
		os_pipe-0.6.1 \
		owning_ref-0.3.3 \
		parking_lot-0.5.5 \
		parking_lot_core-0.2.14 \
		percent-encoding-1.0.1 \
		pkg-config-0.3.11 \
		plist-0.2.4 \
		proc-macro2-0.3.8 \
		quote-0.5.2 \
		rand-0.4.2 \
		redox_syscall-0.1.37 \
		redox_termios-0.1.1 \
		regex-0.2.11 \
		regex-syntax-0.4.2 \
		regex-syntax-0.5.6 \
		safemem-0.2.0 \
		same-file-1.0.2 \
		serde-1.0.51 \
		serde_derive-1.0.51 \
		serde_json-1.0.17 \
		shared_child-0.3.2 \
		smallvec-0.6.1 \
		stable_deref_trait-1.0.0 \
		strsim-0.7.0 \
		syn-0.13.7 \
		syntect-2.1.0 \
		term_size-0.3.1 \
		termion-1.5.1 \
		termios-0.2.2 \
		textwrap-0.9.0 \
		thread_local-0.3.5 \
		time-0.1.39 \
		ucd-util-0.1.1 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.6 \
		unicode-width-0.1.4 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		url-1.7.0 \
		utf8-ranges-1.0.0 \
		vcpkg-0.2.3 \
		void-1.0.2 \
		walkdir-2.1.4 \
		winapi-0.2.8 \
		winapi-0.3.4 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xml-rs-0.7.0 \
		yaml-rust-0.4.0

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bat
.include <bsd.port.mk>
