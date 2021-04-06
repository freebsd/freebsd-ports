PORTNAME=	exa
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	sysutils

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Modern replacement for ls

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ogham

CARGO_CRATES=	ansi_term-0.12.1 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		byteorder-1.3.4 \
		cc-1.0.61 \
		cfg-if-0.1.10 \
		datetime-0.5.2 \
		git2-0.13.11 \
		glob-0.3.0 \
		hermit-abi-0.1.17 \
		idna-0.2.0 \
		jobserver-0.1.21 \
		lazy_static-1.4.0 \
		libc-0.2.79 \
		libgit2-sys-0.12.14+1.1.0 \
		libz-sys-1.1.2 \
		locale-0.2.2 \
		log-0.4.11 \
		matches-0.1.8 \
		natord-1.0.9 \
		num_cpus-1.13.0 \
		number_prefix-0.4.0 \
		openssl-src-111.12.0+1.1.1h \
		openssl-sys-0.9.58 \
		pad-0.1.6 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.19 \
		redox_syscall-0.1.57 \
		scoped_threadpool-0.1.9 \
		term_grid-0.1.7 \
		term_size-0.3.2 \
		tinyvec-0.3.4 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.13 \
		unicode-width-0.1.8 \
		url-2.1.1 \
		users-0.11.0 \
		vcpkg-0.2.10 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		zoneinfo_compiled-0.5.1

PLIST_FILES=	bin/exa \
		etc/bash_completion.d/exa.bash \
		share/fish/completions/exa.fish \
		share/zsh/site-functions/_exa

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completions/completions.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d/exa.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/completions/completions.fish ${STAGEDIR}${PREFIX}/share/fish/completions/exa.fish
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completions/completions.zsh ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_exa
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/exa

.include <bsd.port.mk>
