# Created by: Beech Rintoul <beech@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zen-cart
PORTVERSION=	1.3.9h
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.akherb.com/FreeBSD/source/ \
		LOCAL/beech
DISTNAME=	zen-cart-v1.3.9h-full-fileset-10262010

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP-based user-friendly, open source shopping cart

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt
USES=		zip
USE_PHP=	yes
WANT_PHP_WEB=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.php

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	WWWDIR="${WWWDIR}" PORTNAME="${PORTNAME}"
PLIST_SUB+=	WWWDIR=${WWWDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} EXAMPLESDIR_REL=${EXAMPLESDIR_REL} \
			PORTNAME=${PORTNAME}

NO_STAGE=	yes
do-install:
	@if [ ! -d ${WWWDIR} ]; then mkdir ${WWWDIR} ; fi
	@cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${EXAMPLESDIR} && rm -rf ${WRKSRC}/docs
	@cd ${WRKSRC} && mv vbv_learn_more.html ${EXAMPLESDIR}/
	@cd ${WRKSRC} && mv mcs_learn_more.html ${EXAMPLESDIR}/
	@cd ${WRKSRC} && mv robots_example.txt ${EXAMPLESDIR}/
	@cd ${WRKSRC} && mv install.txt ${EXAMPLESDIR}/
	@cd ${WRKSRC} && mv nddbc.html ${EXAMPLESDIR}/
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 0755 ${WWWDIR}
	@${CHMOD} 0777 ${WWWDIR}/cache
	@cd ${WWWDIR}/images && find . -type d -exec chmod 0777 {} \;
	@cd ${WWWDIR}/includes/languages/english && find html_includes -type d -exec chmod 0777 {} \;
	@${CHMOD} 0777 ${WWWDIR}/media
	@${CHMOD} 0777 ${WWWDIR}/pub
	@${CHMOD} 0777 ${WWWDIR}/admin/backups
	@${CHMOD} 0777 ${WWWDIR}/admin/images/graphs
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 0755 ${WWWDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 0777 ${WWWDIR}/cache' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec cd ${WWWDIR}/images && find . -type d -exec chmod 0777 {} \;' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec cd ${WWWDIR}/includes/languages/english && find html_includes -type d -exec chmod 0777 {} \;' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 0777 ${WWWDIR}/media' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 0777 ${WWWDIR}/pub' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 0777 ${WWWDIR}/admin/backups' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 0777 ${WWWDIR}/admin/images/graphs' >> ${TMPPLIST}

post-install:
	@if [ ! -f ${WWWDIR}/includes/configure.php ]; then \
		${CP} -p ${WWWDIR}/includes/dist-configure.php ${WWWDIR}/includes/configure.php ; \
	fi

	@if [ ! -f ${WWWDIR}/admin/includes/configure.php ]; then \
		${CP} -p ${WWWDIR}/admin/includes/dist-configure.php ${WWWDIR}/admin/includes/configure.php ; \
	fi

.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
