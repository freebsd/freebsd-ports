# New ports collection makefile for:	flashplugin-firefox
# Date created:				16.07.2004
# Whom:					Roman Y. Bogdanov <sam@brj.pp.ru>
#
# $FreeBSD$
#

PORTNAME?=	flashplugin-firefox
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
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
PLUGIN_DIR?=	lib/firefox/plugins
PLIST_SUB+=	PLUGIN_DIR=${PLUGIN_DIR}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-plugin-dir="${PREFIX}/${PLUGIN_DIR}"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"	\
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_WRKSRC=	${WRKDIR}/${DISTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s,-L../lib/.libs,-L${LOCALBASE}/lib,"	\
		-e "s/libnpflash.so.0.0.0/libnpflash.so.0/"	\
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
