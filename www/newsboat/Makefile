# Created by: arved

PORTNAME=	newsboat
DISTVERSION=	2.27
PORTREVISION=	3
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

CARGO_CRATES=	addr2line-0.17.0 \
		adler-1.0.2 \
		aho-corasick-0.7.18 \
		autocfg-1.0.1 \
		backtrace-0.3.63 \
		bit-set-0.5.2 \
		bit-vec-0.6.3 \
		bitflags-1.3.2 \
		block-0.1.6 \
		byteorder-1.4.3 \
		cc-1.0.72 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		codespan-reporting-0.11.1 \
		curl-sys-0.4.52+curl-7.81.0 \
		cxx-1.0.65 \
		cxx-build-1.0.65 \
		cxxbridge-flags-1.0.65 \
		cxxbridge-macro-1.0.65 \
		dirs-4.0.0 \
		dirs-sys-0.3.6 \
		fastrand-1.7.0 \
		fnv-1.0.7 \
		form_urlencoded-1.0.1 \
		getrandom-0.2.3 \
		gettext-rs-0.7.0 \
		gettext-sys-0.21.2 \
		gimli-0.26.1 \
		idna-0.2.3 \
		instant-0.1.12 \
		lazy_static-1.4.0 \
		lexopt-0.2.0 \
		libc-0.2.119 \
		libz-sys-1.1.3 \
		link-cplusplus-1.0.6 \
		locale_config-0.3.0 \
		malloc_buf-0.0.6 \
		matches-0.1.9 \
		md5-0.7.0 \
		memchr-2.4.1 \
		minimal-lexical-0.2.1 \
		miniz_oxide-0.4.4 \
		natord-1.0.9 \
		nom-7.1.0 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		objc-0.2.7 \
		objc-foundation-0.1.1 \
		objc_id-0.1.1 \
		object-0.27.1 \
		once_cell-1.10.0 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.24 \
		ppv-lite86-0.2.15 \
		proc-macro2-1.0.35 \
		proptest-1.0.0 \
		quick-error-1.2.3 \
		quick-error-2.0.1 \
		quote-1.0.10 \
		rand-0.8.4 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rand_xorshift-0.3.0 \
		redox_syscall-0.2.10 \
		redox_users-0.4.0 \
		regex-1.5.5 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		rustc-demangle-0.1.21 \
		rusty-fork-0.3.0 \
		scratch-1.0.1 \
		section_testing-0.0.5 \
		syn-1.0.84 \
		temp-dir-0.1.11 \
		tempfile-3.3.0 \
		termcolor-1.1.2 \
		time-0.1.43 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		unicode-bidi-0.3.7 \
		unicode-normalization-0.1.19 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		url-2.2.2 \
		vcpkg-0.2.15 \
		version_check-0.9.3 \
		wait-timeout-0.2.0 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xdg-2.4.1
CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TARGET_DIR=	${WRKSRC}/target

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,fail "ncursesw",true,; s,fail "libcrypto",true,' \
		-e 's,fail "libssl",true,' \
		${WRKSRC}/config.sh
	@${REINPLACE_CMD} -e 's|-liconv|${ICONV_LIB} -lcrypto ${NCURSESLIBS}|;s|-Werror||' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*boat

.include <bsd.port.mk>
