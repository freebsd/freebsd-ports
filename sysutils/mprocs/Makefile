PORTNAME=	mprocs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.4
PORTREVISION=	11
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

.include <bsd.port.pre.mk>

.if ${ARCH:Mpowerpc64*}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src_Cargo.toml
LIB_DEPENDS=	libluajit-5.1.so:lang/luajit-openresty
.endif

.if ${ARCH} == powerpc
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src_Cargo.toml
LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's/new\("make"\)/new("gmake")/' ${WRKSRC}/cargo-crates/luajit-src-*/src/lib.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mprocs

.include <bsd.port.post.mk>
