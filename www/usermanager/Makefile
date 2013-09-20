# Created by: Daniel Gerzo <danger@FreeBSD.org>
# $FreeBSD$

PORTNAME=	UserManager
PORTVERSION=	2.1
CATEGORIES=	www ftp
MASTER_SITES=	http://machiel.generaal.net/files/pureftpd/
DISTNAME=	ftp_v${PORTVERSION}

MAINTAINER=	danger@FreeBSD.org
COMMENT=	Easily create, change, or delete virtual PureFTPd users

WRKSRC=		${WRKDIR}/ftp

USE_PHP=	mysql pcre posix session

NO_BUILD=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB+=	INSTALLDIR=${INSTALLDIR}

_INSTDIR=	www/data/UserManager
INSTALLDIR?=	${_INSTDIR}

NO_STAGE=	yes
pre-fetch:
.if ${INSTALLDIR} == ${_INSTDIR}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define INSTALLDIR to override default of '${_INSTDIR}'."
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
