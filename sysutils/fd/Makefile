# Created by: Andrey Cherkashin <andoriyu@gmail.com>
# $FreeBSD$

PORTNAME=	fd
DISTVERSIONPREFIX=	v
DISTVERSION=	7.3.0
PORTREVISION=	1
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-find

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Simple, fast and user-friendly alternative to find

LICENSE=	MIT APACHE20
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

CONFLICTS_INSTALL=	fd-[0-9]*

CARGO_CRATES=	aho-corasick-0.6.9 \
		ansi_term-0.11.0 \
		atty-0.2.11 \
		bitflags-1.0.4 \
		cc-1.0.29 \
		cfg-if-0.1.6 \
		clap-2.32.0 \
		crossbeam-channel-0.3.8 \
		crossbeam-utils-0.6.5 \
		ctrlc-3.1.1 \
		diff-0.1.11 \
		filetime-0.2.4 \
		fnv-1.0.6 \
		fuchsia-cprng-0.1.1 \
		globset-0.4.2 \
		humantime-1.2.0 \
		ignore-0.4.6 \
		kernel32-sys-0.2.2 \
		lazy_static-1.2.0 \
		libc-0.2.49 \
		log-0.4.6 \
		lscolors-0.5.0 \
		memchr-2.2.0 \
		nix-0.11.0 \
		num_cpus-1.10.0 \
		quick-error-1.2.2 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rdrand-0.4.0 \
		redox_syscall-0.1.51 \
		redox_termios-0.1.1 \
		regex-1.1.0 \
		regex-syntax-0.6.5 \
		remove_dir_all-0.5.1 \
		same-file-1.0.4 \
		smallvec-0.6.8 \
		strsim-0.7.0 \
		tempdir-0.3.7 \
		term_size-0.3.1 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		ucd-util-0.1.3 \
		unicode-width-0.1.5 \
		unreachable-1.0.0 \
		utf8-ranges-1.0.2 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		void-1.0.2 \
		walkdir-2.2.7 \
		winapi-0.2.8 \
		winapi-0.3.6 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0

SHELL_COMPLETIONS_DIR=	${WRKDIR}/shell-completions-dir
CARGO_ENV=	SHELL_COMPLETIONS_DIR=${SHELL_COMPLETIONS_DIR}

PLIST_FILES=	bin/fd \
		etc/bash_completion.d/fd.bash \
		man/man1/fd.1.gz \
		share/fish/completions/fd.fish \
		share/zsh/site-functions/_fd

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fd
	${INSTALL_MAN} ${WRKSRC}/doc/fd.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${SHELL_COMPLETIONS_DIR}/fd.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${SHELL_COMPLETIONS_DIR}/fd.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${SHELL_COMPLETIONS_DIR}/_fd \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
