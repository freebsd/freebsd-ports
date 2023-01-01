PORTNAME=	faketty
DISTVERSION=	1.0.9
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

CARGO_CRATES=	atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		clap-3.2.23 \
		clap_derive-3.2.18 \
		clap_lex-0.2.4 \
		hashbrown-0.12.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		indexmap-1.9.2 \
		libc-0.2.139 \
		nix-0.25.1 \
		os_str_bytes-6.4.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.49 \
		quote-1.0.23 \
		scratch-1.0.3 \
		strsim-0.10.0 \
		syn-1.0.107 \
		termcolor-1.1.3 \
		textwrap-0.16.0 \
		unicode-ident-1.0.6 \
		version_check-0.9.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
