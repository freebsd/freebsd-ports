PORTNAME=	wallet-engine
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.7
CATEGORIES=	net-p2p

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Rust library for TON wallet applications.
WWW=		https://github.com/i582/wallet-engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cargo
#CARGO_FEATURES=	c-api

USE_GITHUB=	yes
GH_ACCOUNT=	i582

BINDINGS_FILES=	${WRKSRC}/*.el ${WRKSRC}/extensions/*.el

# generate C++ bindings required by telegram-desktop
post-build:
	(cd ${WRKSRC} && cargo xtask bindings cpp)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME:S/-/_/}
	${INSTALL_DATA} ${WRKSRC}/bindings/cpp-experimental/* ${STAGEDIR}${PREFIX}/include/${PORTNAME:S/-/_/}/
	${INSTALL_DATA} ${WRKDIR}/target/release/lib${PORTNAME:S/-/_/}.a ${STAGEDIR}${PREFIX}/lib
# Get ready to install shared library too when needed
#	${INSTALL_LIB} ${WRKDIR}/target/release/lib${PORTNAME:S/-/_/}.so ${STAGEDIR}${PREFIX}/lib
#	${LN} -sf lib${PORTNAME:S/-/_/}.so ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME:S/-/_/}.so.${DISTVERSION:R}
#	${LN} -sf lib${PORTNAME:S/-/_/}.so ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME:S/-/_/}.so.${DISTVERSION:R:R}

.include <bsd.port.mk>
