PORTNAME=	mcfly
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fly through your shell history

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	cantino

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.12.1 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.34.0 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		directories-next-2.0.0 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		either-1.6.1 \
		getrandom-0.1.16 \
		getrandom-0.2.5 \
		hermit-abi-0.1.19 \
		humantime-2.1.0 \
		itertools-0.9.0 \
		itoa-0.4.8 \
		lazy_static-1.4.0 \
		libc-0.2.120 \
		libsqlite3-sys-0.10.0 \
		linked-hash-map-0.5.4 \
		lru-cache-0.1.2 \
		memchr-2.4.1 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		numtoa-0.1.0 \
		pkg-config-0.3.24 \
		ppv-lite86-0.2.16 \
		proc-macro2-1.0.36 \
		quote-1.0.15 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.2.11 \
		redox_termios-0.1.2 \
		redox_users-0.4.2 \
		regex-1.5.5 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		relative-path-1.6.1 \
		rusqlite-0.15.0 \
		ryu-1.0.9 \
		serde-1.0.136 \
		shellexpand-2.1.0 \
		strsim-0.8.0 \
		syn-1.0.89 \
		termion-1.5.6 \
		textwrap-0.11.0 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		time-0.1.44 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		vcpkg-0.2.15 \
		vec_map-0.8.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/${PORTNAME}.bash \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

post-install: # install shell completion files
	# strip
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mcfly
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
