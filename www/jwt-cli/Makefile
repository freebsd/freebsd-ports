# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jwt-cli
PORTVERSION=	2.5.0
CATEGORIES=	www

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Super fast CLI tool to decode and encode JWTs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=	cargo
USE_GITHUB=	yes
GH_ACCOUNT=	mike-engel

CARGO_CRATES=	ansi_term-0.11.0 \
		atty-0.2.11 \
		autocfg-0.1.4 \
		base64-0.10.1 \
		bitflags-1.0.4 \
		byteorder-1.3.1 \
		cc-1.0.37 \
		chrono-0.4.6 \
		clap-2.33.0 \
		itoa-0.4.4 \
		jsonwebtoken-6.0.1 \
		kernel32-sys-0.2.2 \
		lazy_static-1.3.0 \
		libc-0.2.55 \
		num-integer-0.1.41 \
		num-traits-0.2.8 \
		numtoa-0.1.0 \
		proc-macro2-0.4.30 \
		quote-0.6.12 \
		redox_syscall-0.1.54 \
		redox_termios-0.1.1 \
		ring-0.14.6 \
		ryu-0.2.8 \
		serde-1.0.91 \
		serde_derive-1.0.91 \
		serde_json-1.0.39 \
		spin-0.5.0 \
		strsim-0.8.0 \
		syn-0.15.34 \
		term-0.4.6 \
		term-painter-0.2.4 \
		termion-1.5.2 \
		textwrap-0.11.0 \
		time-0.1.42 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		untrusted-0.6.2 \
		vec_map-0.8.1 \
		winapi-0.2.8 \
		winapi-0.3.7 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/jwt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jwt

.include <bsd.port.mk>
