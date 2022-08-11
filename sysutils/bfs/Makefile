PORTNAME=	bfs
DISTVERSION=	2.6.1
CATEGORIES=	sysutils

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Breadth-first version of the UNIX find command

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	bash:shells/bash

USES=		compiler:c11 gmake shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	tavianator

TEST_TARGET=	check

OPTIONS_DEFINE=		ONIGURUMA
OPTIONS_DEFAULT=	ONIGURUMA

ONIGURUMA_DESC=		Oniguruma regular expression support

ONIGURUMA_LIB_DEPENDS=		libonig.so:devel/oniguruma
ONIGURUMA_MAKE_ARGS_OFF=	WITH_ONIGURUMA=

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bfs

.include <bsd.port.mk>
