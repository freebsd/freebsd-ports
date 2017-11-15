# Created by: Andrey Cherkashin <andoriyu@gmail.com>
# $FreeBSD$

PORTNAME=	fd
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.0
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-find

MAINTAINER=	andoriyu@gmail.com
COMMENT=	Simple, fast and user-friendly alternative to find

LICENSE=	MIT APACHE20
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

CONFLICTS_INSTALL=	fd-[0-9]*

CARGO_CRATES=	aho-corasick-0.6.3 \
		ansi_term-0.9.0 \
		atty-0.2.3 \
		bitflags-0.7.0 \
		bitflags-0.9.1 \
		clap-2.26.2 \
		conv-0.3.3 \
		crossbeam-0.2.10 \
		custom_derive-0.1.7 \
		diff-0.1.10 \
		fnv-1.0.5 \
		globset-0.2.0 \
		ignore-0.2.2 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.9 \
		libc-0.2.31 \
		log-0.3.8 \
		magenta-0.1.1 \
		magenta-sys-0.1.1 \
		memchr-1.0.1 \
		num_cpus-1.7.0 \
		rand-0.3.16 \
		redox_syscall-0.1.31 \
		redox_termios-0.1.1 \
		regex-0.2.2 \
		regex-syntax-0.4.1 \
		same-file-0.1.3 \
		shell-escape-0.1.3 \
		strsim-0.6.0 \
		tempdir-0.3.5 \
		term_size-0.3.0 \
		termion-1.5.1 \
		textwrap-0.8.0 \
		thread_local-0.3.4 \
		unicode-width-0.1.4 \
		unreachable-1.0.0 \
		utf8-ranges-1.0.0 \
		vec_map-0.8.0 \
		void-1.0.2 \
		walkdir-1.0.7 \
		winapi-0.2.8 \
		winapi-build-0.1.1

SHELL_COMPLETIONS_DIR=	${WRKDIR}/shell-completions-dir
CARGO_ENV=	SHELL_COMPLETIONS_DIR=${SHELL_COMPLETIONS_DIR}

PLIST_FILES=	bin/fd \
		man/man1/fd.1.gz

OPTIONS_DEFINE=		BASH FISH ZSH
OPTIONS_DEFAULT=	BASH FISH ZSH

BASH_PLIST_FILES=	etc/bash_completion.d/fd.bash-completion
FISH_PLIST_FILES=	share/fish/completions/fd.fish
ZSH_PLIST_FILES=	share/zsh/site-functions/_fd

# This can be removed after https://github.com/sharkdp/fd/pull/169 has
# been merged.
pre-build:
	@${MKDIR} ${SHELL_COMPLETIONS_DIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fd
	${INSTALL_MAN} ${WRKSRC}/doc/fd.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${SHELL_COMPLETIONS_DIR}/fd.bash-completion \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d

post-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${SHELL_COMPLETIONS_DIR}/fd.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${SHELL_COMPLETIONS_DIR}/_fd \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
