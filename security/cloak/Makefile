# $FreeBSD$

PORTNAME=	cloak
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	8
CATEGORIES=	security

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Command line OTP Authenticator application

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	evansmurithi

CARGO_CRATES=	ansi_term-0.11.0 \
		argon2rs-0.2.5 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		backtrace-0.3.15 \
		backtrace-sys-0.1.28 \
		bitflags-1.0.4 \
		blake2-rfc-0.2.18 \
		cc-1.0.35 \
		cfg-if-0.1.7 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.3 \
		data-encoding-2.1.2 \
		dirs-1.0.5 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fuchsia-cprng-0.1.1 \
		lazy_static-1.3.0 \
		libc-0.2.51 \
		nodrop-0.1.13 \
		numtoa-0.1.0 \
		open-1.2.2 \
		proc-macro2-0.4.28 \
		quote-0.6.12 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_os-0.1.3 \
		rdrand-0.4.0 \
		redox_syscall-0.1.54 \
		redox_termios-0.1.1 \
		redox_users-0.3.0 \
		ring-0.14.6 \
		rustc-demangle-0.1.14 \
		scoped_threadpool-0.1.9 \
		serde-1.0.90 \
		serde_derive-1.0.90 \
		spin-0.5.0 \
		strsim-0.8.0 \
		syn-0.15.32 \
		synstructure-0.10.1 \
		termion-1.5.2 \
		textwrap-0.11.0 \
		toml-0.5.0 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		untrusted-0.6.2 \
		vec_map-0.8.1 \
		winapi-0.3.7 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/cloak

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cloak

.include <bsd.port.mk>
