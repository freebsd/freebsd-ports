# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	babeld
PORTVERSION=	1.8.1
CATEGORIES=	net
MASTER_SITES=	http://www.pps.univ-paris-diderot.fr/~jch/software/files/

MAINTAINER=	gaod@hychen.org
COMMENT=	Distance-vector routing protocol

LICENSE=	MIT

MAKE_ARGS=	CDEBUGFLAGS="-O2 -g -Wall"

PLIST_FILES=	bin/babeld \
		man/man8/babeld.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/babeld ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/babeld.man ${STAGEDIR}${PREFIX}/man/man8/babeld.8

.include <bsd.port.mk>
