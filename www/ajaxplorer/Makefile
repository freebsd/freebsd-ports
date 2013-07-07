# $FreeBSD$

PORTNAME=	ajaxplorer
PORTVERSION=	5.0.1
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
SUB_FILES=	pkg-deinstall pkg-install pkg-message

post-patch:
	@${RM} -f ${WRKSRC}/plugins/gui.ajax/res/themes/vision/images/mimes/16/._users-folder.png
	@${MV} ${WRKSRC}/conf/bootstrap_conf.php ${WRKDIR}/bootstrap_conf.php.sample
	@${MV} ${WRKSRC}/conf/bootstrap_context.php ${WRKDIR}/bootstrap_context.php.sample
	@${MV} ${WRKSRC}/conf/bootstrap_repositories.php ${WRKDIR}/bootstrap_repositories.php.sample

do-install:
	${MKDIR} ${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "* .htaccess" ${WWWDIR})
	${INSTALL_DATA} ${WRKDIR}/bootstrap_*.php.sample ${WWWDIR}/conf
	${INSTALL_DATA} ${FILESDIR}/4.2.3-5.0.0-db-upgrade.sql ${WWWDIR}/conf
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@if [ ! -f ${WWWDIR}/conf/bootstrap_conf.php ]; then \
		${CP} -p ${WWWDIR}/conf/bootstrap_conf.php.sample ${WWWDIR}/conf/bootstrap_conf.php ; \
	fi
	@if [ ! -f ${WWWDIR}/conf/bootstrap_context.php ]; then \
		${CP} -p ${WWWDIR}/conf/bootstrap_context.php.sample ${WWWDIR}/conf/bootstrap_context.php ; \
	fi
	@if [ ! -f ${WWWDIR}/conf/bootstrap_repositories.php ]; then \
		${CP} -p ${WWWDIR}/conf/bootstrap_repositories.php.sample ${WWWDIR}/conf/bootstrap_repositories.php ; \
	fi
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
