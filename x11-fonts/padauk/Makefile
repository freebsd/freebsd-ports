# Created by: Kuan-Chung Chiu <buganini@gmail.com>
# $FreeBSD$

PORTNAME=	padauk
PORTVERSION=	2.8
DISTVERSIONSUFFIX=	0
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?&format=file&media_id=Mh_Padauk_zip&filename=/

MAINTAINER=	buganini@gmail.com
COMMENT=	Unicode font supporting all the Myanmar characters

LICENSE=	OFL11

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
NO_BUILD=	yes
USES=		fonts zip

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
