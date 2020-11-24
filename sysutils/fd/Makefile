# Created by: Andrey Cherkashin <andoriyu@gmail.com>
# $FreeBSD$

PORTNAME=	fd
DISTVERSIONPREFIX=	v
DISTVERSION=	8.1.1
PORTREVISION=	6
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

CARGO_CRATES=	aho-corasick-0.7.10 \
		ansi_term-0.11.0 \
		ansi_term-0.12.1 \
		anyhow-1.0.31 \
		arrayref-0.3.6 \
		arrayvec-0.5.1 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		base64-0.11.0 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.10 \
		bstr-0.2.13 \
		cc-1.0.53 \
		cfg-if-0.1.10 \
		clap-2.33.1 \
		constant_time_eq-0.1.5 \
		crossbeam-utils-0.7.2 \
		ctrlc-3.1.4 \
		diff-0.1.12 \
		dirs-2.0.2 \
		dirs-sys-0.3.4 \
		filetime-0.2.10 \
		fnv-1.0.7 \
		fs_extra-1.1.0 \
		fuchsia-cprng-0.1.1 \
		getrandom-0.1.14 \
		globset-0.4.5 \
		hermit-abi-0.1.13 \
		humantime-2.0.0 \
		ignore-0.4.15 \
		jemalloc-sys-0.3.2 \
		jemallocator-0.3.2 \
		lazy_static-1.4.0 \
		libc-0.2.70 \
		log-0.4.8 \
		lscolors-0.7.0 \
		memchr-2.3.3 \
		nix-0.17.0 \
		num_cpus-1.13.0 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		redox_users-0.3.4 \
		regex-1.3.7 \
		regex-syntax-0.6.17 \
		remove_dir_all-0.5.2 \
		rust-argon2-0.7.0 \
		same-file-1.0.6 \
		strsim-0.8.0 \
		tempdir-0.3.7 \
		term_size-0.3.2 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		unicode-width-0.1.7 \
		users-0.10.0 \
		vec_map-0.8.2 \
		version_check-0.9.1 \
		void-1.0.2 \
		walkdir-2.3.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.8 \
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
	${INSTALL_DATA} ${WRKDIR}/completions/_fd \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
