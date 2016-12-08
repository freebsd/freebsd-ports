# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	npapi-vlc
PORTVERSION=	2.0.6
PORTREVISION=	4
CATEGORIES=	www multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/vlc-webplugins/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embeds vlc-player in web-browsers

LIB_DEPENDS=	libvlc.so:multimedia/vlc \
		libxul.so:www/libxul

USES=		libtool pkgconfig tar:xz webplugin:native
USE_GNOME=	gtk20
WEBPLUGIN_NAME=	#
WEBPLUGIN_FILES=libvlcplugin.so
GNU_CONFIGURE=	yes
PLIST_FILES=	${WEBPLUGIN_DIR:S,^${PREFIX}/,,}${WEBPLUGIN_FILES}
PATCH_STRIP=	-p1

do-install:
	${MKDIR} ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_LIB} ${WRKSRC}/npapi/.libs/libvlcplugin.so	\
		${STAGEDIR}/${WEBPLUGIN_DIR}

.include <bsd.port.mk>
