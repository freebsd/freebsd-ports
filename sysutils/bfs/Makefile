# $FreeBSD$

PORTNAME=	bfs
DISTVERSION=	1.5
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

SHEBANG_FILES=	tests.sh tests/*.sh

TEST_TARGET=	check

PLIST_FILES=	bin/bfs \
		man/man1/bfs.1.gz

post-patch:
# Disable test_L_acl and test_acl tests since they assume POSIX.1e
# ACLs and will fail on ZFS or tmpfs.
	@${REINPLACE_CMD} -e '/^    test_acl/d' -e '/^    test_L_acl/d' \
		${WRKSRC}/tests.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bfs ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bfs.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
