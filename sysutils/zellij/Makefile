PORTNAME=	zellij
DISTVERSIONPREFIX=	v
DISTVERSION=	0.44.3
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Versatile, extensible terminal multiplexer
WWW=		https://zellij.dev/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	wasmer-vm crate currently only supports aarch64 and amd64

BUILD_DEPENDS=	${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/libclang.so:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libzstd.so:archivers/zstd

USES=		cargo sqlite ssl

USE_GITHUB=	yes
GH_ACCOUNT=	zellij-org
CARGO_ENV=	LIBSQLITE3_SYS_USE_PKG_CONFIG=yes

PLIST_FILES=	bin/zellij

.include <bsd.port.mk>
