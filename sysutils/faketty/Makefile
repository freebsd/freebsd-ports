PORTNAME=	faketty
DISTVERSION=	1.0.21
PORTREVISION=	0
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

CARGO_CRATES=	anstream-1.0.0 \
		anstyle-1.0.14 \
		anstyle-parse-1.0.0 \
		anstyle-query-1.1.5 \
		anstyle-wincon-3.0.11 \
		bitflags-2.13.2 \
		cfg-if-1.0.5 \
		cfg_aliases-0.2.2 \
		clap-4.6.7 \
		clap_builder-4.6.7 \
		clap_derive-4.6.7 \
		clap_lex-1.1.1 \
		colorchoice-1.0.5 \
		heck-0.5.0 \
		is_terminal_polyfill-1.70.2 \
		libc-0.2.191 \
		nix-0.32.0 \
		once_cell_polyfill-1.70.2 \
		proc-macro2-1.0.107 \
		quote-1.0.47 \
		scratch-1.0.9 \
		strsim-0.11.1 \
		syn-3.0.10 \
		unicode-ident-1.0.27 \
		utf8parse-0.2.2 \
		windows-link-0.2.1 \
		windows-sys-0.61.2

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
