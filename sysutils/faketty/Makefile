PORTNAME=	faketty
DISTVERSION=	1.0.12
PORTREVISION=	5
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

CARGO_CRATES=	bitflags-1.3.2 \
		cc-1.0.78 \
		cfg-if-1.0.0 \
		clap-4.0.32 \
		clap_derive-4.0.21 \
		clap_lex-0.3.0 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		heck-0.4.0 \
		hermit-abi-0.2.6 \
		io-lifetimes-1.0.3 \
		is-terminal-0.4.2 \
		libc-0.2.139 \
		linux-raw-sys-0.1.4 \
		nix-0.26.1 \
		os_str_bytes-6.4.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.49 \
		quote-1.0.23 \
		rustix-0.36.6 \
		scratch-1.0.3 \
		static_assertions-1.1.0 \
		strsim-0.10.0 \
		syn-1.0.107 \
		termcolor-1.1.3 \
		unicode-ident-1.0.6 \
		version_check-0.9.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.0 \
		windows_aarch64_msvc-0.42.0 \
		windows_i686_gnu-0.42.0 \
		windows_i686_msvc-0.42.0 \
		windows_x86_64_gnu-0.42.0 \
		windows_x86_64_gnullvm-0.42.0 \
		windows_x86_64_msvc-0.42.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
