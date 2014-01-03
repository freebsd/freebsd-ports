# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mahara
PORTVERSION=	1.1.8
CATEGORIES=	www
MASTER_SITES=	http://launchpad.net/${PORTNAME}/1.1/${PORTVERSION}/+download/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	An open source ePortfolio system

USE_BZIP2=	yes
USE_PHP=	session json curl xml xmlrpc openssl simplexml

OPTIONS_DEFINE=	MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	MAHARADIR=${MAHARADIR} \
		MAHARADATADIR=${MAHARADATADIR}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/htdocs

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

.include <bsd.port.mk>
