# Created by: arved
# $FreeBSD$

PORTNAME=	newsboat
PORTVERSION=	2.21
PORTREVISION=	2
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
CARGO_CRATES=	addr2line-0.12.2 \
		adler32-1.1.0 \
		aho-corasick-0.7.13 \
		arrayvec-0.5.1 \
		autocfg-1.0.0 \
		backtrace-0.3.49 \
		bit-set-0.5.2 \
		bit-vec-0.6.2 \
		bitflags-1.2.1 \
		block-0.1.6 \
		byteorder-1.3.4 \
		cc-1.0.57 \
		cfg-if-0.1.10 \
		chrono-0.4.15 \
		clap-2.33.3 \
		curl-sys-0.4.36+curl-7.71.1 \
		fnv-1.0.7 \
		getrandom-0.1.14 \
		gettext-rs-0.5.0 \
		gettext-sys-0.19.9 \
		gimli-0.21.0 \
		idna-0.2.0 \
		lazy_static-1.4.0 \
		lexical-core-0.7.4 \
		libc-0.2.77 \
		libz-sys-1.1.0 \
		locale_config-0.3.0 \
		malloc_buf-0.0.6 \
		matches-0.1.8 \
		memchr-2.3.3 \
		miniz_oxide-0.3.7 \
		natord-1.0.9 \
		nom-5.1.2 \
		num-integer-0.1.43 \
		num-traits-0.2.12 \
		objc-0.2.7 \
		objc-foundation-0.1.1 \
		objc_id-0.1.1 \
		object-0.20.0 \
		once_cell-1.4.1 \
		openssl-sys-0.9.58 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.17 \
		ppv-lite86-0.2.8 \
		proptest-0.10.1 \
		quick-error-1.2.3 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_xorshift-0.2.0 \
		redox_syscall-0.1.56 \
		regex-1.3.9 \
		regex-syntax-0.6.18 \
		remove_dir_all-0.5.3 \
		rustc-demangle-0.1.16 \
		rusty-fork-0.3.0 \
		ryu-1.0.5 \
		section_testing-0.0.4 \
		static_assertions-1.1.0 \
		tempfile-3.1.0 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		time-0.1.43 \
		tinyvec-0.3.3 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.13 \
		unicode-width-0.1.8 \
		url-2.1.1 \
		vcpkg-0.2.10 \
		version_check-0.9.2 \
		wait-timeout-0.2.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
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
