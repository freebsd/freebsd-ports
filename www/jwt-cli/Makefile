# Created by: Sergey A. Osokin <osa@FreeBSD.org>

PORTNAME=	jwt-cli
PORTVERSION=	4.0.0
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Super fast CLI tool to decode and encode JWTs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=	cargo
USE_GITHUB=	yes
GH_ACCOUNT=	mike-engel

CARGO_CRATES=	aho-corasick-0.7.15 \
		ansi_term-0.11.0 \
		arrayref-0.3.6 \
		arrayvec-0.5.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.12.3 \
		base64-0.13.0 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.11 \
		bumpalo-3.6.0 \
		cc-1.0.66 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		constant_time_eq-0.1.5 \
		crossbeam-utils-0.8.1 \
		dirs-2.0.2 \
		dirs-sys-0.3.5 \
		getrandom-0.1.16 \
		hermit-abi-0.1.18 \
		itoa-0.4.7 \
		js-sys-0.3.47 \
		jsonwebtoken-7.2.0 \
		lazy_static-1.4.0 \
		libc-0.2.86 \
		log-0.4.14 \
		memchr-2.3.4 \
		num-0.2.1 \
		num-bigint-0.2.6 \
		num-complex-0.2.4 \
		num-integer-0.1.44 \
		num-iter-0.1.42 \
		num-rational-0.2.4 \
		num-traits-0.2.14 \
		once_cell-1.5.2 \
		parse_duration-2.1.0 \
		pem-0.8.2 \
		proc-macro2-1.0.24 \
		quote-1.0.9 \
		redox_syscall-0.1.57 \
		redox_users-0.3.5 \
		regex-1.4.3 \
		regex-syntax-0.6.22 \
		ring-0.16.20 \
		rust-argon2-0.8.3 \
		ryu-1.0.5 \
		serde-1.0.123 \
		serde_derive-1.0.123 \
		serde_json-1.0.62 \
		simple_asn1-0.4.1 \
		spin-0.5.2 \
		strsim-0.8.0 \
		syn-1.0.60 \
		term-0.6.1 \
		term-painter-0.3.0 \
		textwrap-0.11.0 \
		thread_local-1.1.3 \
		time-0.1.44 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		untrusted-0.7.1 \
		vec_map-0.8.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.70 \
		wasm-bindgen-backend-0.2.70 \
		wasm-bindgen-macro-0.2.70 \
		wasm-bindgen-macro-support-0.2.70 \
		wasm-bindgen-shared-0.2.70 \
		web-sys-0.3.47 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/jwt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jwt

.include <bsd.port.mk>
