# $FreeBSD$

PORTNAME=	mcfly
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.5
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fly through your shell history

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	cantino

CARGO_CRATES=	aho-corasick-0.7.10 \
		ansi_term-0.11.0 \
		arrayref-0.3.6 \
		arrayvec-0.5.1 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		base64-0.11.0 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.10 \
		bstr-0.2.12 \
		byteorder-1.3.4 \
		cc-1.0.52 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		constant_time_eq-0.1.5 \
		crossbeam-utils-0.7.2 \
		csv-1.1.3 \
		csv-core-0.1.10 \
		dirs-2.0.2 \
		dirs-sys-0.3.4 \
		either-1.6.1 \
		getrandom-0.1.14 \
		hermit-abi-0.1.12 \
		itertools-0.9.0 \
		itoa-0.4.5 \
		lazy_static-1.4.0 \
		libc-0.2.69 \
		libsqlite3-sys-0.10.0 \
		linked-hash-map-0.5.3 \
		lru-cache-0.1.2 \
		memchr-2.3.3 \
		numtoa-0.1.0 \
		pkg-config-0.3.17 \
		ppv-lite86-0.2.6 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.56 \
		redox_termios-0.1.1 \
		redox_users-0.3.4 \
		regex-1.3.7 \
		regex-automata-0.1.9 \
		regex-syntax-0.6.17 \
		relative-path-1.0.0 \
		rusqlite-0.15.0 \
		rust-argon2-0.7.0 \
		ryu-1.0.4 \
		serde-1.0.106 \
		shellexpand-2.0.0 \
		strsim-0.8.0 \
		termion-1.5.5 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		time-0.1.43 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		vcpkg-0.2.8 \
		vec_map-0.8.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/${PORTNAME}.bash \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

post-install: # install shell completion files
	# bash
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	# fish
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.fish ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	# zsh
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.zsh ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
