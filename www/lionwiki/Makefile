# New ports collection makefile for:	lionwiki
# Date created:		2009-10-07
# Whom:			Sylvio Cesar <sylvio@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lionwiki
PORTVERSION=	3.1.1
CATEGORIES=	www
MASTER_SITES=	http://lionwiki.0o.cz/download/${PORTVERSION}/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Minimalis wiki, extensible, templatable and file based

USE_BZIP2=	yes
USE_PHP=	session ctype

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
ROOTFILES=	config.php index.php
ROOTDIRS=	lang plugins templates var
SUB_FILES=	pkg-message

post-patch:
	@(cd ${WRKSRC} && ${MV} config.php config.php.sample)

do-install:
	@${MKDIR} ${WWWDIR}
	@${INSTALL_DATA} ${WRKSRC}/config.php.sample ${WWWDIR}/
	@if [ ! -f ${WWWDIR}/config.php ]; then \
		${CP} -p ${WWWDIR}/config.php.sample ${WWWDIR}/config.php; \
	fi
	@${INSTALL_DATA} ${WRKSRC}/index.php ${WWWDIR}/
.for dirs in ${ROOTDIRS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${dirs} ${WWWDIR}/ )
.endfor
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}
.include <bsd.port.mk>
