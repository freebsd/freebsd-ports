# New ports collection makefile for:	flashplugin-firefox
# Date created:				16.07.2004
# Whom:					Roman Y. Bogdanov <sam@brj.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	flashplugin-firefox
PORTVERSION=	0.4.12
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gplflash
DISTNAME=	gplflash-${PORTVERSION}

MAINTAINER=	sam@brj.pp.ru
COMMENT=	A GPL standalone Flash (TM) plugin for FireFox web browser

LIB_DEPENDS=	flash.0:${PORTSDIR}/graphics/libflash
RUN_DEPENDS?=	firefox:${PORTSDIR}/www/firefox

WRKSRC=		${WRKDIR}/${DISTNAME}/plugin

USE_BZIP2=	yes
USE_X_PREFIX=	yes
PLUGIN_DIR?=	lib/firefox/plugins
PLIST_SUB+=	PLUGIN_DIR=${PLUGIN_DIR}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -shared -fPIC -DXP_UNIX \
	    -I${.CURDIR}../lib -I${LOCALBASE}/include -I${X11BASE}/include \
	    -o npflash.so plugin.c npunix.c \
	    -L${LOCALBASE}/lib -L${X11BASE}/lib -lflash -lXt

do-install:
	@${MKDIR} ${PREFIX}/${PLUGIN_DIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/npflash.so ${PREFIX}/${PLUGIN_DIR}

.include <bsd.port.mk>
