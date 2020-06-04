# $FreeBSD$

PORTNAME=	exa
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
PORTREVISION=	11
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Modern replacement for ls

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ogham

CARGO_CRATES=	aho-corasick-0.7.3 \
		ansi_term-0.12.0 \
		atty-0.2.11 \
		autocfg-0.1.4 \
		bitflags-1.0.4 \
		byteorder-1.3.2 \
		cc-1.0.35 \
		cfg-if-0.1.7 \
		datetime-0.4.7 \
		env_logger-0.6.1 \
		git2-0.9.1 \
		glob-0.3.0 \
		humantime-1.2.0 \
		idna-0.1.5 \
		iso8601-0.1.1 \
		kernel32-sys-0.2.2 \
		lazy_static-1.3.0 \
		libc-0.2.51 \
		libgit2-sys-0.8.1 \
		libz-sys-1.0.25 \
		locale-0.2.2 \
		log-0.4.6 \
		matches-0.1.8 \
		memchr-2.2.0 \
		natord-1.0.9 \
		nom-1.2.4 \
		num-traits-0.1.43 \
		num-traits-0.2.6 \
		num_cpus-1.10.0 \
		number_prefix-0.3.0 \
		openssl-src-111.3.0+1.1.1c \
		openssl-sys-0.9.47 \
		pad-0.1.5 \
		percent-encoding-1.0.1 \
		pkg-config-0.3.14 \
		quick-error-1.2.2 \
		redox_syscall-0.1.54 \
		redox_termios-0.1.1 \
		regex-1.1.6 \
		regex-syntax-0.6.6 \
		scoped_threadpool-0.1.9 \
		smallvec-0.6.9 \
		term_grid-0.1.7 \
		term_size-0.3.1 \
		termcolor-1.0.4 \
		termion-1.5.1 \
		thread_local-0.3.6 \
		ucd-util-0.1.3 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.8 \
		unicode-width-0.1.5 \
		url-1.7.2 \
		users-0.9.1 \
		utf8-ranges-1.0.2 \
		vcpkg-0.2.6 \
		winapi-0.2.8 \
		winapi-0.3.7 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1 \
		zoneinfo_compiled-0.4.8

PLIST_FILES=	bin/exa \
		man/man1/exa.1.gz \
		etc/bash_completion.d/exa.bash \
		share/fish/completions/exa.fish \
		share/zsh/site-functions/_exa

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/contrib/completions.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d/exa.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/contrib/completions.fish ${STAGEDIR}${PREFIX}/share/fish/completions/exa.fish
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/contrib/completions.zsh ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_exa
	${INSTALL_MAN} ${WRKSRC}/contrib/man/exa.1 ${STAGEDIR}${PREFIX}/man/man1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/exa

.include <bsd.port.mk>
