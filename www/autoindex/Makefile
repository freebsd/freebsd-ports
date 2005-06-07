# New ports collection makefile for:	AutoIndex
# Date created:				17 December 2004
# Whom:					Daniel Gerzo <danger@rulez.sk>
#
# $FreeBSD$
#

PORTNAME=	AutoIndex
PORTVERSION=	1.5.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	autoindex

MAINTAINER=	danger@rulez.sk
COMMENT=	PHP 4.x script that makes a table that lists the files in a directory

WRKSRC=		${WRKDIR}/${PORTNAME}

BROKEN_WITH_PHP=	5
USE_PHP=	yes
CONFLICTS=	AutoIndex-2*

NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}/index_icons
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}/index_icons/apache
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}/index_icons/kde
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}/index_icons/osx
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}/index_icons/winxp
	@${MKDIR} ${PREFIX}/www/data/${PORTNAME}/languages
	${INSTALL_DATA} ${WRKSRC}/.htpasswd.autoindex ${PREFIX}/www/data/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.php ${PREFIX}/www/data/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/www/data/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/stylesheet.css ${PREFIX}/www/data/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/index_icons/apache/* ${PREFIX}/www/data/${PORTNAME}/index_icons/apache
	${INSTALL_DATA} ${WRKSRC}/index_icons/kde/* ${PREFIX}/www/data/${PORTNAME}/index_icons/kde
	${INSTALL_DATA} ${WRKSRC}/index_icons/osx/* ${PREFIX}/www/data/${PORTNAME}/index_icons/osx
	${INSTALL_DATA} ${WRKSRC}/index_icons/winxp/* ${PREFIX}/www/data/${PORTNAME}/index_icons/winxp
	${INSTALL_DATA} ${WRKSRC}/languages/*  ${PREFIX}/www/data/${PORTNAME}/languages
	@${ECHO_CMD} ""

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
