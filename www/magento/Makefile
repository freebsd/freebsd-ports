# New ports collection makefile for:	magento
# Date created:				1st March, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	magento
PORTVERSION=	1.6.1.0
CATEGORIES=	www finance
MASTER_SITES=	LOCAL/wen

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A feature-rich eCommerce platform

USE_BZIP2=	yes
USE_PHP=	pdo_mysql hash gd iconv curl dom soap simplexml mcrypt mysql
WRKSRC=		${WRKDIR}/magento

.include <bsd.port.pre.mk>

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	MAGENTODIR=${MAGENTODIR}

MAGENTODIR?=	www/magento

pre-install:
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${MAGENTODIR}?g" >${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dirrm ${MAGENTODIR}?g" >> ${PLIST}
	@${ECHO} @dirrmtry ${MAGENTODIR} >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${PREFIX}/${MAGENTODIR}

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${MAGENTODIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${MAGENTODIR}' \
		>> ${TMPPLIST}
	${CHMOD} -R 755 ${PREFIX}/${MAGENTODIR}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${PREFIX}/${MAGENTODIR}' >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
