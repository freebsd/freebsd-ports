# Created by: Andrey Cherkashin <andoriyu@gmail.com>

PORTNAME=	fd
DISTVERSIONPREFIX=	v
DISTVERSION=	8.3.2
PORTREVISION=	2
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-find

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Simple, fast and user-friendly alternative to find

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.12.1 \
		anyhow-1.0.52 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		cc-1.0.72 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-3.0.5 \
		clap_complete-3.0.2 \
		crossbeam-utils-0.8.5 \
		ctrlc-3.2.1 \
		diff-0.1.12 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		filetime-0.2.15 \
		fnv-1.0.7 \
		fs_extra-1.2.0 \
		fuchsia-cprng-0.1.1 \
		getrandom-0.2.3 \
		globset-0.4.8 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		humantime-2.1.0 \
		ignore-0.4.18 \
		indexmap-1.8.0 \
		jemalloc-sys-0.3.2 \
		jemallocator-0.3.2 \
		lazy_static-1.4.0 \
		libc-0.2.112 \
		log-0.4.14 \
		lscolors-0.8.1 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		nix-0.23.1 \
		normpath-0.3.2 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		num_cpus-1.13.1 \
		once_cell-1.9.0 \
		os_str_bytes-6.0.0 \
		proc-macro2-1.0.36 \
		quote-1.0.14 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rdrand-0.4.0 \
		redox_syscall-0.2.10 \
		redox_users-0.4.0 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		same-file-1.0.6 \
		strsim-0.10.0 \
		syn-1.0.85 \
		tempdir-0.3.7 \
		termcolor-1.1.2 \
		terminal_size-0.1.17 \
		test-case-1.2.1 \
		textwrap-0.14.2 \
		thread_local-1.1.3 \
		time-0.1.43 \
		unicode-xid-0.2.2 \
		users-0.11.0 \
		version_check-0.9.4 \
		walkdir-2.3.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

MAKE_ENV=	SHELL_COMPLETIONS_DIR=${WRKDIR}/completions

CONFLICTS_INSTALL=	fd

PLIST_FILES=	bin/fd \
		etc/bash_completion.d/fd.bash \
		share/fish/completions/fd.fish \
		share/man/man1/fd.1.gz \
		share/zsh/site-functions/_fd

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fd
	${INSTALL_MAN} ${WRKSRC}/doc/fd.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKDIR}/completions/fd.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKDIR}/completions/fd.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/contrib/completion/_fd \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
