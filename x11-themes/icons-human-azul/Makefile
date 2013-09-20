# Created by: Phillip Neumann <pneumann@gmail.com>
# $FreeBSD$

PORTNAME=	icons-human-azul
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	37099-HumanAzul

MAINTAINER=	pneumann@gmail.com
COMMENT=	A set of icons from the Ubuntu human look

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/HumanAzul

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/share/icons/HumanAzul
	@${CP} -rip ${WRKSRC} ${PREFIX}/share/icons/

.include <bsd.port.mk>
