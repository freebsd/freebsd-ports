# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	tcpshow
PORTVERSION=	1.74
PORTREVISION=	2
CATEGORIES=	net security
MASTER_SITES=	LOCAL/obrien
DISTFILES=	tcpshow.c tcpshow.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Decode tcpdump(1) output

NO_WRKSUBDIR=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/tcpshow.c ${WRKSRC}
	@${CP} ${DISTDIR}/tcpshow.1 ${WRKSRC}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o tcpshow tcpshow.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpshow ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tcpshow.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
