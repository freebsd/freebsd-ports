PORTNAME=	coxswain
DISTVERSIONPREFIX=	v
DISTVERSION=	2.34.0
CATEGORIES=	sysutils

MAINTAINER=	michael.w.olesen@gmail.com
COMMENT=	Two-panel file manager for the terminal, Norton Commander style
WWW=		https://github.com/mwo-dk/coxswain

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	mwo-dk
USE_RC_SUBR=	coxswain_index

CARGO_BUILD_ARGS=	--package coxswain
CARGO_INSTALL_PATH=	crates/coxswain
CARGO_TEST_ARGS=	--package coxswain --package coxswain-core

PLIST_FILES=	bin/cox \
		bin/coxswain \
		share/man/man1/coxswain.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/crates/coxswain/coxswain.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
