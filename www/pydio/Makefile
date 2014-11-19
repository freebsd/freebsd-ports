# $FreeBSD$

PORTNAME=	pydio
PORTVERSION=	5.2.5
CATEGORIES=	www
MASTER_SITES=	SF/ajaxplorer/${PORTNAME}/stable-channel/${PORTVERSION}
DISTNAME=	${PORTNAME}-core-${PORTVERSION}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Ajax web file management system

LICENSE=	AGPLv3

PORTSCOUT=	limitw:1,even

NO_BUILD=	yes
NO_ARCH=	yes
USES=		dos2unix shebangfix
php_OLD_CMD=	/php
SHEBANG_FILES=	plugins/core.mq/ws-server.php \
		plugins/core.mq/vendor/phpws/demo_ssl.php \
		plugins/core.mq/vendor/phpws/demo.php
USE_PHP=	dom mcrypt gd
DOS2UNIX_REGEX=	.*\.php
WANT_PHP_WEB=	yes
SUB_FILES=	pkg-deinstall pkg-message
SUB_LIST+=	GOWDIR=${WWWDIR:H}

post-patch:
	@${RM} -f ${WRKSRC}/plugins/gui.ajax/res/themes/vision/images/mimes/16/._users-folder.png
	@${MV} ${WRKSRC}/conf/bootstrap_conf.php ${WRKDIR}/bootstrap_conf.php.sample
	@${MV} ${WRKSRC}/conf/bootstrap_context.php ${WRKDIR}/bootstrap_context.php.sample
	@${MV} ${WRKSRC}/conf/bootstrap_repositories.php ${WRKDIR}/bootstrap_repositories.php.sample

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "* .htaccess" ${STAGEDIR}${WWWDIR})
	${INSTALL_DATA} ${WRKDIR}/bootstrap_*.php.sample ${STAGEDIR}${WWWDIR}/conf

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}

.include <bsd.port.mk>
