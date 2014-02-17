# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	npapi-vlc
PORTVERSION=	2.0.6
CATEGORIES=	www multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/vlc-webplugins/${PORTVERSION}/

MAINTAINER=	mi@aldan.algber.com
COMMENT=	Embeds vlc-player in web-browsers

LIB_DEPENDS=	libvlc.so:${PORTSDIR}/multimedia/vlc

USES=	webplugin:native
USE_XZ=	yes
WEBPLUGIN_NAME=	#
WEBPLUGIN_FILES=libvlcplugin.so
GNU_CONFIGURE=	yes
PLIST_FILES=	${WEBPLUGIN_DIR:S,^${PREFIX}/,,}${WEBPLUGIN_FILES}

do-install:
	${MKDIR} ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_LIB} ${WRKSRC}/npapi/.libs/libvlcplugin.so	\
		${STAGEDIR}/${WEBPLUGIN_DIR}

.include <bsd.port.mk>
