PORTNAME=	faketty
DISTVERSION=	1.0.20
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
		anstyle-query-1.1.5 \
		anstyle-wincon-3.0.11 \
		bitflags-2.11.0 \
		cfg-if-1.0.4 \
		cfg_aliases-0.2.1 \
		clap-4.5.60 \
		clap_builder-4.5.60 \
		clap_derive-4.5.55 \
		clap_lex-1.0.0 \
		colorchoice-1.0.4 \
		heck-0.5.0 \
		is_terminal_polyfill-1.70.2 \
		libc-0.2.183 \
		nix-0.31.2 \
		once_cell_polyfill-1.70.2 \
		proc-macro2-1.0.106 \
		quote-1.0.45 \
		scratch-1.0.9 \
		strsim-0.11.1 \
		syn-2.0.117 \
		unicode-ident-1.0.24 \
		utf8parse-0.2.2 \
		windows-link-0.2.1 \
		windows-sys-0.61.2

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
