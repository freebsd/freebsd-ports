# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	tcb
PORTVERSION=	1.4a
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File viewer for terminal

USES=		gmake

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
