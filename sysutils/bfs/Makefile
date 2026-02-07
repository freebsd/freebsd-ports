PORTNAME=	bfs
DISTVERSION=	4.1
CATEGORIES=	sysutils

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Breadth-first version of the UNIX find command
WWW=		https://github.com/tavianator/bfs

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	bash:shells/bash

USES=		compiler:c++17-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	tavianator

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

TEST_TARGET=	check

OPTIONS_DEFINE=		ONIGURUMA RELEASE
OPTIONS_DEFAULT=	ONIGURUMA RELEASE

ONIGURUMA_DESC=		Oniguruma regular expression support
RELEASE_DESC=		Enable optimizations, disable assertions

ONIGURUMA_LIB_DEPENDS=		libonig.so:devel/oniguruma
ONIGURUMA_CONFIGURE_WITH=	oniguruma

RELEASE_CONFIGURE_ENABLE=	release

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bfs

.include <bsd.port.mk>
