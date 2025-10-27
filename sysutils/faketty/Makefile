PORTNAME=	faketty
DISTVERSION=	1.0.19
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wrapper to exec a command in a pty, even if redirecting the output
WWW=		https://github.com/dtolnay/faketty

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	dtolnay

CARGO_CRATES=	anstream-0.6.21 \
		anstyle-1.0.13 \
		anstyle-parse-0.2.7 \
		anstyle-query-1.1.4 \
		anstyle-wincon-3.0.10 \
		bitflags-2.10.0 \
		cfg-if-1.0.4 \
		cfg_aliases-0.2.1 \
		clap-4.5.50 \
		clap_builder-4.5.50 \
		clap_derive-4.5.49 \
		clap_lex-0.7.6 \
		colorchoice-1.0.4 \
		heck-0.5.0 \
		is_terminal_polyfill-1.70.2 \
		libc-0.2.177 \
		nix-0.30.1 \
		once_cell_polyfill-1.70.2 \
		proc-macro2-1.0.103 \
		quote-1.0.41 \
		scratch-1.0.9 \
		strsim-0.11.1 \
		syn-2.0.108 \
		unicode-ident-1.0.20 \
		utf8parse-0.2.2 \
		windows-link-0.2.1 \
		windows-sys-0.60.2 \
		windows-targets-0.53.5 \
		windows_aarch64_gnullvm-0.53.1 \
		windows_aarch64_msvc-0.53.1 \
		windows_i686_gnu-0.53.1 \
		windows_i686_gnullvm-0.53.1 \
		windows_i686_msvc-0.53.1 \
		windows_x86_64_gnu-0.53.1 \
		windows_x86_64_gnullvm-0.53.1 \
		windows_x86_64_msvc-0.53.1

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
