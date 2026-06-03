PORTNAME=	suitecrm
PORTVERSION=	8.7
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://suitecrm.com/download/148/suite87/564667/
DISTNAME=	${PORTNAME}-8-7-1

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open source Customer Relationship Management (CRM) software solution
WWW=		https://suitercrm.com/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		php
USE_PHP=	curl ctype dom filter gd iconv imap intl ldap \
		mysqli pdo pdo_mysql posix session simplexml \
		soap sodium tokenizer xml mbstring xmlreader \
		xmlwriter zip zlib
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST=		${WRKDIR}/plist
CRMDIR=		www/suitecrm

SUB_FILES+=	pkg-message

do-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} -yxf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} -C ${WRKSRC}

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
