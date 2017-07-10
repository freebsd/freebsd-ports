# $FreeBSD$

PORTNAME=	geckodriver
PORTVERSION=	0.17.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	daniel@blodan.se
COMMENT=	Proxy for using WebDriver clients with Gecko-based browsers

LICENSE=	MPL

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	mozilla

PLIST_FILES=	bin/geckodriver

CARGO_CRATES=	advapi32-sys-0.1.2 \
		aho-corasick-0.6.2 \
		backtrace-0.3.2 \
		backtrace-sys-0.1.10 \
		base64-0.5.2 \
		bitflags-0.8.2 \
		byteorder-1.0.0 \
		bzip2-0.3.2 \
		bzip2-sys-0.1.5 \
		cfg-if-0.1.0 \
		chrono-0.2.25 \
		clap-2.24.2 \
		cookie-0.6.2 \
		crossbeam-0.2.10 \
		dbghelp-sys-0.2.0 \
		flate2-0.2.19 \
		gcc-0.3.42 \
		httparse-1.2.2 \
		hyper-0.10.10 \
		idna-0.1.2 \
		isatty-0.1.3 \
		kernel32-sys-0.1.4 \
		kernel32-sys-0.2.2 \
		ktmw32-sys-0.1.0 \
		language-tags-0.2.2 \
		lazy_static-0.1.16 \
		lazy_static-0.2.2 \
		libc-0.2.20 \
		log-0.3.6 \
		matches-0.1.4 \
		memchr-1.0.1 \
		mime-0.2.4 \
		miniz-sys-0.1.9 \
		mozprofile-0.3.0 \
		mozrunner-0.4.0 \
		mozversion-0.1.2 \
		msdos_time-0.1.5 \
		num-0.1.37 \
		num-integer-0.1.33 \
		num-iter-0.1.33 \
		num-traits-0.1.37 \
		num_cpus-1.2.1 \
		podio-0.1.5 \
		rand-0.3.15 \
		redox_syscall-0.1.16 \
		regex-0.2.1 \
		regex-syntax-0.4.0 \
		rust-ini-0.10.0 \
		rustc-demangle-0.1.4 \
		rustc-serialize-0.3.22 \
		rustc_version-0.1.7 \
		semver-0.1.20 \
		semver-0.6.0 \
		semver-parser-0.7.0 \
		slog-1.5.2 \
		slog-atomic-0.4.3 \
		slog-extra-0.1.2 \
		slog-stdlog-1.1.0 \
		slog-stream-1.2.1 \
		slog-term-1.5.0 \
		strsim-0.6.0 \
		tempdir-0.3.5 \
		term_size-0.3.0 \
		thread-id-3.0.0 \
		thread_local-0.3.3 \
		time-0.1.36 \
		traitobject-0.1.0 \
		typeable-0.1.2 \
		unicase-1.4.0 \
		unicode-bidi-0.3.3 \
		unicode-normalization-0.1.4 \
		unicode-segmentation-1.1.0 \
		unicode-width-0.1.4 \
		unreachable-0.1.1 \
		url-1.4.1 \
		utf8-ranges-1.0.0 \
		uuid-0.1.18 \
		vec_map-0.8.0 \
		void-1.0.2 \
		webdriver-0.26.0 \
		winapi-0.2.8 \
		winapi-build-0.1.1 \
		winreg-0.3.5 \
		zip-0.1.19

.include <bsd.port.mk>
