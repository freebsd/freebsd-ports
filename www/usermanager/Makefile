# New ports collection makefile for:	UserManager
# Date created:				19 December 2004
# Whom:					DanGer <danger@wilbury.sk>
#
# $FreeBSD$
#

PORTNAME=	UserManager
PORTVERSION=	1.4.0
CATEGORIES=	www
MASTER_SITES=	http://machiel.generaal.net/files/pureftpd/
DISTNAME=	ftp_v${PORTVERSION}

MAINTAINER=	danger@wilbury.sk
COMMENT=	Easily create, change, or delete virtual PureFTPd users

WRKSRC=		${WRKDIR}/ftp

BROKEN_WITH_PHP=	5
USE_PHP=	mysql

NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${PREFIX}/www/data/UserManager
	@${MKDIR} ${PREFIX}/www/data/UserManager/images
	@${MKDIR} ${PREFIX}/www/data/UserManager/language
	@${MKDIR} ${PREFIX}/www/data/UserManager/style
	${INSTALL_DATA} ${WRKSRC}/script.mysql ${PREFIX}/www/data/UserManager
	${INSTALL_DATA} ${WRKSRC}/*.php ${PREFIX}/www/data/UserManager
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/www/data/UserManager
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${PREFIX}/www/data/UserManager
	${INSTALL_DATA} ${WRKSRC}/images/* ${PREFIX}/www/data/UserManager/images
	${INSTALL_DATA} ${WRKSRC}/language/* ${PREFIX}/www/data/UserManager/language
	${INSTALL_DATA} ${WRKSRC}/style/*  ${PREFIX}/www/data/UserManager/style
	@${ECHO_CMD} ""

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
