PORTNAME=	xine
PORTVERSION=	1.0.2
PORTREVISION=	13
DISTVERSIONPREFIX=	plugin-
CATEGORIES=	www multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-plugin/${PORTVERSION}
PKGNAMEPREFIX=	npapi-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embed Xine player into browser

BROKEN_aarch64=		fails to build: ../include/prcpucfg.h:604:2: Unknown CPU architecture

LIB_DEPENDS=	libxine.so:multimedia/libxine

USES=		pkgconfig webplugin:native tar:bzip2
GNU_CONFIGURE=	yes
WEBPLUGIN_NAME=	#
WEBPLUGIN_FILES=	xineplugin.so
PLIST_FILES=	${WEBPLUGIN_DIR}${WEBPLUGIN_FILES}

do-install:
	${MKDIR} ${STAGEDIR}${WEBPLUGIN_DIR}
	${INSTALL_LIB} ${WRKSRC}/src/.libs/${WEBPLUGIN_FILES} ${STAGEDIR}${WEBPLUGIN_DIR}

.include <bsd.port.mk>
