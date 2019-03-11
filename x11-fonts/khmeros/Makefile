# Created by: Kuan-Chung Chiu <buganini@gmail.com>
# $FreeBSD$

PORTNAME=	khmeros
PORTVERSION=	5.0
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/khmer/Fonts%20-%20KhmerOS/KhmerOS%20Fonts%205.0-%20LGPL%20Licence
DISTNAME=	All_KhmerOS_5.0

MAINTAINER=	buganini@gmail.com
COMMENT=	Khmer OS fonts

USES=		fonts zip
NO_BUILD=	yes

FONTNAME=	Khmer

post-patch:
	${MV} "${WRKSRC}/KhmerOS .ttf" ${WRKSRC}/KhmerOS.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
