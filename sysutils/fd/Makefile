# Created by: Andrey Cherkashin <andoriyu@gmail.com>
# $FreeBSD$

PORTNAME=	fd
DISTVERSIONPREFIX=	v
DISTVERSION=	7.0.0
PORTREVISION=	1
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
CARGO_CRATES=	aho-corasick-0.6.4 \
	ansi_term-0.11.0 \
	atty-0.2.8 \
	bitflags-0.9.1 \
	bitflags-1.0.1 \
	cfg-if-0.1.2 \
	clap-2.31.1 \
	crossbeam-0.3.2 \
	ctrlc-3.1.0 \
	diff-0.1.11 \
	fnv-1.0.6 \
	fuchsia-zircon-0.3.3 \
	fuchsia-zircon-sys-0.3.3 \
	globset-0.3.0 \
	ignore-0.4.1 \
	kernel32-sys-0.2.2 \
	lazy_static-1.0.0 \
	libc-0.2.40 \
	log-0.4.1 \
	memchr-2.0.1 \
	nix-0.9.0 \
	num_cpus-1.8.0 \
	rand-0.4.2 \
	redox_syscall-0.1.37 \
	redox_termios-0.1.1 \
	regex-0.2.8 \
	regex-syntax-0.5.2 \
	remove_dir_all-0.3.0 \
	same-file-1.0.2 \
	strsim-0.7.0 \
	tempdir-0.3.6 \
	term_size-0.3.1 \
	termion-1.5.1 \
	textwrap-0.9.0 \
	thread_local-0.3.5 \
	ucd-util-0.1.1 \
	unicode-width-0.1.4 \
	unreachable-1.0.0 \
	utf8-ranges-1.0.0 \
	vec_map-0.8.0 \
	version_check-0.1.3 \
	void-1.0.2 \
	walkdir-2.1.4 \
	winapi-0.2.8 \
	winapi-0.3.4 \
	winapi-build-0.1.1 \
	winapi-i686-pc-windows-gnu-0.4.0 \
	winapi-x86_64-pc-windows-gnu-0.4.0

SHELL_COMPLETIONS_DIR=	${WRKDIR}/shell-completions-dir
CARGO_ENV=	SHELL_COMPLETIONS_DIR=${SHELL_COMPLETIONS_DIR}

PLIST_FILES=	bin/fd \
		man/man1/fd.1.gz

OPTIONS_DEFINE=		BASH FISH ZSH
OPTIONS_DEFAULT=	BASH FISH ZSH

BASH_PLIST_FILES=	etc/bash_completion.d/fd.bash
FISH_PLIST_FILES=	share/fish/completions/fd.fish
ZSH_PLIST_FILES=	share/zsh/site-functions/_fd

# This can be removed after https://github.com/sharkdp/fd/pull/169 has
# been merged.
#pre-build:
#	@${MKDIR} ${SHELL_COMPLETIONS_DIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fd
	${INSTALL_MAN} ${WRKSRC}/doc/fd.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${SHELL_COMPLETIONS_DIR}/fd.bash \
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
