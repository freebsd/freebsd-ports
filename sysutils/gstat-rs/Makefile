PORTNAME=	gstat-rs
DISTVERSIONPREFIX=	gstat-v
DISTVERSION=	0.1.6
PORTREVISION=	13
CATEGORIES=	sysutils

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Replacement for gstat(8)
WWW=		https://github.com/asomers/gstat-rs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc=	bindgen crashes, see https://github.com/rust-lang/rust-bindgen/issues/1746

BUILD_DEPENDS=	llvm-config${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	asomers
SUB_FILES=	pkg-message

CARGO_INSTALL_PATH=	gstat
CARGO_CARGOTOML=	${WRKSRC}/gstat/Cargo.toml
CARGO_TEST_ARGS=	--all
CARGO_ENV+=	LLVM_CONFIG_PATH=${LOCALBASE}/bin/llvm-config${LLVM_DEFAULT}

PLIST_FILES=	sbin/gstat-rs \
		share/man/man8/gstat-rs.8.gz

post-install:
	${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/gstat ${STAGEDIR}${PREFIX}/sbin/gstat-rs
	${RM} ${STAGEDIR}${PREFIX}/bin/gstat
	${INSTALL_MAN} ${WRKSRC}/gstat/doc/gstat.8 ${STAGEDIR}${PREFIX}/share/man/man8/gstat-rs.8

.include <bsd.port.mk>
