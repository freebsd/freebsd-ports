# Created by: Kuan-Chung Chiu <buganini@gmail.com>
# $FreeBSD$

PORTNAME=	padauk
PORTVERSION=	2.8
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?&format=file&media_id=Mh_Padauk_zip&filename=/
DISTNAME=	${PORTNAME}-${PORTVERSION}0

MAINTAINER=	buganini@gmail.com
COMMENT=	Unicode font supporting all the Myanmar characters

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
NO_BUILD=	yes
USES=		fonts zip

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
