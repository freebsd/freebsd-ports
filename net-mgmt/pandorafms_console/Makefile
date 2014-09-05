# Created by: KIKUCHI Koichiro <koichiro@rworks.jp>
# $FreeBSD$

PORTNAME=	pandora_console
CATEGORIES=	net-mgmt

MAINTAINER=	koichiro@rworks.jp
COMMENT=	Pandora FMS console

LICENSE=	${PANDORA_LICENSE}
LICENSE_FILE=	${PANDORA_LICENSE_FILE}

RUN_DEPENDS=	${LOCALBASE}/bin/twopi:${PORTSDIR}/graphics/graphviz

OPTIONS_DEFINE=	DOCS PGSQL
DOCS_DESC=	Install AUTHORS and ChangeLog
PGSQL_DESC=	Use PostgreSQL backend (experimental)

USE_PHP=	curl gd gettext json ldap mbstring mysql snmp session \
		xml zip zlib
WANT_PHP_WEB=	yes
USE_APACHE_RUN=	22+

SUB_FILES+=	pandora_console.conf pkg-message

.include "${.CURDIR}/../pandorafms_server/bsd.pandora.mk"

PANDORA_INSTALLER_ARGS+=	--destdir ${STAGEDIR}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "\|PANDORA_HOME=|s|=[^;]*|=${WWWDIR}|g" \
		${WRKSRC}/pandora_console_install
	@${REINPLACE_CMD} \
		-e "s|/usr/bin|${LOCALBASE}/bin|g" \
		${WRKSRC}/pandoradb.data*.sql
	@${REINPLACE_CMD} \
		-e 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/extras/check_other_languages.sh \
		${WRKSRC}/include/languages/extract_newlines.sh

post-install:
	@cd ${STAGEDIR}${WWWDIR} \
		&& ${RM} -rf pandora_console_install* *.spec \
			extras/check_other_languages.sh.bak \
			include/languages/extract_newlines.sh.bak \
			*.sql.bak COPYING ${PORTDOCS} DEBIAN/
	@cd ${STAGEDIR}${WWWDIR} && ${MV} install.php install.done
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${x} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	@${MKDIR} -p ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/Includes
	@${INSTALL_DATA} ${WRKDIR}/pandora_console.conf \
		${STAGEDIR}${PREFIX}/${APACHEETCDIR}/Includes/pandora_console.conf.sample
	@${LN} -sf ${_LICENSE_DIR}/${LICENSE} ${STAGEDIR}${WWWDIR}/COPYING

.include <bsd.port.post.mk>
