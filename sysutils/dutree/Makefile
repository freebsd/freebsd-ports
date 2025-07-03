PORTNAME=	dutree
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.15
PORTREVISION=	19
CATEGORIES=	sysutils

PATCH_SITES=	https://github.com/nachoparker/dutree/commit/
PATCHFILES=	55b8218767626e40940ee2cfd7cf1c4f643079cc.patch:-p1

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Tool to analyze file system usage written in Rust
WWW=		https://github.com/nachoparker/dutree

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	nachoparker

CARGO_CRATES=	aho-corasick-0.7.6 \
		arc-swap-0.4.3 \
		getopts-0.2.21 \
		lazy_static-1.0.0 \
		libc-0.2.145 \
		memchr-2.2.1 \
		regex-1.3.1 \
		regex-syntax-0.6.12 \
		signal-hook-0.1.10 \
		signal-hook-registry-1.1.1 \
		terminal_size-0.1.8 \
		thread_local-0.3.6 \
		unicode-segmentation-1.2.0 \
		unicode-width-0.1.6 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
