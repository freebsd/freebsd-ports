PORTNAME=	bfs
DISTVERSION=	2.3
CATEGORIES=	sysutils

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Breadth-first version of the UNIX find command

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	bash:shells/bash

USES=		compiler:c11 gmake shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	tavianator

SHEBANG_FILES=	tests.sh tests/*.sh
TEST_TARGET=	check

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bfs

.include <bsd.port.mk>
