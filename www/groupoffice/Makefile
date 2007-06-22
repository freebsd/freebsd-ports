# New ports collection makefile for:	www/groupoffice
# Date created:							16 February 2007
# Whom:					Aron Schlesinger <as@bsdgroup.de>
#
# $FreeBSD$

PORTNAME=	groupoffice
DISTVERSIONPREFIX=	com-
DISTVERSION=	2.17-stable-6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	group-office

MAINTAINER=	as@bsdgroup.de
COMMENT=	A modular web application framework vor office

RESTRICTED=	Free for personal use only
NO_BUILD=	yes
USE_PHP=	mysql session mbstring pcre xml
WANT_PHP_WEB=	yes
USE_MYSQL=	yes
IGNORE_WITH_MYSQL=	323

WWWDIR?=	${PREFIX}/www/${PORTNAME}2

SUB_FILES=	pkg-message

OPTIONS=	IMAP	"IMAP support" on \
		GD	"Gallery support (GD)" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_IMAP)
USE_PHP+=	imap iconv
.endif

.if !defined(WITHOUT_GD)
USE_PHP+=	gd
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/ ${WWWDIR}
	@${TOUCH} ${WWWDIR}/config.php
	@${CHOWN} ${WWWOWN} ${WWWDIR}/config.php
	@${CAT} ${PKGMESSAGE}

create-plist:
	@${FIND} -s ${WRKSRC}/${file} -not -type d \
	    | ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}
	@${ECHO_CMD} '@exec touch %D/%%WWWDIR%%/config.php;chown ${WWWOWN} %D/%%WWWDIR%%/config.php' >> ${PLIST}
	@${ECHO_CMD} '@unexec if [ ! -s %D/%%WWWDIR%%/config.php ];then rm -f %D/%%WWWDIR%%/config.php;fi' >> ${PLIST}
	@${FIND} -ds ${WRKSRC}/${file} -type d \
	    | ${SED} -e 's,^${WRKSRC},@dirrm %%WWWDIR%%,' >> ${PLIST}

.include <bsd.port.post.mk>
