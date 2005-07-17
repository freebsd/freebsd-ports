# New ports collection makefile for:	UserManager
# Date created:				19 December 2004
# Whom:					Daniel Gerzo <danger@rulez.sk>
#
# $FreeBSD$
#

PORTNAME=	UserManager
PORTVERSION=	2.0
CATEGORIES=	www ftp
MASTER_SITES=	http://machiel.generaal.net/files/pureftpd/
DISTNAME=	ftp_v${PORTVERSION}

MAINTAINER=	danger@rulez.sk
COMMENT=	Easily create, change, or delete virtual PureFTPd users

WRKSRC=		${WRKDIR}/ftp

BROKEN_WITH_PHP=	5
USE_PHP=	mysql pcre posix session

NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${PREFIX}/www/data/UserManager
	@${CP} -Rp ${WRKSRC}/* ${PREFIX}/www/data/UserManager
	@${CHMOD} 666 ${PREFIX}/www/data/UserManager/config.php
	@${ECHO_CMD} ""

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
