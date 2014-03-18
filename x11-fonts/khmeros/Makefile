# Created by: Kuan-Chung Chiu <buganini@gmail.com>
# $FreeBSD$

PORTNAME=	khmeros
PORTVERSION=	5.0
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/khmer/Fonts%20-%20KhmerOS/KhmerOS%20Fonts%205.0-%20LGPL%20Licence
DISTNAME=	All_KhmerOS_5.0

MAINTAINER=	buganini@gmail.com
COMMENT=	Khmer OS fonts

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USES=		zip
NO_BUILD=	yes

FONTSDIR=	lib/X11/fonts/Khmer/
PLIST_SUB+=	FONTSDIR=${FONTSDIR}

post-patch:
	${MV} "${WRKSRC}/KhmerOS .ttf" ${WRKSRC}/KhmerOS.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${PREFIX}/${FONTSDIR}

.include <bsd.port.mk>
