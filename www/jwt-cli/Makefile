# Created by: Sergey A. Osokin <osa@FreeBSD.org>

PORTNAME=	jwt-cli
PORTVERSION=	5.0.0
CATEGORIES=	www

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Super fast CLI tool to decode and encode JWTs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=	cargo
USE_GITHUB=	yes
GH_ACCOUNT=	mike-engel

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.12.3 \
		base64-0.13.0 \
		bitflags-1.3.2 \
		bumpalo-3.8.0 \
		bunt-0.2.6 \
		bunt-macros-0.2.5 \
		cc-1.0.72 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		hermit-abi-0.1.19 \
		itoa-0.4.8 \
		js-sys-0.3.55 \
		jsonwebtoken-7.2.0 \
		lazy_static-1.4.0 \
		libc-0.2.107 \
		litrs-0.2.3 \
		log-0.4.14 \
		memchr-2.4.1 \
		num-0.2.1 \
		num-bigint-0.2.6 \
		num-complex-0.2.4 \
		num-integer-0.1.44 \
		num-iter-0.1.42 \
		num-rational-0.2.4 \
		num-traits-0.2.14 \
		once_cell-1.8.0 \
		parse_duration-2.1.1 \
		pem-0.8.3 \
		proc-macro2-1.0.32 \
		quote-1.0.10 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		ring-0.16.20 \
		ryu-1.0.5 \
		serde-1.0.130 \
		serde_derive-1.0.130 \
		serde_json-1.0.70 \
		simple_asn1-0.4.1 \
		spin-0.5.2 \
		strsim-0.8.0 \
		syn-1.0.81 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		time-0.1.44 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		untrusted-0.7.1 \
		vec_map-0.8.2 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.78 \
		wasm-bindgen-backend-0.2.78 \
		wasm-bindgen-macro-0.2.78 \
		wasm-bindgen-macro-support-0.2.78 \
		wasm-bindgen-shared-0.2.78 \
		web-sys-0.3.55 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/jwt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jwt

.include <bsd.port.mk>
