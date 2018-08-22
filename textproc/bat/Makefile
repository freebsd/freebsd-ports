# $FreeBSD$

PORTNAME=	bat
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	textproc

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Clone of cat with syntax highlighting

LICENSE=	APACHE20

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

PLIST_FILES=	bin/bat

CARGO_CRATES=	aho-corasick-0.6.6 \
		ansi_term-0.11.0 \
		atty-0.2.11 \
		base64-0.8.0 \
		bincode-1.0.1 \
		bitflags-1.0.3 \
		byteorder-1.2.4 \
		cc-1.0.18 \
		cfg-if-0.1.5 \
		chrono-0.4.5 \
		clap-2.32.0 \
		clicolors-control-0.2.0 \
		cmake-0.1.33 \
		console-0.6.1 \
		directories-1.0.1 \
		error-chain-0.12.0 \
		flate2-1.0.2 \
		fnv-1.0.6 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		git2-0.7.5 \
		idna-0.1.5 \
		itoa-0.4.2 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.11 \
		lazy_static-1.1.0 \
		libc-0.2.43 \
		libgit2-sys-0.7.7 \
		libz-sys-1.0.20 \
		linked-hash-map-0.5.1 \
		lock_api-0.1.3 \
		log-0.4.4 \
		matches-0.1.7 \
		memchr-2.0.1 \
		miniz-sys-0.1.10 \
		num-integer-0.1.39 \
		num-traits-0.2.5 \
		onig-3.2.2 \
		onig_sys-68.2.0 \
		owning_ref-0.3.3 \
		parking_lot-0.6.3 \
		parking_lot_core-0.2.14 \
		percent-encoding-1.0.1 \
		pkg-config-0.3.13 \
		plist-0.2.4 \
		proc-macro2-0.4.13 \
		quote-0.6.6 \
		rand-0.4.3 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		regex-0.2.11 \
		regex-syntax-0.4.2 \
		regex-syntax-0.5.6 \
		remove_dir_all-0.5.1 \
		ryu-0.2.4 \
		safemem-0.2.0 \
		same-file-1.0.2 \
		scopeguard-0.3.3 \
		serde-1.0.71 \
		serde_derive-1.0.71 \
		serde_json-1.0.26 \
		smallvec-0.6.4 \
		stable_deref_trait-1.1.1 \
		strsim-0.7.0 \
		syn-0.14.8 \
		syntect-2.1.0 \
		tempdir-0.3.7 \
		term_size-0.3.1 \
		termion-1.5.1 \
		termios-0.2.2 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		time-0.1.40 \
		ucd-util-0.1.1 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.7 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		url-1.7.1 \
		utf8-ranges-1.0.0 \
		vcpkg-0.2.5 \
		version_check-0.1.4 \
		void-1.0.2 \
		walkdir-2.2.0 \
		winapi-0.2.8 \
		winapi-0.3.5 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xml-rs-0.7.0 \
		yaml-rust-0.4.0

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bat
.include <bsd.port.mk>
