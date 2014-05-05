# Created by: chinsan@mail2000.com.tw
# $FreeBSD$

PORTNAME=	bBlog
PORTVERSION=	0.7.6
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A elegant personal publishing system with Smarty

USE_PHP=	mysql pcre session
NO_BUILD=	YES
WANT_PHP_WEB=	YES

WRKSRC=		${WRKDIR}/${PORTNAME:tl}
WWWDOCROOT?=	www
BBLOGURL?=	${PORTNAME:tl}
BBLOGDIR?=	${WWWDOCROOT}/${BBLOGURL}

SUB_FILES=	pkg-message
SUB_LIST=	BBLOGURL=${BBLOGURL} BBLOGDIR=${BBLOGDIR}
PLIST_SUB=	WWWDOCROOT=${WWWDOCROOT} BBLOGURL=${BBLOGURL}

OPTIONS_DEFINE=	GD IMAGICK
OPTIONS_DEFAULT=GD
IMAGICK_DESC=	${IMAGEMAGICK_DESC}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGD}
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/gd.so:${PORTSDIR}/${gd_DEPENDS}
.endif

.if ${PORT_OPTIONS:MIMAGICK}
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/imagick.so:${PORTSDIR}/${imagick_DEPENDS}
.endif

.if empty(PORT_OPTIONS:MGD) && empty(PORT_OPTIONS:MIMAGICK)
pre-patch:
	@${ECHO_CMD} "Without GD or ImageMagick support. No thumbnails will be generated at all."
.endif

do-install:
	@${MKDIR} ${PREFIX}/${BBLOGDIR}/${PORTNAME:tl}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${BBLOGDIR}
	@${CHGRP} -R ${WWWGRP} ${PREFIX}/${BBLOGDIR}
	@${CHMOD} 755 ${PREFIX}/${BBLOGDIR}
.for f in archives.php documentation.txt htaccess-cleanurls index.php item rss.php search.php section
	${INSTALL_DATA} ${WRKDIR}/${f} ${PREFIX}/${BBLOGDIR}
.endfor
	@${CP} -Rv ${WRKSRC}/* ${PREFIX}/${BBLOGDIR}/${PORTNAME:tl}
	@${CHMOD} 775 ${PREFIX}/${BBLOGDIR}/${PORTNAME:tl}/compiled_templates/
	@${CHMOD} 775 ${PREFIX}/${BBLOGDIR}/${PORTNAME:tl}/cache/
	@${CHMOD} 775 ${PREFIX}/${BBLOGDIR}/${PORTNAME:tl}/cache/favorites.xml
	@${CHMOD} 775 ${PREFIX}/${BBLOGDIR}/${PORTNAME:tl}/config.php

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
