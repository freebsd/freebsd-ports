# New ports collection makefile for:   tasks
# Date created:                25 Mar 2004
# Whom:                        Sebastien Gioria <gioria@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	tasks
PORTVERSION=	1.8.6
CATEGORIES=	www
MASTER_SITES=	http://www.alexking.org/software/tasks/download/
DISTNAME=	tasks

MAINTAINER=	gioria@FreeBSD.org
COMMENT=	A web based, hierarchical task manager

BROKEN=		Unfetchable
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22
RESTRICTED=	No redistribution or repackaging allowed

USE_APACHE=	yes
USE_MYSQL=	yes
USE_PHP=	yes
USE_ZIP=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
WWW_DIR=	${PREFIX}/www/data
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

do-build:
	@${SED} 's|%%WWW_DIR%%|${WWW_DIR}|g' ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

do-install:
	${MKDIR} ${WWW_DIR}/tasks
	${CP} -R ${WRKSRC}/* ${WWW_DIR}/tasks
	${CHOWN} -R www:www ${WWW_DIR}/tasks
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
