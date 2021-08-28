# Created by: arved

PORTNAME=	newsboat
DISTVERSION=	2.24
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://newsboat.org/releases/${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mt-bugs@markoturk.info
COMMENT=	RSS feed reader for the text console

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjson-c.so:devel/json-c \
		libstfl.so:devel/stfl

USES=		cargo compiler:c++11-lang gettext gmake gnome iconv:translit \
		ncurses pkgconfig python:env shebangfix sqlite ssl tar:xz
USE_GNOME=	libxml2

SHEBANG_FILES=	contrib/bookmark-evernote.sh contrib/exportOPMLWithTags.py \
		contrib/feedgrabber.rb contrib/getpocket.com/send-to-pocket.sh \
		contrib/heise.rb contrib/image-preview/nbparser \
		contrib/slashdot.rb doc/examples/example-exec-script.py

CARGO_CRATES=	addr2line-0.14.1 \
		adler-1.0.2 \
		aho-corasick-0.7.15 \
		arrayvec-0.5.2 \
		autocfg-1.0.1 \
		backtrace-0.3.56 \
		bit-set-0.5.2 \
		bit-vec-0.6.3 \
		bitflags-1.2.1 \
		bitvec-0.19.5 \
		block-0.1.6 \
		byteorder-1.4.3 \
		cc-1.0.67 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		codespan-reporting-0.11.1 \
		curl-sys-0.4.44+curl-7.77.0 \
		cxx-1.0.49 \
		cxx-build-1.0.49 \
		cxxbridge-flags-1.0.49 \
		cxxbridge-macro-1.0.49 \
		fnv-1.0.7 \
		form_urlencoded-1.0.1 \
		funty-1.1.0 \
		getrandom-0.2.2 \
		gettext-rs-0.7.0 \
		gettext-sys-0.21.0 \
		gimli-0.23.0 \
		idna-0.2.2 \
		lazy_static-1.4.0 \
		lexical-core-0.7.5 \
		libc-0.2.97 \
		libz-sys-1.1.2 \
		link-cplusplus-1.0.5 \
		locale_config-0.3.0 \
		malloc_buf-0.0.6 \
		matches-0.1.8 \
		memchr-2.3.4 \
		miniz_oxide-0.4.4 \
		natord-1.0.9 \
		nom-6.1.2 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		objc-0.2.7 \
		objc-foundation-0.1.1 \
		objc_id-0.1.1 \
		object-0.23.0 \
		once_cell-1.8.0 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.19 \
		ppv-lite86-0.2.10 \
		proc-macro2-1.0.26 \
		proptest-1.0.0 \
		quick-error-1.2.3 \
		quick-error-2.0.0 \
		quote-1.0.9 \
		radium-0.5.3 \
		rand-0.8.4 \
		rand_chacha-0.3.0 \
		rand_core-0.6.2 \
		rand_hc-0.3.0 \
		rand_xorshift-0.3.0 \
		redox_syscall-0.2.5 \
		regex-1.4.5 \
		regex-syntax-0.6.23 \
		remove_dir_all-0.5.3 \
		rustc-demangle-0.1.18 \
		rusty-fork-0.3.0 \
		ryu-1.0.5 \
		scratch-1.0.0 \
		section_testing-0.0.5 \
		static_assertions-1.1.0 \
		syn-1.0.70 \
		tap-1.0.1 \
		tempfile-3.2.0 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		time-0.1.43 \
		tinyvec-1.1.1 \
		tinyvec_macros-0.1.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.17 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		url-2.2.2 \
		vcpkg-0.2.11 \
		version_check-0.9.3 \
		wait-timeout-0.2.0 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wyz-0.2.0 \
		xdg-2.2.0
CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TARGET_DIR=	${WRKSRC}/target

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
