# $FreeBSD$

PORTNAME=	bfs
DISTVERSION=	1.3.1
CATEGORIES=	sysutils

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Breadth-first version of the UNIX find command

LICENSE=	BSD0CLAUSE
LICENSE_NAME=	BSD Zero Clause License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

TEST_DEPENDS=	bash:shells/bash

USES=		gmake shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	tavianator

SHEBANG_FILES=	tests/*.sh
PLIST_FILES=	bin/bfs \
		man/man1/bfs.1.gz
TEST_TARGET=	check

post-patch:
	@${REINPLACE_CMD} 's,/bin/bash,${LOCALBASE}/bin/bash,g' ${WRKSRC}/tests.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bfs ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bfs.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
