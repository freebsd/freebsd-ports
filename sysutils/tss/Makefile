# Created by: Peter Ankerstal <peter@pean.org>
# $FreeBSD$

PORTNAME=	tss
PORTVERSION=	0.8.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pulia.nu/tss/src/

MAINTAINER=	peter@pean.org
COMMENT=	Terminal ScreenSaver that allows you to lock you terminal

NO_STAGE=	yes
post-patch:
	@ ${REINPLACE_CMD} -e "s|/etc/tss|${PREFIX}/etc/tss|" ${WRKSRC}/src/main.c

do-install:
	${INSTALL_SCRIPT} -m 4755 ${WRKSRC}/tss ${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/tss
	${INSTALL_DATA} ${WRKSRC}/tss_art/*   ${PREFIX}/etc/tss
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ART_CREDITS COPYING Changelog INSTALL README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
