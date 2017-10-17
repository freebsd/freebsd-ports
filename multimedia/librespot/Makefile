# $FreeBSD$

PORTNAME=	librespot
PORTVERSION=	0.1.0
CATEGORIES=	multimedia net devel

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	Open Source Spotify client library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		tries to clone git repository during build phase

BUILD_DEPENDS=	rust>=1.19.0_2:lang/rust \
		portaudio>0:audio/portaudio

USES=		localbase pathfix pkgconfig shebangfix
USE_LDCONFIG=	yes

# Rust's target arch string is different from *BSD arch strings
RUST_ARCH_x86_64=	x86_64 # dragonfly
RUST_ARCH_amd64=	x86_64
RUST_ARCH_i386=		i686
RUST_TARGET=		${RUST_ARCH_${ARCH}}-unknown-${OPSYS:tl}

USE_GITHUB=	yes
GH_ACCOUNT=	plietar
GH_TAGNAME=	85dbc3b

MAKE_ENV=	CARGO_HOME=${BUILD_WRKSRC}

PLIST_FILES=	bin/${PORTNAME} \
		lib/rustlib/${RUST_TARGET}/lib/lib${PORTNAME}.rlib

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} cargo build --release --verbose

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/rustlib/${RUST_TARGET}/lib
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/target/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/target/release/${PORTNAME} ${STAGEDIR}${PREFIX}/lib/rustlib/${RUST_TARGET}/lib/lib${PORTNAME}.rlib

.include <bsd.port.mk>
