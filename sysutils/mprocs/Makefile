PORTNAME=	mprocs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Run multiple commands in parallel
WWW=		https://github.com/pvolok/mprocs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	pvolok

CARGO_CARGOLOCK=	${WRKSRC}/../Cargo.lock

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/mprocs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mprocs

.include <bsd.port.mk>
