# New ports collection makefile for:	flashplugin-mozilla
# Date created:				25 October 2001
# Whom:					Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME?=	flashplugin-mozilla
PORTVERSION=	0.4.12
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gplflash
DISTNAME=	gplflash-${PORTVERSION}

MAINTAINER=	llwang@infor.org
COMMENT=	A GPL standalone Flash (TM) plugin for Mozilla web browser

LIB_DEPENDS=	flash.0:${PORTSDIR}/graphics/libflash
RUN_DEPENDS?=	mozilla:${PORTSDIR}/www/mozilla

WRKSRC=		${WRKDIR}/${DISTNAME}/plugin

USE_BZIP2=	yes
USE_X_PREFIX=	yes
PLUGIN_DIR?=	lib/browser_plugins
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
