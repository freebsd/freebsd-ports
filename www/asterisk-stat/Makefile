# Created by: Fumihiko Kimura <jfkimura@yahoo.com>
# $FreeBSD$

PORTNAME=	asterisk-stat
PORTVERSION=	2.0.1
PORTREVISION=	15
CATEGORIES=	www
MASTER_SITES=	http://ftp.iij.ad.jp/pub/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}-v${PORTVERSION:S/./_/g}

MAINTAINER=	jfkimura@yahoo.co.jp
COMMENT=	ASTERISK call detail records analyzer

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libgd.so:graphics/gd

NO_BUILD=	yes
USE_PHP=	session gd pcre
WANT_PHP_WEB=	yes
ASTERISKDIR?=	${WWWDIR}
SITE_SUBDIR=	asterisk-stat-v2
WRKSRC=		${WRKDIR}/${SITE_SUBDIR}
SUB_FILES=	pkg-message
SUB_LIST+=	ASTERISKDIR=${ASTERISKDIR}

OPTIONS_DEFINE=	PGSQL
PGSQL_DESC=	Use PostgreSQL instead of MySQL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPGSQL}
ASTERISKSTATDB=	pgsql
EXTRA_PATCHES+=	${FILESDIR}/pgsql__patch-call.log.php
.else
ASTERISKSTATDB=	mysql
.endif

USE_PHP+=	${ASTERISKSTATDB}
EXTRA_PATCHES+=	${FILESDIR}/${ASTERISKSTATDB}__patch-cdr.php \
		${FILESDIR}/${ASTERISKSTATDB}__patch-defines.php
PLIST_SUB+=	ASTERISKDIR=${ASTERISKDIR:S,^${PREFIX}/,,} \
		ASTERISKSTATDB=${ASTERISKSTATDB} \
		WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

post-patch:
	@${MV} ${WRKSRC}/images/print.css ${WRKSRC}/css
	@${CP} ${WRKSRC}/images/spacer.gif ${WRKSRC}/images/clear.gif
	@${CP} ${WRKSRC}/css/images/*png ${WRKSRC}/images
	@${RM} ${WRKSRC}/about.php \
		${WRKSRC}/lib/defines.php.orig \
		${WRKSRC}/cdr.php.orig \
		${WRKSRC}/export_pdf.php.orig

do-install:
	@${MKDIR} ${STAGEDIR}${ASTERISKDIR}
	@${MV} ${WRKSRC}/lib/defines.php ${WRKSRC}/lib/defines.php-dist
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${ASTERISKDIR})
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/asterisk
	${INSTALL_DATA} ${FILESDIR}/cdr_${ASTERISKSTATDB}.tbl ${STAGEDIR}${PREFIX}/etc/asterisk

.include <bsd.port.mk>
