#-*- mode: makefile; tab-width: 4; -*
# ex:ts=4
#
# Maintainers:  Beech Rintoul <beech@alaskaparadise.com>,
#				Andrew Pantyukhin <infofarmer@FreeBSD.org>
#

MASTER_SITES?=		HORDE
DISTVERSIONPREFIX?=	h3-

.if defined(USE_HORDE) && ${USE_HORDE:Mbase}
RUN_DEPENDS+=	${HORBAS}/rpc.php:${PORTSDIR}/www/horde-base
.endif

#USE_BZIP2=	yes
NO_BUILD=	yes

PEARDIR?=	${LOCALBASE}/share/pear
PORTREV_H?=	${LOCALBASE}/include/c-client/portrevision.h
HORBAS?=	${PREFIX}/www/horde
HORDIR?=	${HORBAS}${PORTNAME:S|^|/|:S|/horde||}
HORCFG?=	${HORDIR}/config
HORLOG?=	/var/log/horde.log
PKGDEINSTALL?=	${WRKDIR}/pkg-deinstall
PKGINSTALL?=	${WRKDIR}/pkg-install
PLIST_SUB+=	HORDIR=${HORDIR:S|^${PREFIX}/||} HORBAS=${HORBAS:S|^${PREFIX}/||}
SUB_LIST+=	HORDIR=${HORDIR} HORBAS=${HORBAS} PORTSDIR=${PORTSDIR} HORDEADMUSR=${HORDEADMUSR}\
			HORDEGRP=${WWWGRP} HORCFG=${HORCFG} PORTNAME=${PORTNAME}
PKGMESSAGE?=	${WRKDIR}/pkg-message
.if !defined(USE_HORDE) || !${USE_HORDE:Mpkg-message}
SUB_FILES?=		pkg-message
.endif

.if defined(WITH_SUPHP) && !defined(WITHOUT_SUPHP)
RUN_DEPENDS+=	${LOCALBASE}/sbin/suphp:${PORTSDIR}/www/suphp
WANT_PHP_CGI=	yes
HORDEADMUSR?=	horde
SUB_LIST+=		WITH_SUPHP=yes
.else
WANT_PHP_WEB=	yes
.endif

HOSTNAME?=	`/bin/hostname`
SERVOS?=	${OPSYS}-${OSREL}

.if !target(post-extract)
post-extract:
	@${RM} -f ${WRKSRC}/COPYING ${WRKSRC}/LICENSE
	@${MV} ${WRKSRC}/README ${WRKSRC}/docs/
	@${MV} ${WRKSRC}/docs ${WRKDIR}/
.endif

.if !target(post-patch)
post-patch:
.	for file in pkg-deinstall pkg-install
	@${SED} ${_SUB_LIST_TEMP} -e '/^@comment /d' ${.CURDIR}/../../www/horde-base/files/${file}.in > ${WRKDIR}/${file}
.	endfor
.	if defined(USE_HORDE) && ${USE_HORDE:Mpkg-message}
	@${SED} ${_SUB_LIST_TEMP} -e '/^@comment /d' ${.CURDIR}/../../www/horde-base/files/pkg-message.common.in >\
		${WRKDIR}/pkg-message
.	endif
	@${EGREP} -lr '(/usr/local|%%LOCALBASE%%|/tmp/horde.log)' ${WRKSRC}/config/ |\
		${XARGS} ${REINPLACE_CMD} -Ee 's:(/usr/local|%%LOCALBASE%%):${LOCALBASE}:;s|/tmp/horde.log|${HORLOG}|'
	@if [ -d ${WRKSRC}/scripts ]; then\
		${EGREP} -lr '(/usr/local/bin/php|usr/bin/php)' ${WRKSRC}/scripts/ |\
   		${XARGS} ${REINPLACE_CMD} -Ee 's:(/usr/local/bin/php|/usr/bin/php):${LOCALBASE}/bin/php:'; fi
# Copy RCSID tag from conf.xml into conf.php to stop Horde complaining
	@if [ -f ${WRKSRC}/config/conf.php.dist ] &&\
	! ${GREP} -qe "$$Horde:.*conf\.xml" ${WRKSRC}/config/conf.php.dist; then \
		${GREP} -hm1 "$$Horde:.*conf\.xml" ${WRKSRC}/config/conf.xml |\
		${SED} -e 's#^ *<!--#//#;s# *--> *$$##g' \
		>> ${WRKSRC}/config/conf.php.dist; \
	fi
.endif

.if !target(post-configure)
post-configure:
	@${FIND} ${WRKSRC} -name \*.orig -delete -or -name \*.bak -delete
.endif

.if !target(do-install)
do-install:
	@${INSTALL} -d ${HORDIR}/
	@${CP} -Rp ${WRKSRC}/ ${HORDIR}/
	@${TOUCH} ${HORLOG}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${HORDIR}/ ${HORLOG}
	@${CHMOD} -R o-rwx ${HORDIR}/ ${HORLOG}
	@${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} @exec ${CHMOD} -R o-rwx %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${TOUCH} ${HORLOG};${CHOWN} ${WWWOWN}:${WWWGRP} ${HORLOG}" >> ${TMPPLIST}
.if ${HORBAS} == ${HORDIR}
	@${ECHO_CMD} "@unexec if [ ! -s ${HORLOG} ];then ${RM} -f ${HORLOG};fi" >> ${TMPPLIST}
.endif
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKDIR}/docs/|} ${DOCSDIR}/
.endif
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

horde-plist:	extract
	@${FIND} -s ${WRKSRC} -not -type d | ${SED} -e 's|^${WRKSRC}|%%HORDIR%%|' > ${PLIST}
	@${FIND} -ds ${WRKSRC} -type d -not -name ${DISTNAME} -empty |\
		${SED} -e 's|^${WRKSRC}|@exec mkdir -p %D/%%HORDIR%%|' >> ${PLIST}
	@${FIND} -ds ${WRKSRC} -type d -not -name ${DISTNAME} |\
		${SED} -e 's|^${WRKSRC}|@dirrm %%HORDIR%%|' |\
		${SED} -Ee '/%(\/lib\/data|\/config)/s|dirrm|dirrmtry|' >> ${PLIST}
	@${ECHO_CMD} @dirrmtry %%HORDIR%% >> ${PLIST}
	@${ECHO_CMD} @dirrmtry %%HORBAS%% >> ${PLIST}
