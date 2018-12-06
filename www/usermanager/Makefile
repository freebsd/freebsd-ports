# Created by: Daniel Gerzo <danger@FreeBSD.org>
# $FreeBSD$

PORTNAME=	UserManager
PORTVERSION=	2.1
CATEGORIES=	www ftp
MASTER_SITES=	http://machiel.generaal.net/files/pureftpd/
DISTNAME=	ftp_v${PORTVERSION}

MAINTAINER=	danger@FreeBSD.org
COMMENT=	Easily create, change, or delete virtual PureFTPd users

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

IGNORE_WITH_PHP=	71 72 73

WRKSRC=		${WRKDIR}/ftp

USES=		php
USE_PHP=	mysql pcre posix session

NO_BUILD=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB+=	INSTALLDIR=${INSTALLDIR}

_INSTDIR=	www/data/UserManager
INSTALLDIR?=	${_INSTDIR}

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
	@${MKDIR} ${STAGEDIR}${PREFIX}/${INSTALLDIR}
	@${CP} -Rp ${WRKSRC}/* ${STAGEDIR}${PREFIX}/${INSTALLDIR}
	@${CHMOD} 666 ${STAGEDIR}${PREFIX}/${INSTALLDIR}/config.php
	@${MV} ${STAGEDIR}${PREFIX}/${INSTALLDIR}/config.php \
		${STAGEDIR}${PREFIX}/${INSTALLDIR}/config.php.sample

.include <bsd.port.mk>
