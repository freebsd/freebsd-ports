# Created by: KIKUCHI Koichiro <koichiro@rworks.jp>
# $FreeBSD$

PORTNAME=	pandora_console
PORTVERSION=	${PANDORA_VERSION}
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	koichiro@rworks.jp
COMMENT=	Pandora FMS console

LICENSE=	${PANDORA_LICENSE}
LICENSE_FILE=	${PANDORA_LICENSE_FILE}

RUN_DEPENDS=	${LOCALBASE}/bin/twopi:${PORTSDIR}/graphics/graphviz

OPTIONS_DEFINE=	PGSQL
PGSQL_DESC=	Use PostgreSQL backend (experimental)

USE_APACHE_RUN=	22+
USE_PHP=	curl gd gettext json ldap mbstring mysql snmp session \
		xml zip zlib
WANT_PHP_WEB=	yes

SUB_FILES+=	pandora_console.conf
SUB_LIST+=	APACHEETCDIR=${PREFIX}/${APACHEETCDIR}

NO_STAGE=	yes
.include "${.CURDIR}/../pandorafms_server/bsd.pandora.mk"

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "s|%%WWWDIR%%|${WWWDIR}|g" \
		${WRKSRC}/pandora_console_install
	@${REINPLACE_CMD} \
		-e "s|/usr/bin|${LOCALBASE}/bin|g" \
		${WRKSRC}/pandoradb.data*.sql
	@${REINPLACE_CMD} \
		-e 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/extras/check_other_languages.sh \
		${WRKSRC}/include/languages/extract_newlines.sh

do-install:
	@cd ${WRKSRC} && ${SH} pandora_console_install --force-install

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for x in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${x} ${DOCSDIR}
.endfor
.endif
	@cd ${WWWDIR} \
		&& ${RM} -rf pandora_console_install* \
			pandora_console_upgrade *.spec \
			extras/check_other_languages.sh.bak \
			include/languages/extract_newlines.sh.bak \
			*.sql.bak COPYING ${PORTDOCS} DEBIAN/
	@if [ -e ${WWWDIR}/include/config.php ]; then \
		${MV} ${WWWDIR}/install.php ${WWWDIR}/install.done; \
	fi;
	@${MKDIR} ${PREFIX}/${APACHEETCDIR}/Includes
	@${INSTALL_DATA} ${WRKDIR}/pandora_console.conf \
		${PREFIX}/${APACHEETCDIR}/Includes/pandora_console.conf
	@${LN} -sf ${_LICENSE_DIR}/${LICENSE} ${WWWDIR}/COPYING

.include <bsd.port.post.mk>
