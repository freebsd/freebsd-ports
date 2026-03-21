PORTNAME=	dutree
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.18
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Tool to analyze file system usage written in Rust
WWW=		https://github.com/nachoparker/dutree

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	nachoparker

CARGO_CRATES=	aho-corasick-0.7.13 \
		arc-swap-0.4.7 \
		getopts-0.2.21 \
		lazy_static-1.4.0 \
		libc-0.2.145 \
		memchr-2.3.3 \
		regex-1.3.9 \
		regex-syntax-0.6.18 \
		signal-hook-0.1.16 \
		signal-hook-registry-1.2.0 \
		terminal_size-0.1.12 \
		thread_local-1.0.1 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
