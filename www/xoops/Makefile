# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	xoops
PORTVERSION=	2.5.6
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/XOOPS%20Core%20%28stable%20releases%29/XOOPS_${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A Dynamic Web CMS

USE_PHP=	mysql

NO_BUILD=	yes
SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${WWWDIR}
.for i in checksum.md5 checksum.php
	@cd ${WRKSRC} && ${CP} ${i} ${WWWDIR}/
.endfor
.for d in docs extras htdocs
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${WWWDIR}
.endfor
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' \
		>> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
