# Created by: arved
# $FreeBSD$

PORTNAME=	newsboat
PORTVERSION=	2.14
CATEGORIES=	www
MASTER_SITES=	https://newsboat.org/releases/${PORTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mt@markoturk.info
COMMENT=	RSS feed reader for the text console

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libstfl.so:devel/stfl \
		libcurl.so:ftp/curl \
		libjson-c.so:devel/json-c

USES=		cargo compiler:c++11-lib gettext gmake gnome iconv:translit ncurses \
		pkgconfig sqlite shebangfix ssl tar:xz
USE_CXXSTD=	gnu++11
USE_GNOME=	libxml2

MAKE_ARGS=	CARGO=${CARGO_CARGO_BIN} mandir=${PREFIX}/man prefix=${PREFIX}
MAKE_ENV=	${CARGO_ENV}

CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TARGET_DIR=	${WRKSRC}/target
CARGO_CRATES=	aho-corasick-0.6.9 \
		argon2rs-0.2.5 \
		arrayvec-0.4.9 \
		autocfg-0.1.1 \
		backtrace-0.3.13 \
		backtrace-sys-0.1.26 \
		bitflags-1.0.4 \
		blake2-rfc-0.2.18 \
		cc-1.0.26 \
		cfg-if-0.1.6 \
		chrono-0.4.6 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.3 \
		dirs-1.0.4 \
		failure-0.1.3 \
		failure_derive-0.1.3 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		idna-0.1.5 \
		lazy_static-1.2.0 \
		libc-0.2.45 \
		lock_api-0.1.5 \
		matches-0.1.8 \
		memchr-2.1.2 \
		nodrop-0.1.13 \
		num-integer-0.1.39 \
		num-traits-0.2.6 \
		once_cell-0.1.6 \
		parking_lot-0.6.4 \
		parking_lot_core-0.3.1 \
		percent-encoding-1.0.1 \
		proc-macro2-0.4.24 \
		quote-0.6.10 \
		rand-0.4.3 \
		rand-0.5.5 \
		rand-0.6.1 \
		rand_chacha-0.1.0 \
		rand_core-0.2.2 \
		rand_core-0.3.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.1 \
		rand_pcg-0.1.1 \
		rand_xorshift-0.1.0 \
		redox_syscall-0.1.44 \
		redox_users-0.2.0 \
		regex-1.1.0 \
		regex-syntax-0.6.4 \
		remove_dir_all-0.5.1 \
		rustc-demangle-0.1.11 \
		rustc_version-0.2.3 \
		scoped_threadpool-0.1.9 \
		scopeguard-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		smallvec-0.6.7 \
		syn-0.15.23 \
		synstructure-0.10.1 \
		tempfile-3.0.5 \
		thread_local-0.3.6 \
		time-0.1.41 \
		ucd-util-0.1.3 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.7 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		url-1.7.2 \
		utf8-ranges-1.0.2 \
		version_check-0.1.5 \
		void-1.0.2 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's,fail "ncursesw",true,; s,fail "libcrypto",true,' \
		${WRKSRC}/config.sh
	${REINPLACE_CMD} -e 's|-liconv|${ICONV_LIB} -lcrypto -lncursesw|;s|-Werror||' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*boat

.include <bsd.port.mk>
