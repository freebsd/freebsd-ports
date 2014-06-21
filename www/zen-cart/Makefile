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
USES=		dos2unix zip
USE_PHP=	yes
WANT_PHP_WEB=	yes
DOS2UNIX_REGEX=	.*\.php

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	WWWDIR="${WWWDIR}" PORTNAME="${PORTNAME}"
PLIST_SUB+=	WWWDIR=${WWWDIR} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} EXAMPLESDIR_REL=${EXAMPLESDIR_REL} \
			PORTNAME=${PORTNAME}

do-install:
	@if [ ! -d ${STAGEDIR}${WWWDIR} ]; then ${MKDIR} ${STAGEDIR}${WWWDIR} ; fi
	@cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${EXAMPLESDIR} && ${RM} -rf ${WRKSRC}/docs
	@cd ${WRKSRC} && ${MV} vbv_learn_more.html ${STAGEDIR}${EXAMPLESDIR}/
	@cd ${WRKSRC} && ${MV} mcs_learn_more.html ${STAGEDIR}${EXAMPLESDIR}/
	@cd ${WRKSRC} && ${MV} robots_example.txt ${STAGEDIR}${EXAMPLESDIR}/
	@cd ${WRKSRC} && ${MV} install.txt ${STAGEDIR}${EXAMPLESDIR}/
	@cd ${WRKSRC} && ${MV} nddbc.html ${STAGEDIR}${EXAMPLESDIR}/
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	@${CHMOD} -R 0755 ${STAGEDIR}${WWWDIR}
	@${CHMOD} 0777 ${STAGEDIR}${WWWDIR}/cache
	@cd ${STAGEDIR}${WWWDIR}/images && ${FIND} . -type d -exec ${CHMOD} 0777 {} \;
	@cd ${STAGEDIR}${WWWDIR}/includes/languages/english && ${FIND} html_includes -type d -exec ${CHMOD} 0777 {} \;
	@${CHMOD} 0777 ${STAGEDIR}${WWWDIR}/media
	@${CHMOD} 0777 ${STAGEDIR}${WWWDIR}/pub
	@${CHMOD} 0777 ${STAGEDIR}${WWWDIR}/admin/backups
	@${CHMOD} 0777 ${STAGEDIR}${WWWDIR}/admin/images/graphs
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 0755 ${WWWDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 0777 ${WWWDIR}/cache' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec cd ${WWWDIR}/images && ${FIND} . -type d -exec ${CHMOD} 0777 {} \;' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec cd ${WWWDIR}/includes/languages/english && ${FIND} html_includes -type d -exec ${CHMOD} 0777 {} \;' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 0777 ${WWWDIR}/media' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 0777 ${WWWDIR}/pub' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 0777 ${WWWDIR}/admin/backups' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 0777 ${WWWDIR}/admin/images/graphs' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec if cmp -s ${WWWDIR}/includes/configure.php ${WWWDIR}/includes/dist-configure.php; then rm -f ${WWWDIR}/includes/configure.php; fi' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec cp -n ${WWWDIR}/includes/dist-configure.php ${WWWDIR}/includes/configure.php' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec if cmp -s ${WWWDIR}/admin/includes/configure.php ${WWWDIR}/admin/includes/dist-configure.php; then rm -f ${WWWDIR}/admin/includes/configure.php; fi' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec cp -n ${WWWDIR}/admin/includes/dist-configure.php ${WWWDIR}/admin/includes/configure.php' >> ${TMPPLIST}

.include <bsd.port.mk>
