# Created by: KIKUCHI Koichiro <koichiro@rworks.jp>
# $FreeBSD$

PORTNAME=	pandora_console
CATEGORIES=	net-mgmt

MAINTAINER=	koichiro@rworks.jp
COMMENT=	Pandora FMS console

LICENSE=	${PANDORA_LICENSE}
LICENSE_FILE=	${PANDORA_LICENSE_FILE}

RUN_DEPENDS=	${LOCALBASE}/bin/twopi:graphics/graphviz

USES=		shebangfix
SHEBANG_FILES=	include/languages/extract_newlines.sh \
		include/languages/util-all \
		include/languages/util-bzr-update \
		include/languages/util-compile-mo \
		include/languages/util-create-po \
		include/languages/util-create-template \
		include/languages/util-generate-tarball \
		include/languages/util-update-po \
		pandora_console_upgrade

OPTIONS_DEFINE=	DOCS PGSQL
DOCS_DESC=	Install AUTHORS and ChangeLog
PGSQL_DESC=	Use PostgreSQL backend (experimental)

USE_PHP=	curl filter gd gettext hash json ldap mbstring mysql \
		snmp session xml zip zlib
WANT_PHP_WEB=	yes
USE_APACHE_RUN=	22+

SUB_FILES+=	pandora_console.conf pkg-message newsyslog.conf
SUB_LIST+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

PGSQL_USE=	PHP=pgsql

.include "${.CURDIR}/../pandorafms_server/bsd.pandora.mk"

PORTREVISION=	2

PANDORA_INSTALLER_ARGS+=	--destdir ${STAGEDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e "\|PANDORA_HOME=|s|=[^;]*|=${WWWDIR}|g" \
		${WRKSRC}/pandora_console_install
	@${REINPLACE_CMD} \
		-e "s|/usr/bin|${LOCALBASE}/bin|g" \
		${WRKSRC}/pandoradb.data*.sql
	@${REINPLACE_CMD} \
		-e 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/extras/check_other_languages.sh

post-install:
	@cd ${STAGEDIR}${WWWDIR} \
		&& ${RM} -rf pandora_console_[il]* DEBIAN/ *.spec \
			attachment/downloads/.gitignore ${PORTDOCS} \
			Dockerfile docker_entrypoint.sh \
			*.sql.bak extras/check_other_languages.sh.bak
	@cd ${STAGEDIR}${WWWDIR} && ${MV} install.php install_old.php
	@(d=${STAGEDIR}${PREFIX}/${APACHEETCDIR}/Includes; ${MKDIR} $$d; \
		${INSTALL_DATA} ${WRKDIR}/pandora_console.conf \
			$$d/pandora_console.conf.sample)
	@(d=${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d; ${MKDIR} $$d; \
		${INSTALL_DATA} ${WRKDIR}/newsyslog.conf \
			$$d/pandora_console.conf)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${x} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
