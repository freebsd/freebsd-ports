# Created by: dk
# $FreeBSD$

PORTNAME=	nntpbtr
PORTVERSION=	1.7
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/news/

MAINTAINER=	dk@farm.org
COMMENT=	NNTP bulk transfer

USES=	tar:Z
PLIST_FILES=	sbin/${PORTNAME} man/man1/${PORTNAME}.1.gz

ALL_TARGET=	${PORTNAME}

pre-build:
	(cd ${FILESDIR} ; ${PAX} -rw -l -u dbz ${WRKDIR}) || ${TRUE}
	(cd ${WRKDIR}/dbz ; ${CC} ${CFLAGS} -c -I. dbz.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
