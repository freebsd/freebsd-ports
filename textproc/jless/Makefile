PORTNAME=	jless
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.2
PORTREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Command-line JSON viewer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	PaulJuliusMartinez

CARGO_CRATES=	aho-corasick-0.7.18 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		beef-0.5.1 \
		bitflags-1.2.1 \
		cc-1.0.69 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clap-3.0.14 \
		clap_derive-3.0.14 \
		clipboard-win-4.2.1 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		endian-type-0.1.2 \
		error-code-2.3.0 \
		fd-lock-3.0.0 \
		fnv-1.0.7 \
		getrandom-0.2.3 \
		hashbrown-0.11.2 \
		heck-0.4.0 \
		hermit-abi-0.1.18 \
		indexmap-1.8.0 \
		isatty-0.1.9 \
		lazy_static-1.4.0 \
		libc-0.2.99 \
		libc-stdhandle-0.1.0 \
		log-0.4.14 \
		logos-0.12.0 \
		logos-derive-0.12.0 \
		memchr-2.4.1 \
		memoffset-0.6.4 \
		nibble_vec-0.1.0 \
		nix-0.22.1 \
		numtoa-0.1.0 \
		os_str_bytes-6.0.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.36 \
		quote-1.0.9 \
		radix_trie-0.2.1 \
		redox_syscall-0.1.57 \
		redox_syscall-0.2.6 \
		redox_termios-0.1.2 \
		redox_users-0.4.0 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		rustyline-9.0.0 \
		scopeguard-1.1.0 \
		signal-hook-0.3.8 \
		signal-hook-registry-1.3.0 \
		smallvec-1.6.1 \
		str-buf-1.0.5 \
		strsim-0.10.0 \
		syn-1.0.86 \
		termcolor-1.1.2 \
		termion-1.5.6 \
		textwrap-0.14.2 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		utf8-ranges-1.0.4 \
		utf8parse-0.2.0 \
		version_check-0.9.3 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/jless

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jless

.include <bsd.port.mk>
