# Created by: Dierk Sacher <dierk@blaxxtarz.de>
# $FreeBSD$

PORTNAME=	ffmpegthumbnailer
PORTVERSION=	2.2.0
PORTREVISION=	10
CATEGORIES=	multimedia graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight video thumbnailer that can be used by file managers

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libswscale.so:multimedia/ffmpeg

USE_GITHUB=	yes
GH_ACCOUNT=	dirkvdb

USES=		cmake compiler:c++11-lib gnome jpeg localbase pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_GIO=ON

OPTIONS_DEFINE=	THUMBNAILER
THUMBNAILER_DESC=Register as a system thumbnailer
OPTIONS_SUB=	yes
OPTIONS_DEFAULT=THUMBNAILER

THUMBNAILER_CMAKE_ON=	-DENABLE_THUMBNAILER=ON

.include <bsd.port.mk>
