# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magento
PORTVERSION=	1.7.0.2
CATEGORIES=	www finance
MASTER_SITES=	http://www.magentocommerce.com/downloads/assets/${PORTVERSION}/

MAINTAINER=	mel@magemana.nl
COMMENT=	Feature-rich eCommerce platform

USE_PHP=	pdo_mysql hash gd iconv curl dom soap simplexml mcrypt mysql \
		ctype
WRKSRC=		${WRKDIR}/magento

OPTIONS_DEFINE=	MYSQL56
MYSQL56_DESC=	Add installer patch for MySQL 5.6 server

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL56}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-app__code__core__Mage__Install__Model__Installer__Db__Mysql4.php
.endif

.include <bsd.port.pre.mk>

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	MAGENTODIR=${MAGENTODIR}
WRITABLE=	var media app/etc/modules
EXECUTABLE=	cron.sh mage

MAGENTODIR?=	www/magento

pre-install:
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${MAGENTODIR}?g" >${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dirrm ${MAGENTODIR}?g" >> ${PLIST}
	@${ECHO} @dirrmtry ${MAGENTODIR} >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${PREFIX}/${MAGENTODIR}
.for _dir in ${WRITABLE}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${MAGENTODIR}/${_dir}
	@${FIND} ${PREFIX}/${MAGENTODIR}/${_dir} -exec ${CHMOD} u+w {} +
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${MAGENTODIR}/${_dir}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${FIND} ${PREFIX}/${MAGENTODIR}/${_dir} -exec ${CHMOD} u+w {} +' \
		>> ${TMPPLIST}
.endfor
.for _prog in ${EXECUTABLE}
	@${CHMOD} 555 ${PREFIX}/${MAGENTODIR}/${_prog}
	@${ECHO_CMD} '@exec ${CHMOD} 555 ${PREFIX}/${MAGENTODIR}/${_prog}' >> ${PLIST}
.endfor
	@${CHMOD} 777 ${PREFIX}/${MAGENTODIR}/app/etc
	@${ECHO_CMD} '@exec ${CMMOD} 777 ${PREFIX}/${MAGENTODIR}/${_prog}' >> ${PLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
