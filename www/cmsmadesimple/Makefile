# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	cmsmadesimple
PORTVERSION=	1.9.1
CATEGORIES=	www
MASTER_SITES=	http://s3.amazonaws.com/cmsms/downloads/6491/
DISTNAME=	${PORTNAME}-${PORTVERSION}-full

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A Simple Open Source CMS

USE_PHP=	mysql tokenizer gd
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}
CMS_DIRS=	admin doc images install lib \
		modules plugins tmp uploads
CMS_FILES=	favicon_cms.ico fileloc.php include.php \
		index.php moduleinterface.php \
		soap.php stylesheet.css \
		stylesheet.php version.php
WRITABLE_DIRS=	tmp tmp/templates_c tmp/cache \
		uploads uploads/images modules

NO_STAGE=	yes
.include <bsd.port.pre.mk>
post-extract:
	@cd ${WRKSRC} && ${RM} -f config.php

do-install:
.for i in ${CMS_DIRS}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${WWWDIR}
.endfor
.for i in ${CMS_FILES}
	@cd ${WRKSRC} && ${CP} ${i} ${WWWDIR}/${i}
.endfor
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}

	@if [ ! -f ${WWWDIR}/config.php ]; then \
	${TOUCH} ${WWWDIR}/config.php ; fi

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' \
		>> ${TMPPLIST}

.for i in ${WRITABLE_DIRS}
	@${CHMOD} 775 ${WWWDIR}/${i}
	@${ECHO_CMD} '@exec ${CHMOD} 775 ${WWWDIR}/${i}' \
		>> ${TMPPLIST}
.endfor

	@${CHMOD} 666 ${WWWDIR}/config.php
	@${ECHO_CMD} '@exec ${CHMOD} 666 ${WWWDIR}/config.php' \
		>> ${TMPPLIST}

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
