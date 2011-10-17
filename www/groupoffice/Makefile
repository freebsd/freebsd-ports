# New ports collection makefile for:	www/groupoffice
# Date created:							16 February 2007
# Whom:					Aron Schlesinger <as@bsdgroup.de>
#
# $FreeBSD$

PORTNAME=	groupoffice
DISTVERSIONPREFIX=	com-
DISTVERSION=	3.7.24
CATEGORIES=	www
MASTER_SITES=	SF/group-office/3.7

MAINTAINER=	as@bsdgroup.de
COMMENT=	A modular web application framework vor office

RESTRICTED=	Free for personal use only
NO_BUILD=	yes
USE_PHP=	mysql session mbstring pcre xml
WANT_PHP_WEB=	yes
USE_MYSQL=	yes

WWWDIR?=	${PREFIX}/www/${PORTNAME}3

SUB_FILES=	pkg-message

OPTIONS=	IMAP		"IMAP support" on \
		GD		"Gallery support (GD)" on \
		CALENDAR	"Calendar holiday support" on \
		WBXML		"Synchronization support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_IMAP)
USE_PHP+=	imap iconv
.endif

.if !defined(WITHOUT_GD)
USE_PHP+=	gd
.endif

.if !defined(WITHOUT_CALENDAR)
USE_PHP+=	calendar
.endif

.if !defined(WITHOUT_WBXML)
LIB_DEPENDS=	wbxml2:${PORTSDIR}/textproc/wbxml2
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
