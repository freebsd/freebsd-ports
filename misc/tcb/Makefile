# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	tcb
PORTVERSION=	1.4a
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SUNSITE/utils/file

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File viewer for terminal

DEPRECATED=	Abandonware that uses sys/dir.h
EXPIRATION_DATE=	2019-07-12

USES=		gmake

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/tcb ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/tcb
	${INSTALL_DATA} ${WRKSRC}/tcbrc ${STAGEDIR}${PREFIX}/share/tcb
	${INSTALL_DATA} ${WRKSRC}/doc/HELP ${STAGEDIR}${PREFIX}/share/tcb
	${INSTALL_MAN} ${WRKSRC}/doc/tcb.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/tcb
	${INSTALL_DATA} ${WRKSRC}/doc/CHANGES ${STAGEDIR}${PREFIX}/share/doc/tcb
	${INSTALL_DATA} ${WRKSRC}/doc/COPYING ${STAGEDIR}${PREFIX}/share/doc/tcb
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/share/doc/tcb

.include <bsd.port.mk>
