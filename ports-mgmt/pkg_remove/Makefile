# Created by: NAKAJI Hiroyuki <nakaji@tutrp.tut.ac.jp>
# $FreeBSD$

PORTNAME=	pkg_remove
PORTVERSION=	1.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	nakaji@jp.freebsd.org
COMMENT=	Utility to uninstall packages

USES=		shebangfix
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SHEBANG_FILES=	pkg_remove
PLIST_FILES=	bin/pkg_remove

SRC=		${.CURDIR}/src

do-fetch:
	@${DO_NADA}

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${SRC}/pkg_remove.txt ${WRKSRC}/pkg_remove

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_remove ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
