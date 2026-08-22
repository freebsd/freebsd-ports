PORTNAME=	elgg
PORTVERSION=	7.0.5
CATEGORIES=	www
MASTER_SITES=	http://elgg.org/download/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Blogging and social networking platform
WWW=		https://www.elgg.org/

LICENSE=	GPLv2

USES=		cpe gettext shebangfix zip php
USE_PHP=	curl dom fileinfo filter gd intl \
		mbstring pdo_mysql \
		session simplexml soap sqlite3 xml xmlrpc
IGNORE_WITH_PHP=	86

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message

ELGGDIR=	www/elgg
ELGGDATADIR=	${WWWDIR}/data

pre-install:
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${ELGGDIR}?g" >>${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dir ${ELGGDIR}?g" >> ${PLIST}

	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${PLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${PLIST}
	@${ECHO_CMD} "@mode 755" >> ${PLIST}
	@${ECHO} @dir ${ELGGDATADIR} >> ${PLIST}
	@${ECHO_CMD} "@mode" >> ${PLIST}
	@${ECHO_CMD} "@group" >> ${PLIST}
	@${ECHO_CMD} "@owner" >> ${PLIST}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

	@${INSTALL} -d ${STAGEDIR}${ELGGDATADIR}
	@${CHMOD} 755 ${STAGEDIR}${ELGGDATADIR}
	@${CHMOD} 755 ${STAGEDIR}${WWWDIR}/elgg-config

.include <bsd.port.mk>
