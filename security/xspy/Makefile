# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	xspy
PORTVERSION=	1.0c
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.acm.vt.edu/~jmaxwell/programs/xspy/

MAINTAINER=	onatan@gmail.com
COMMENT=	Utility for monitoring keystrokes on remote X servers

BROKEN=		unfetchable

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		imake:notall xorg
USE_XORG=	x11

ALL_TARGET=	xspy

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xspy ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
