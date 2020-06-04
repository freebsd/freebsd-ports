# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jwt-cli
PORTVERSION=	3.1.0
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Super fast CLI tool to decode and encode JWTs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=	cargo
USE_GITHUB=	yes
GH_ACCOUNT=	mike-engel

CARGO_CRATES=	aho-corasick-0.7.10 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		base64-0.11.0 \
		bitflags-1.2.1 \
		bumpalo-3.2.0 \
		cc-1.0.50 \
		cfg-if-0.1.10 \
		chrono-0.4.11 \
		clap-2.33.0 \
		hermit-abi-0.1.8 \
		itoa-0.4.5 \
		js-sys-0.3.36 \
		jsonwebtoken-7.1.0 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.67 \
		log-0.4.8 \
		memchr-2.3.3 \
		num-0.2.1 \
		num-bigint-0.2.6 \
		num-complex-0.2.4 \
		num-integer-0.1.42 \
		num-iter-0.1.40 \
		num-rational-0.2.4 \
		num-traits-0.2.11 \
		parse_duration-2.1.0 \
		pem-0.7.0 \
		proc-macro2-1.0.9 \
		quote-1.0.3 \
		redox_syscall-0.1.56 \
		regex-1.3.5 \
		regex-syntax-0.6.17 \
		ring-0.16.11 \
		ryu-1.0.3 \
		serde-1.0.106 \
		serde_derive-1.0.106 \
		serde_json-1.0.51 \
		simple_asn1-0.4.0 \
		spin-0.5.2 \
		strsim-0.8.0 \
		syn-1.0.16 \
		term-0.4.6 \
		term-painter-0.2.4 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		time-0.1.42 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		untrusted-0.7.0 \
		vec_map-0.8.1 \
		wasm-bindgen-0.2.59 \
		wasm-bindgen-backend-0.2.59 \
		wasm-bindgen-macro-0.2.59 \
		wasm-bindgen-macro-support-0.2.59 \
		wasm-bindgen-shared-0.2.59 \
		web-sys-0.3.36 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/jwt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jwt

.include <bsd.port.mk>
