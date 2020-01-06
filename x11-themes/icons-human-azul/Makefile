# Created by: Phillip Neumann <pneumann@gmail.com>
# $FreeBSD$

PORTNAME=	icons-human-azul
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	http://vvelox.net/distfiles/
DISTNAME=	37099-HumanAzul

MAINTAINER=	pneumann@gmail.com
COMMENT=	Set of icons from the Ubuntu human look

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/HumanAzul

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/HumanAzul
	@${CP} -rip ${WRKSRC} ${STAGEDIR}${PREFIX}/share/icons/

.include <bsd.port.mk>
