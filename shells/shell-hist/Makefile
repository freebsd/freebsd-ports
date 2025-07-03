PORTNAME=	shell-hist
DISTVERSION=	g20190515
PORTREVISION=	23
CATEGORIES=	shells

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Inspect your shell history
WWW=		https://github.com/jamesmunns/shell-hist

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	jamesmunns
GH_TAGNAME=	b2f1c3f

CARGO_CRATES=	aho-corasick-0.7.3 \
		ansi_term-0.11.0 \
		argon2rs-0.2.5 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		backtrace-0.3.15 \
		backtrace-sys-0.1.28 \
		bitflags-1.0.4 \
		blake2-rfc-0.2.18 \
		cc-1.0.36 \
		cfg-if-0.1.7 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.3 \
		dirs-1.0.5 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fuchsia-cprng-0.1.1 \
		heck-0.3.1 \
		lazy_static-1.3.0 \
		libc-0.2.54 \
		memchr-2.2.0 \
		nodrop-0.1.13 \
		numtoa-0.1.0 \
		proc-macro2-0.4.30 \
		quote-0.6.12 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_os-0.1.3 \
		rdrand-0.4.0 \
		redox_syscall-0.1.54 \
		redox_termios-0.1.1 \
		redox_users-0.3.0 \
		regex-1.1.6 \
		regex-syntax-0.6.6 \
		rustc-demangle-0.1.14 \
		scoped_threadpool-0.1.9 \
		strsim-0.8.0 \
		structopt-0.2.15 \
		structopt-derive-0.2.15 \
		syn-0.15.34 \
		synstructure-0.10.1 \
		termion-1.5.2 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		ucd-util-0.1.3 \
		unicode-segmentation-1.2.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.2 \
		vec_map-0.8.1 \
		winapi-0.3.7 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
