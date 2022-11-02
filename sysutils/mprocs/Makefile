PORTNAME=	mprocs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.4
CATEGORIES=	sysutils

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Run multiple commands in parallel
WWW=		https://github.com/pvolok/mprocs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo gmake
USE_GITHUB=	yes
GH_ACCOUNT=	pvolok

CARGO_INSTALL_PATH=	src

PLIST_FILES=	bin/mprocs

post-patch:
	@${REINPLACE_CMD} -Ee 's/new\("make"\)/new("gmake")/' ${WRKSRC}/cargo-crates/luajit-src-*/src/lib.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mprocs

.include <bsd.port.mk>
