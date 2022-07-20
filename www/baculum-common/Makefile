PORTNAME=	baculum
PORTVERSION=	11.0.6
CATEGORIES?=	www
MASTER_SITES=	SF/bacula/bacula/${PORTVERSION}
PKGNAMESUFFIX?=	-common
DISTNAME=	bacula-gui-${PORTVERSION}

MAINTAINER=	sipopo@yandex.ru
COMMENT?=	common libraries for baculum

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/${PORTNAME}/LICENSE

USES+=		php
PHP_VER=	74

BCL_VARDIR?=	/var
BCL_CACHEDIR?=	${BCL_VARDIR}/cache/${PORTNAME}
BCL_LOGDIR?=	${BCL_VARDIR}/log/${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

USE_PHP+=	ctype dom json session xml

OPTIONS_DEFINE?=EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=       pdo_mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=       pdo_pgsql
.endif

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/htdocs/protected/Common
	${MKDIR} ${STAGEDIR}${WWWDIR}/htdocs/protected/vendor
	${MKDIR} ${STAGEDIR}${WWWDIR}/htdocs/themes
	${MKDIR} ${STAGEDIR}${BCL_CACHEDIR}
	${MKDIR} ${STAGEDIR}${BCL_LOGDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}/Config
.if ${PKGNAMESUFFIX} == "-common"
	${CP} -R ${WRKSRC}/${PORTNAME}/protected/Common ${STAGEDIR}${WWWDIR}/htdocs/protected
	${CP} -R ${WRKSRC}/${PORTNAME}/protected/vendor ${STAGEDIR}${WWWDIR}/htdocs/protected
	${CP} ${WRKSRC}/${PORTNAME}/protected/application.xml ${STAGEDIR}${WWWDIR}/htdocs/protected
	${CP} ${WRKSRC}/${PORTNAME}/protected/autoload.php ${STAGEDIR}${WWWDIR}/htdocs/protected
	${CP} -R ${WRKSRC}/${PORTNAME}/themes ${STAGEDIR}${WWWDIR}/htdocs
	${RLN} ${STAGEDIR}${BCL_CACHEDIR} ${STAGEDIR}${WWWDIR}/htdocs/protected/runtime
	${RLN} ${STAGEDIR}${BCL_CACHEDIR} ${STAGEDIR}${WWWDIR}/htdocs/assets

.for i in AUTHORS INSTALL LICENSE LICENSE-FOSS README ReleaseNotes UPGRADE index.php
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${i} ${STAGEDIR}${WWWDIR}/htdocs/${i}
.endfor
.endif

.if ${PKGNAMESUFFIX} == "-api"
	${MKDIR} ${STAGEDIR}${ETCDIR}/Config/API
	${CP} -R ${WRKSRC}/${PORTNAME}/protected/API ${STAGEDIR}${WWWDIR}/htdocs/protected
	${RM} -Rf ${STAGEDIR}${WWWDIR}/htdocs/protected/API/Config
	${RM} -Rf ${STAGEDIR}${WWWDIR}/htdocs/protected/API/Logs
	${RLN} ${STAGEDIR}${BCL_LOGDIR} ${STAGEDIR}${WWWDIR}/htdocs/protected/API/Logs
	${RLN} ${STAGEDIR}${ETCDIR}/Config/API ${STAGEDIR}${WWWDIR}/htdocs/protected/API/Config
.endif
.if ${PKGNAMESUFFIX} == "-web"
	${MKDIR} ${STAGEDIR}${ETCDIR}/Config/WEB
	${CP} -R ${WRKSRC}/${PORTNAME}/protected/Web ${STAGEDIR}${WWWDIR}/htdocs/protected
	${RM} -Rf ${STAGEDIR}${WWWDIR}/htdocs/protected/Web/Config
	${RM} -Rf ${STAGEDIR}${WWWDIR}/htdocs/protected/Web/Logs
	${RLN} ${STAGEDIR}${BCL_LOGDIR} ${STAGEDIR}${WWWDIR}/htdocs/protected/Web/Logs
	${RLN} ${STAGEDIR}${ETCDIR}/Config/WEB ${STAGEDIR}${WWWDIR}/htdocs/protected/Web/Config
.endif

	@${ECHO_CMD} \
		'@postexec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/htdocs' \
		>> ${TMPPLIST}
	@${ECHO_CMD} \
		'@postexec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${BCL_LOGDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} \
		'@postexec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${BCL_CACHEDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} \
		'@postexec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${ETCDIR}' \
		>> ${TMPPLIST}

post-install:
.if ${PKGNAMESUFFIX} == "-common"
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/${PORTNAME}/examples/sudo ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/${PORTNAME}/examples/deb/*conf ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
