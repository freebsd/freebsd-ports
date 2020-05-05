# $FreeBSD$

PORTNAME=	zoxide
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
CATEGORIES=	sysutils

MAINTAINER=	andoriyu@gmail.com
COMMENT=	Fast cd alternative that learns your habits

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ajeetdsouza

CARGO_CRATES=	ansi_term-0.11.0 \
		anyhow-1.0.28 \
		arrayref-0.3.6 \
		arrayvec-0.5.1 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		base64-0.11.0 \
		bincode-1.2.1 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.10 \
		bstr-0.2.12 \
		byteorder-1.3.4 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		constant_time_eq-0.1.5 \
		crossbeam-utils-0.7.2 \
		dirs-2.0.2 \
		dirs-sys-0.3.4 \
		getrandom-0.1.14 \
		heck-0.3.1 \
		hermit-abi-0.1.10 \
		lazy_static-1.4.0 \
		libc-0.2.68 \
		memchr-2.3.3 \
		ppv-lite86-0.2.6 \
		proc-macro-error-0.4.12 \
		proc-macro-error-attr-0.4.12 \
		proc-macro2-1.0.10 \
		quote-1.0.3 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.56 \
		redox_users-0.3.4 \
		regex-automata-0.1.9 \
		rust-argon2-0.7.0 \
		serde-1.0.105 \
		serde_derive-1.0.105 \
		strsim-0.8.0 \
		structopt-0.3.12 \
		structopt-derive-0.4.5 \
		syn-1.0.17 \
		syn-mid-0.5.0 \
		textwrap-0.11.0 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		uuid-0.8.1 \
		vec_map-0.8.1 \
		version_check-0.9.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/zoxide

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/zoxide

.include <bsd.port.mk>
