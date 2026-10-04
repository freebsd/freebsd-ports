PORTNAME=	dekit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.6
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Run multiple commands in parallel
WWW=		https://github.com/pvolok/dekit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		Cannot upgrade due to linuxisms
EXPIRATION_DATE=	2026-11-03

BUILD_DEPENDS=  ${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/libclang.so:devel/llvm${LLVM_DEFAULT}

USES=		cargo gmake
USE_GITHUB=	yes
GH_ACCOUNT=	pvolok

CARGO_INSTALL_PATH=	src

PLIST_FILES=	bin/dekit \
		bin/mprocs

.include <bsd.port.mk>
