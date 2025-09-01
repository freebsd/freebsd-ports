PORTNAME=	aq
DISTVERSION=	0.3.0
PORTREVISION=	12
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extend jq for any data format
WWW=		https://github.com/rossmacarthur/aq

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

RUN_DEPENDS=	jq:textproc/jq

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	rossmacarthur

CARGO_CRATES=	anyhow-1.0.69 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cc-1.0.79 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		hashbrown-0.12.3 \
		hermit-abi-0.3.1 \
		indexmap-1.9.2 \
		io-lifetimes-1.0.5 \
		is-terminal-0.4.3 \
		itoa-1.0.5 \
		libc-0.2.139 \
		linux-raw-sys-0.1.4 \
		memchr-2.5.0 \
		nom8-0.2.0 \
		rustix-0.36.8 \
		ryu-1.0.12 \
		serde-1.0.152 \
		serde-transcode-1.1.1 \
		serde_json-1.0.93 \
		serde_spanned-0.6.1 \
		serde_yaml-0.9.17 \
		toml-0.7.2 \
		toml_datetime-0.6.1 \
		toml_edit-0.19.3 \
		unsafe-libyaml-0.2.5 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.45.0 \
		windows-targets-0.42.1 \
		windows_aarch64_gnullvm-0.42.1 \
		windows_aarch64_msvc-0.42.1 \
		windows_i686_gnu-0.42.1 \
		windows_i686_msvc-0.42.1 \
		windows_x86_64_gnu-0.42.1 \
		windows_x86_64_gnullvm-0.42.1 \
		windows_x86_64_msvc-0.42.1

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
