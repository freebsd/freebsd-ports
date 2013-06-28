# Created by: minoura@netbsd.org
# $FreeBSD$

PORTNAME=	xcruiser
PORTVERSION=	0.30
PORTREVISION=	2
CATEGORIES=	x11-fm
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Navigate through a three-dimensional view of a file system

USES=		imake
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
MAN1=		xcruiser.1

post-install:
	@${MKDIR} ${PREFIX}/share/doc/xcruise
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xcruise

.include <bsd.port.mk>
