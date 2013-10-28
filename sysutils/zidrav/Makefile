# Created by: Cosmin Stroe <cstroe1@uic.edu>
# $FreeBSD$

PORTNAME=	zidrav
PORTVERSION=	1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}4unix/${PORTVERSION}
DISTNAME=	zidrav4unix-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A file corruption detection and repair program

LICENSE=	GPLv2

ALL_TARGET=	zidrav
PLIST_FILES=	bin/zidrav man/man1/zidrav.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zidrav ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/zidrav.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
