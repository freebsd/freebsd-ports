PORTNAME=	suitecrm
PORTVERSION=	7.14.3
CATEGORIES=	www
MASTER_SITES=	https://suitecrm.com/download/141/suite714/563700/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open source Customer Relationship Management (CRM) software solution
WWW=		https://suitercrm.com/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		php
USE_PHP=	curl ctype dom filter gd imap mysqli pdo posix \
		session tokenizer xml mbstring zip zlib
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/SuiteCRM-${PORTVERSION}

PLIST=		${WRKDIR}/plist
CRMDIR=		www/suitecrm

SUB_FILES+=	pkg-message

pre-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${PLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${PLIST}
	@${ECHO_CMD} "@mode 755" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${CRMDIR}?g" >>${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dir ${CRMDIR}?g" >> ${PLIST}
	@${ECHO_CMD} "@mode" >> ${PLIST}
	@${ECHO_CMD} "@group" >> ${PLIST}
	@${ECHO_CMD} "@owner" >> ${PLIST}

do-install:
	@${MKDIR} ${STAGEDIR}/${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/

.include <bsd.port.mk>
