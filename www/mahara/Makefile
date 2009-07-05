# New ports collection makefile for:	mahara
# Date created:				21 Feb, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mahara
PORTVERSION=	1.1.5
CATEGORIES=	www
MASTER_SITES=	http://eduforge.org/frs/download.php/994/

MAINTAINER=	wenheping@gmail.com
COMMENT=	An open source ePortfolio system

USE_PHP=	session json curl xml xmlrpc openssl simplexml

OPTIONS=	MYSQL   "Add support for a MySQL database server" On \
		PGSQL   "Add support for a PostgreSQL database server" Off

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	MAHARADIR=${MAHARADIR} \
		MAHARADATADIR=${MAHARADATADIR}
WRKSRC=		${WRKDIR}/htdocs

MAHARADIR?=	www/mahara
MAHARADATADIR?=	www/maharadata

pre-install:
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${MAHARADIR}?g" >${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dirrm ${MAHARADIR}?g" >> ${PLIST}
	@${ECHO} @dirrm ${MAHARADATADIR} >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${INSTALL} -d ${PREFIX}/${MAHARADATADIR}

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}
	@${CHMOD} -R 755 ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' >> ${TMPPLIST}

	@${CHMOD} -R a+w ${PREFIX}/${MAHARADATADIR}
	@${ECHO_CMD} '@exec ${CHMOD} -R a+w ${PREFIX}/${MAHARADATADIR}' >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
