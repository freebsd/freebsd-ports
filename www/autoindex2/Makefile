# New ports collection makefile for:	AutoIndex
# Date created:				17 December 2004
# Whom:					Daniel Gerzo <danger@rulez.sk>
#
# $FreeBSD$
#

PORTNAME=	AutoIndex
PORTVERSION=	2.1.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	autoindex

MAINTAINER=	danger@rulez.sk
COMMENT=	PHP 5.x script that makes a table that lists the files in a directory

WRKSRC=		${WRKDIR}/${PORTNAME}

LATEST_LINK=	autoindex2

USE_PHP=	yes
DEFAULT_PHP_VER=	5
BROKEN_WITH_PHP=	4
CONFLICTS=	AutoIndex-1*

NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}/classes
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}/index_icons
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}/index_icons/apache
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}/index_icons/kde
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}/index_icons/osx
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}/index_icons/winxp
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}/languages
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}/templates
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}/templates/default
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}/templates/simple_image_gallery
	${INSTALL_DATA} ${WRKSRC}/.htpasswd.autoindex ${PREFIX}/www/data/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.php ${PREFIX}/www/data/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/hidden_files ${PREFIX}/www/data/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/www/data/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/classes/* ${PREFIX}/www/data/${PORTNAME}/classes
	${INSTALL_DATA} ${WRKSRC}/index_icons/apache/* ${PREFIX}/www/data/${PORTNAME}/index_icons/apache
	${INSTALL_DATA} ${WRKSRC}/index_icons/kde/* ${PREFIX}/www/data/${PORTNAME}/index_icons/kde
	${INSTALL_DATA} ${WRKSRC}/index_icons/osx/* ${PREFIX}/www/data/${PORTNAME}/index_icons/osx
	${INSTALL_DATA} ${WRKSRC}/index_icons/winxp/* ${PREFIX}/www/data/${PORTNAME}/index_icons/winxp
	${INSTALL_DATA} ${WRKSRC}/languages/*  ${PREFIX}/www/data/${PORTNAME}/languages
	${INSTALL_DATA} ${WRKSRC}/templates/readme.html ${PREFIX}/www/data/${PORTNAME}/templates
	${INSTALL_DATA} ${WRKSRC}/templates/default/* ${PREFIX}/www/data/${PORTNAME}/templates/default
	${INSTALL_DATA} ${WRKSRC}/templates/simple_image_gallery/* ${PREFIX}/www/data/${PORTNAME}/templates/simple_image_gallery
	@${ECHO_CMD} ""

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
