# Created by: Matthew Dillon <dillon@backplane.com>
# $FreeBSD$

PORTNAME=	cpdup
PORTVERSION=	1.18
CATEGORIES=	sysutils
MASTER_SITES=	http://apollo.backplane.com/FreeSrc/ \
		http://utenti.gufi.org/~gmarco/files/distfiles/

MAINTAINER=	gmarco@gufi.org
COMMENT=	Comprehensive filesystem mirroring and backup program

USES=		tar:tgz

WRKSRC=		${WRKDIR}/${PORTNAME}

CFLAGS+=	-D_ST_FLAGS_PRESENT_

PLIST_FILES=	bin/cpdup man/man1/cpdup.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpdup ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cpdup.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
