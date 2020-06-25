# Created by: arved
# $FreeBSD$

PORTNAME=	newsboat
PORTVERSION=	2.20.1
CATEGORIES=	www
MASTER_SITES=	https://newsboat.org/releases/${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mt@markoturk.info
COMMENT=	RSS feed reader for the text console

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
LIB_DEPENDS=	libstfl.so:devel/stfl \
		libcurl.so:ftp/curl \
		libjson-c.so:devel/json-c

USES=		cargo compiler:c++11-lang gettext gmake gnome iconv:translit \
		ncurses pkgconfig python:env shebangfix sqlite ssl tar:xz
USE_GNOME=	libxml2

SHEBANG_FILES=	contrib/bookmark-evernote.sh contrib/feedgrabber.rb \
		contrib/getpocket.com/send-to-pocket.sh contrib/heise.rb \
		contrib/slashdot.rb doc/examples/example-exec-script.py

MAKE_ARGS=	CARGO=${CARGO_CARGO_BIN} prefix=${PREFIX}
MAKE_ENV=	${CARGO_ENV}

CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TARGET_DIR=	${WRKSRC}/target
CARGO_CRATES=	aho-corasick-0.6.9 \
		arrayref-0.3.6 \
		arrayvec-0.4.10 \
		arrayvec-0.5.1 \
		autocfg-0.1.2 \
		autocfg-1.0.0 \
		backtrace-0.3.13 \
		backtrace-sys-0.1.28 \
		base64-0.11.0 \
		bit-set-0.5.1 \
		bit-vec-0.5.1 \
		bitflags-1.0.4 \
		blake2b_simd-0.5.10 \
		byteorder-1.3.4 \
		cc-1.0.29 \
		cfg-if-0.1.6 \
		chrono-0.4.6 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.5 \
		crossbeam-utils-0.7.2 \
		curl-sys-0.4.5 \
		dirs-2.0.2 \
		dirs-sys-0.3.4 \
		fnv-1.0.6 \
		fuchsia-cprng-0.1.1 \
		getrandom-0.1.14 \
		gettext-rs-0.4.1 \
		gettext-sys-0.19.8 \
		idna-0.2.0 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.11 \
		lazy_static-1.2.0 \
		lexical-core-0.6.2 \
		libc-0.2.69 \
		libz-sys-1.0.17 \
		locale_config-0.2.2 \
		matches-0.1.8 \
		memchr-2.1.3 \
		natord-1.0.9 \
		nodrop-0.1.13 \
		nom-5.1.1 \
		num-integer-0.1.39 \
		num-traits-0.2.6 \
		once_cell-1.3.1 \
		openssl-sys-0.9.53 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.14 \
		proptest-0.9.6 \
		quick-error-1.2.2 \
		rand-0.6.5 \
		rand_chacha-0.1.1 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.3 \
		rand_os-0.1.2 \
		rand_pcg-0.1.1 \
		rand_xorshift-0.1.1 \
		rdrand-0.4.0 \
		redox_syscall-0.1.51 \
		redox_users-0.3.4 \
		regex-0.2.11 \
		regex-syntax-0.5.6 \
		regex-syntax-0.6.5 \
		remove_dir_all-0.5.1 \
		rust-argon2-0.7.0 \
		rustc-demangle-0.1.13 \
		rustc_version-0.2.3 \
		rusty-fork-0.2.1 \
		ryu-1.0.3 \
		section_testing-0.0.4 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		smallvec-0.6.10 \
		static_assertions-0.3.4 \
		tempfile-3.0.6 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		time-0.1.42 \
		ucd-util-0.1.3 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.8 \
		unicode-width-0.1.5 \
		url-2.1.1 \
		utf8-ranges-1.0.2 \
		vcpkg-0.2.6 \
		version_check-0.9.1 \
		wait-timeout-0.1.5 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.2.8 \
		winapi-0.3.6 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xdg-2.2.0

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,fail "ncursesw",true,; s,fail "libcrypto",true,' \
		-e 's,fail "libssl",true,' \
		${WRKSRC}/config.sh
	@${REINPLACE_CMD} -e 's|-liconv|${ICONV_LIB} -lcrypto -l${NCURSES_IMPL}|;s|-Werror||' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*boat

.include <bsd.port.mk>
