# Created by: Andrey Cherkashin <andoriyu@gmail.com>

PORTNAME=	fd
DISTVERSIONPREFIX=	v
DISTVERSION=	8.2.1
PORTREVISION=	4
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

CARGO_CRATES=	aho-corasick-0.7.15 \
		ansi_term-0.11.0 \
		ansi_term-0.12.1 \
		anyhow-1.0.35 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		bstr-0.2.14 \
		cc-1.0.66 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		crossbeam-utils-0.8.1 \
		ctrlc-3.1.7 \
		diff-0.1.12 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.1 \
		filetime-0.2.13 \
		fnv-1.0.7 \
		fs_extra-1.2.0 \
		fuchsia-cprng-0.1.1 \
		getrandom-0.1.15 \
		globset-0.4.6 \
		hermit-abi-0.1.17 \
		humantime-2.0.1 \
		ignore-0.4.17 \
		jemalloc-sys-0.3.2 \
		jemallocator-0.3.2 \
		lazy_static-1.4.0 \
		libc-0.2.80 \
		log-0.4.11 \
		lscolors-0.7.1 \
		memchr-2.3.4 \
		nix-0.18.0 \
		num_cpus-1.13.0 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rdrand-0.4.0 \
		redox_syscall-0.1.57 \
		redox_users-0.3.5 \
		regex-1.4.2 \
		regex-syntax-0.6.21 \
		remove_dir_all-0.5.3 \
		same-file-1.0.6 \
		strsim-0.8.0 \
		tempdir-0.3.7 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		unicode-width-0.1.8 \
		users-0.11.0 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		walkdir-2.3.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
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
