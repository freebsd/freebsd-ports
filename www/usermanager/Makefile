# New ports collection makefile for:	UserManager
# Date created:				19 December 2004
# Whom:					Daniel Gerzo <danger@rulez.sk>
#
# $FreeBSD$
#

PORTNAME=	UserManager
PORTVERSION=	2.1
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
PLIST_SUB+=	INSTALLDIR=${INSTALLDIR}
INSTALLDIR?=	www/data/UserManager

pre-fetch:
.if !defined(INSTALLDIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define INSTALLDIR to override default of 'www/data/UserManager'."
	@${ECHO_MSG} ""
.endif

post-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
	 -e 's|%%INSTALLDIR%%|${INSTALLDIR}|g' ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${PREFIX}/${INSTALLDIR}
	@${CP} -Rp ${WRKSRC}/* ${PREFIX}/${INSTALLDIR}
	@${CHMOD} 666 ${PREFIX}/${INSTALLDIR}/config.php
	@${ECHO_CMD} ""

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
