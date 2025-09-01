PORTNAME=	rsyn
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.1
PORTREVISION=	16
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wire-compatible rsync client in Rust
WWW=		https://github.com/sourcefrog/rsyn

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	sourcefrog

CARGO_CRATES=	aho-corasick-0.7.10 \
		ansi_term-0.11.0 \
		anyhow-1.0.30 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		bitflags-1.2.1 \
		cfg-if-0.1.10 \
		chrono-0.4.11 \
		clap-2.33.1 \
		fern-0.6.0 \
		fuchsia-cprng-0.1.1 \
		heck-0.3.1 \
		hermit-abi-0.1.12 \
		hex-0.4.2 \
		lazy_static-1.4.0 \
		libc-0.2.70 \
		log-0.4.8 \
		memchr-2.3.3 \
		num-integer-0.1.42 \
		num-traits-0.2.11 \
		proc-macro-error-1.0.2 \
		proc-macro-error-attr-1.0.2 \
		proc-macro2-1.0.12 \
		quote-1.0.5 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rdrand-0.4.0 \
		regex-1.3.7 \
		regex-syntax-0.6.17 \
		remove_dir_all-0.5.2 \
		shell-words-1.0.0 \
		strsim-0.8.0 \
		structopt-0.3.14 \
		structopt-derive-0.4.7 \
		syn-1.0.21 \
		syn-mid-0.5.0 \
		tempdir-0.3.7 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		time-0.1.43 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		unix_mode-0.1.1 \
		vec_map-0.8.2 \
		version_check-0.9.1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
