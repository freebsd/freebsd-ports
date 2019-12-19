# Created by: Andrey Cherkashin <andoriyu@gmail.com>
# $FreeBSD$

PORTNAME=	fd
DISTVERSIONPREFIX=	v
DISTVERSION=	7.4.0
PORTREVISION=	3
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-find

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Simple, fast and user-friendly alternative to find

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

CARGO_CRATES=	aho-corasick-0.7.6 \
		ansi_term-0.11.0 \
		ansi_term-0.12.1 \
		atty-0.2.13 \
		bitflags-1.1.0 \
		bstr-0.2.8 \
		cc-1.0.45 \
		cfg-if-0.1.9 \
		clap-2.33.0 \
		crossbeam-channel-0.3.9 \
		crossbeam-utils-0.6.6 \
		ctrlc-3.1.3 \
		diff-0.1.11 \
		filetime-0.2.7 \
		fnv-1.0.6 \
		fs_extra-1.1.0 \
		fuchsia-cprng-0.1.1 \
		globset-0.4.4 \
		humantime-1.3.0 \
		ignore-0.4.10 \
		jemalloc-sys-0.3.2 \
		jemallocator-0.3.2 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.62 \
		log-0.4.8 \
		lscolors-0.6.0 \
		memchr-2.2.1 \
		nix-0.14.1 \
		num_cpus-1.10.1 \
		quick-error-1.2.2 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		regex-1.3.1 \
		regex-syntax-0.6.12 \
		remove_dir_all-0.5.2 \
		same-file-1.0.5 \
		strsim-0.8.0 \
		tempdir-0.3.7 \
		term_size-0.3.1 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		unicode-width-0.1.6 \
		vec_map-0.8.1 \
		version_check-0.9.1 \
		void-1.0.2 \
		walkdir-2.2.9 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0
MAKE_ENV=	SHELL_COMPLETIONS_DIR=${WRKDIR}/completions

CONFLICTS_INSTALL=	fd

PLIST_FILES=	bin/fd \
		etc/bash_completion.d/fd.bash \
		man/man1/fd.1.gz \
		share/fish/completions/fd.fish \
		share/zsh/site-functions/_fd

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fd
	${INSTALL_MAN} ${WRKSRC}/doc/fd.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
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
