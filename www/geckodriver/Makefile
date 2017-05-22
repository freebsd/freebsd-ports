# $FreeBSD$

PORTNAME=	geckodriver
PORTVERSION=	0.16.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	http://freebsd-ports.mytaste.org/www/geckodriver/:crates
DISTFILES=	registry-${PORTVERSION}.tar.gz:crates

MAINTAINER=	daniel@blodan.se
COMMENT=	Proxy for using WebDriver clients with Gecko-based browsers

LICENSE=	MPL

BUILD_DEPENDS=	cargo:devel/cargo

USE_GITHUB=	yes
GH_ACCOUNT=	mozilla

MAKE_ENV=	CARGO_HOME=${BUILD_WRKSRC}

PLIST_FILES=	bin/geckodriver

post-extract:
	cd ${WRKDIR} && ${COPYTREE_SHARE} registry ${WRKSRC}
	${MKDIR} ${BUILD_WRKSRC}/.cargo
	${ECHO} "[source.crates-io]" > ${BUILD_WRKSRC}/.cargo/config
	${ECHO} "local-registry = 'registry'" >> ${BUILD_WRKSRC}/.cargo/config

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} cargo build --release --verbose

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/target/release/geckodriver ${STAGEDIR}${PREFIX}/bin/geckodriver

.include <bsd.port.mk>
