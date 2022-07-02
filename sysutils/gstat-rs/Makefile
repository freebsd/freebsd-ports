PORTNAME=	gstat-rs
DISTVERSIONPREFIX=	gstat-v
DISTVERSION=	0.1.2
PORTREVISION=	8
CATEGORIES=	sysutils

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Replacement for gstat(8)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	asomers
SUB_FILES=	pkg-message

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		approx-0.5.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bindgen-0.53.3 \
		bitfield-0.13.2 \
		bitflags-1.2.1 \
		cassowary-0.3.0 \
		cc-1.0.69 \
		cexpr-0.4.0 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clang-sys-0.29.3 \
		clap-2.33.3 \
		confy-0.4.0 \
		directories-2.0.2 \
		dirs-sys-0.3.6 \
		env_logger-0.7.1 \
		getrandom-0.2.3 \
		glob-0.3.0 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		humanize-rs-0.1.5 \
		humantime-1.3.0 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.98 \
		libloading-0.5.2 \
		log-0.4.14 \
		memchr-2.4.0 \
		memoffset-0.6.4 \
		nix-0.22.0 \
		nom-5.1.2 \
		nonzero_ext-0.2.0 \
		num-traits-0.2.14 \
		numtoa-0.1.0 \
		peeking_take_while-0.1.2 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.27 \
		quick-error-1.2.3 \
		quote-1.0.9 \
		redox_syscall-0.2.9 \
		redox_termios-0.1.2 \
		redox_users-0.4.0 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		rustc-hash-1.1.0 \
		serde-1.0.126 \
		serde_derive-1.0.126 \
		shlex-0.1.1 \
		strsim-0.8.0 \
		structopt-0.3.22 \
		structopt-derive-0.4.15 \
		syn-1.0.73 \
		term_size-0.3.2 \
		termcolor-1.1.2 \
		termion-1.5.6 \
		textwrap-0.11.0 \
		toml-0.5.8 \
		tui-0.15.0 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		which-3.1.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_INSTALL_PATH=	gstat
CARGO_CARGOTOML=	${WRKSRC}/gstat/Cargo.toml
CARGO_TEST_ARGS=	--all
CARGO_ENV+=	LLVM_CONFIG_PATH=${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT}

PLIST_FILES=	sbin/gstat-rs \
		share/man/man8/gstat-rs.8.gz

post-install:
	${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/gstat ${STAGEDIR}${PREFIX}/sbin/gstat-rs
	${RM} ${STAGEDIR}${PREFIX}/bin/gstat
	${INSTALL_MAN} ${WRKSRC}/gstat/doc/gstat.8 ${STAGEDIR}${MAN8PREFIX}/share/man/man8/gstat-rs.8

.include <bsd.port.mk>
