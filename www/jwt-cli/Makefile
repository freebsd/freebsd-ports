# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jwt-cli
PORTVERSION=	2.5.2
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Super fast CLI tool to decode and encode JWTs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=	cargo
USE_GITHUB=	yes
GH_ACCOUNT=	mike-engel

CARGO_CRATES=	ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		base64-0.10.1 \
		bitflags-1.2.1 \
		byteorder-1.3.2 \
		cc-1.0.50 \
		chrono-0.4.10 \
		clap-2.33.0 \
		hermit-abi-0.1.6 \
		itoa-0.4.5 \
		jsonwebtoken-6.0.1 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.66 \
		num-integer-0.1.42 \
		num-traits-0.2.11 \
		proc-macro2-1.0.8 \
		quote-1.0.2 \
		redox_syscall-0.1.56 \
		ring-0.14.6 \
		ryu-1.0.2 \
		serde-1.0.104 \
		serde_derive-1.0.104 \
		serde_json-1.0.45 \
		spin-0.5.2 \
		strsim-0.8.0 \
		syn-1.0.14 \
		term-0.4.6 \
		term-painter-0.2.4 \
		textwrap-0.11.0 \
		time-0.1.42 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		untrusted-0.6.2 \
		vec_map-0.8.1 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/jwt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jwt

.include <bsd.port.mk>
