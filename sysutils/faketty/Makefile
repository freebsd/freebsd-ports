PORTNAME=	faketty
DISTVERSION=	1.0.18
PORTREVISION=	9
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

CARGO_CRATES=	anstream-0.6.15 \
		anstyle-1.0.8 \
		anstyle-parse-0.2.5 \
		anstyle-query-1.1.1 \
		anstyle-wincon-3.0.4 \
		bitflags-2.6.0 \
		cfg-if-1.0.0 \
		cfg_aliases-0.2.1 \
		clap-4.5.16 \
		clap_builder-4.5.15 \
		clap_derive-4.5.13 \
		clap_lex-0.7.2 \
		colorchoice-1.0.2 \
		heck-0.5.0 \
		is_terminal_polyfill-1.70.1 \
		libc-0.2.157 \
		nix-0.29.0 \
		proc-macro2-1.0.86 \
		quote-1.0.36 \
		scratch-1.0.7 \
		strsim-0.11.1 \
		syn-2.0.75 \
		unicode-ident-1.0.12 \
		utf8parse-0.2.2 \
		windows-sys-0.52.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
