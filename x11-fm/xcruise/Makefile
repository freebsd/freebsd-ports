# Created by: minoura@netbsd.org
# $FreeBSD$

PORTNAME=	xcruiser
PORTVERSION=	0.30
PORTREVISION=	3
CATEGORIES=	x11-fm
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Navigate through a three-dimensional view of a file system

USES=		imake
USE_XORG=	ice sm x11 xaw xext xmu xpm xt

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/xcruise
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/share/doc/xcruise

.include <bsd.port.mk>
