# $FreeBSD$

PORTNAME=	bfs
DISTVERSION=	2.2
CATEGORIES=	sysutils

MAINTAINER=	driesm.michiels@gmail.com
COMMENT=	Breadth-first version of the UNIX find command

LICENSE=	BSD0CLAUSE
LICENSE_NAME=	BSD Zero Clause License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

TEST_DEPENDS=	bash:shells/bash

USES=		compiler:c11 gmake shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	tavianator

SHEBANG_FILES=	tests.sh tests/*.sh
TEST_TARGET=	check

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bfs

.include <bsd.port.mk>
