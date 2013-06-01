# $FreeBSD$

PORTNAME=	ajaxplorer
PORTVERSION=	4.2.3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/stable-channel/${PORTVERSION}
DISTNAME=	${PORTNAME}-core-${PORTVERSION}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Ajax web file management system

LICENSE=	AGPLv3

NO_BUILD=	yes
USE_PHP=	dom mcrypt gd
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.php
WANT_PHP_WEB=	yes
SUB_FILES=	pkg-deinstall pkg-message

do-install:
	${MKDIR} ${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "* .htaccess" ${WWWDIR})
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
