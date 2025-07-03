PORTNAME=	async
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
PORTREVISION=	23
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool to parallelize shell commands
WWW=		https://github.com/ctbur/async

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	ctbur

CARGO_CRATES=	aho-corasick-0.7.3 \
		ansi_term-0.11.0 \
		atty-0.2.11 \
		autocfg-0.1.4 \
		bincode-1.1.4 \
		bitflags-1.1.0 \
		byteorder-1.3.2 \
		cfg-if-0.1.9 \
		clap-2.33.0 \
		env_logger-0.6.1 \
		heck-0.3.1 \
		humantime-1.2.0 \
		lazy_static-1.3.0 \
		libc-0.2.58 \
		log-0.4.6 \
		memchr-2.2.0 \
		num_cpus-1.10.1 \
		numtoa-0.1.0 \
		proc-macro2-0.4.30 \
		quick-error-1.2.2 \
		quote-0.6.12 \
		redox_syscall-0.1.54 \
		redox_termios-0.1.1 \
		regex-1.1.7 \
		regex-syntax-0.6.7 \
		serde-1.0.92 \
		serde_derive-1.0.92 \
		strsim-0.8.0 \
		structopt-0.2.16 \
		structopt-derive-0.2.16 \
		syn-0.15.36 \
		termcolor-1.0.5 \
		termion-1.5.3 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		threadpool-1.7.1 \
		ucd-util-0.1.3 \
		unicode-segmentation-1.3.0 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.3 \
		vec_map-0.8.1 \
		winapi-0.3.7 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
