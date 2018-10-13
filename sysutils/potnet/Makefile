# $FreeBSD$

PORTNAME=	potnet
DISTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Utility to help sysutils/pot to manage the internal network

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	cargo

USE_GITHUB=	yes
GH_ACCOUNT=	pizzamig

PLIST_FILES=	bin/potnet

CARGO_CRATES=	aho-corasick-0.6.5 \
		atty-0.2.10 \
		bitflags-1.0.3 \
		cfg-if-0.1.4 \
		clap-2.32.0 \
		env_logger-0.5.10 \
		humantime-1.1.1 \
		lazy_static-1.0.1 \
		libc-0.2.42 \
		log-0.4.2 \
		memchr-2.0.1 \
		proc-macro2-0.4.6 \
		quick-error-1.2.2 \
		quote-0.6.3 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		regex-1.0.1 \
		regex-syntax-0.6.1 \
		same-file-1.0.2 \
		structopt-0.2.10 \
		structopt-derive-0.2.10 \
		syn-0.14.2 \
		termcolor-0.3.6 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.5 \
		ucd-util-0.1.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		utf8-ranges-1.0.0 \
		void-1.0.2 \
		walkdir-2.1.4 \
		winapi-0.3.5 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-0.1.6

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/potnet
.include <bsd.port.mk>
