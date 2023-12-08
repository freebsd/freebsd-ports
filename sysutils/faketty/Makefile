PORTNAME=	faketty
DISTVERSION=	1.0.13
PORTREVISION=	3
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

CARGO_CRATES=	anstream-0.5.0 \
		anstyle-1.0.2 \
		anstyle-parse-0.2.1 \
		anstyle-query-1.0.0 \
		anstyle-wincon-2.1.0 \
		bitflags-2.4.0 \
		cfg-if-1.0.0 \
		clap-4.4.0 \
		clap_builder-4.4.0 \
		clap_derive-4.4.0 \
		clap_lex-0.5.1 \
		colorchoice-1.0.0 \
		heck-0.4.1 \
		libc-0.2.147 \
		nix-0.27.0 \
		proc-macro2-1.0.66 \
		quote-1.0.33 \
		scratch-1.0.7 \
		strsim-0.10.0 \
		syn-2.0.29 \
		unicode-ident-1.0.11 \
		utf8parse-0.2.1 \
		windows-sys-0.48.0 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
