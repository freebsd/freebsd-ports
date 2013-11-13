# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xine
PORTVERSION=	1.0.2
PORTREVISION=	8
DISTVERSIONPREFIX=	plugin-
CATEGORIES=	www multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-plugin/${PORTVERSION}
PKGNAMEPREFIX=	npapi-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Embed Xine player into browser

LIB_DEPENDS=	libxine.so:${PORTSDIR}/multimedia/libxine

USES=		pkgconfig webplugin:native
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
WEBPLUGIN_NAME=	#
WEBPLUGIN_FILES=	xineplugin.so
PLIST_FILES=	${WEBPLUGIN_DIR}${WEBPLUGIN_FILES}

do-install:
	${MKDIR} ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_LIB} ${WRKSRC}/src/.libs/${WEBPLUGIN_FILES} ${STAGEDIR}${WEBPLUGIN_DIR}

.include <bsd.port.mk>
