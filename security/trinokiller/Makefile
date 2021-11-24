# Created by: David O'Brien (obrien@NUXI.com)

PORTNAME=	trinokiller
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	https://dl.packetstormsecurity.net/distributed/
DISTNAME=	trinokiller
EXTRACT_SUFX=	.c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Remotely kill trino nodes

DEPRECATED=	Abandonware, dead upstream
EXPIRATION_DATE=2022-03-31

PLIST_FILES=	sbin/trinokiller

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${DISTNAME} ${WRKSRC}/${DISTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${STAGEDIR}/${PREFIX}/sbin

.include <bsd.port.mk>
