# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	wmjulia
PORTVERSION=	0.40
PORTREVISION=	5
CATEGORIES=	misc windowmaker afterstep
MASTER_SITES=	http://web.novalis.org/programs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp that creates an animated Julia set

LICENSE=	GPLv2

USES=		gmake xorg
USE_XORG=	x11 xext xpm

WRKSRC=		${WRKDIR}/${PORTNAME}.app
PLIST_FILES=	bin/wmjulia

MAKE_ARGS=	-C ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
