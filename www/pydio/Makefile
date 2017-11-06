# $FreeBSD$

PORTNAME=	pydio
PORTVERSION=	8.0.1
CATEGORIES=	www
MASTER_SITES=	https://download.pydio.com/pub/core/archives/
DISTNAME=	${PORTNAME}-core-${PORTVERSION}

MAINTAINER=	net@arrishq.net
COMMENT=	Ajax web file management system

LICENSE=	AGPLv3

PORTSCOUT=	limitw:1,even

NO_BUILD=	yes
NO_ARCH=	yes
USES=		cpe dos2unix php:web
USE_PHP=	dom mcrypt gd
DOS2UNIX_REGEX=	.*\.php
SUB_FILES=	pkg-deinstall pkg-message
SUB_LIST+=	GOWDIR=${WWWDIR:H}

post-patch:
	@${MV} ${WRKSRC}/conf/bootstrap_conf.php ${WRKDIR}/bootstrap_conf.php.sample
	@${MV} ${WRKSRC}/conf/bootstrap_context.php ${WRKDIR}/bootstrap_context.php.sample
	@${MV} ${WRKSRC}/conf/bootstrap_repositories.php ${WRKDIR}/bootstrap_repositories.php.sample
	# Remove unneeded sample file for IIS
	@${RM} ${WRKSRC}/web.config.sample
	@${RM} ${WRKSRC}/data/web.config

	# Remove dead symlinks shipped in upstream
	@${RM} ${WRKSRC}/plugins/gui.ajax/res/mui/less
	@${RM} ${WRKSRC}/plugins/gui.ajax/res/themes/common/css/mui/less

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "* .htaccess" ${STAGEDIR}${WWWDIR})
	${INSTALL_DATA} ${WRKDIR}/bootstrap_*.php.sample ${STAGEDIR}${WWWDIR}/conf

post-install:
	@${ECHO_CMD} '@postexec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}

.include <bsd.port.mk>
