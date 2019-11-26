# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	helma
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	http://adele.helma.org/download/helma/${PORTVERSION}/ \
		LOCAL/decke
DISTFILES=	helma-${PORTVERSION}.tar.gz helma-${PORTVERSION}-src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web application framework for fast and efficient scripting

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKBASE}/licenses/license.txt

WRKBASE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKBASE}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

USE_RC_SUBR=	helma
USE_JAVA=	yes
USE_ANT=	yes
ALL_TARGET=	clean jar
NO_ARCH=	yes

DBDIR?=		/var/db/${PORTNAME}
LOGDIR?=	/var/log/${PORTNAME}
HELMA_USER=	${WWWOWN}
HELMA_GROUP=	${WWWGRP}
HELMA_CONFIG=	${WRKBASE}/scripts/helma.conf

PLIST_SUB=	DBDIR="${DBDIR}" \
		LOGDIR="${LOGDIR}" \
		HELMA_USER="${HELMA_USER}" \
		HELMA_GROUP="${HELMA_GROUP}"

OPTIONS_DEFINE=	MYSQL DOCS
OPTIONS_SUB=	yes
MYSQL_DESC=	Install MySQL Connector for Java

MYSQL_RUN_DEPENDS=	${JAVALIBDIR}/mysql-connector-java.jar:databases/mysql-connector-java

post-patch:
	@${REINPLACE_CMD} -e 's|JAVA_HOME=/usr/lib/j2sdk1.5-sun|JAVA_HOME=${JAVA_HOME}|' \
		${HELMA_CONFIG}
	@${REINPLACE_CMD} -e 's|HELMA_INSTALL=/usr/local/helma/helma-1.6.x|HELMA_INSTALL=${DATADIR}|' \
		${HELMA_CONFIG}
	@${REINPLACE_CMD} -e 's|HELMA_HOME=\$$HELMA_INSTALL|HELMA_HOME=${WWWDIR}|' \
		${HELMA_CONFIG}
	@${REINPLACE_CMD} -e 's|HELMA_USER=helma|HELMA_USER=${HELMA_USER}|' \
		${HELMA_CONFIG}
	@${REINPLACE_CMD} -e 's|HELMA_LOG=\$$HELMA_HOME/log/helma-out.log|HELMA_LOG=${LOGDIR}/helma-out.log|' \
		${HELMA_CONFIG}
	@${ECHO_CMD} "HELMA_CONFIG=${ETCDIR}" >> \
		${HELMA_CONFIG}

	@${ECHO_CMD} "" >> \
		${WRKBASE}/server.properties
	@${ECHO_CMD} "# custom directories" >> \
		${WRKBASE}/server.properties
	@${ECHO_CMD} "hopHome = ${WWWDIR}" >> \
		${WRKBASE}/server.properties
	@${ECHO_CMD} "appHome = ${WWWDIR}/apps" >> \
		${WRKBASE}/server.properties
	@${ECHO_CMD} "appsPropFile = ${ETCDIR}/apps.properties" >> \
		${WRKBASE}/server.properties
	@${ECHO_CMD} "dbPropFile = ${ETCDIR}/db.properties" >> \
		${WRKBASE}/server.properties
	@${ECHO_CMD} "dbHome = ${DBDIR}" >> \
		${WRKBASE}/server.properties
	@${REINPLACE_CMD} -e 's|# logDir = console|logDir = ${LOGDIR}|' \
		${WRKBASE}/server.properties

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/helma.sh.in ${STAGEDIR}${PREFIX}/bin/helma

	${MKDIR} ${STAGEDIR}${WWWDIR} && \
	(cd ${WRKBASE} && ${COPYTREE_SHARE} "apps modules" ${STAGEDIR}${WWWDIR} \
		"! -name *.html ! -name helma-*.jar ! -name .jsdoc")

	${MKDIR} ${STAGEDIR}${DATADIR} && \
	(cd ${WRKBASE} && ${COPYTREE_SHARE} "lib launcher.jar" ${STAGEDIR}${DATADIR} \
		"! -name *.html ! -name helma-*.jar ! -name .jsdoc")

	${MKDIR} ${STAGEDIR}${LOGDIR}

	${MKDIR} ${STAGEDIR}${DBDIR}

	${MKDIR} ${STAGEDIR}${ETCDIR}; \
	for f in apps.properties db.properties server.properties scripts/helma.conf; do \
		${INSTALL_DATA} ${WRKBASE}/$$f ${STAGEDIR}${ETCDIR}/$${f##*/}.sample; \
	done

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	(cd ${WRKBASE} && ${COPYTREE_SHARE} "licenses license.txt README.txt" ${STAGEDIR}${DOCSDIR})

	${MKDIR} ${STAGEDIR}${DOCSDIR}/docs/api/jala && \
	(cd ${WRKBASE}/modules/jala/docs && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/docs/api/jala)

do-install-MYSQL-on:
	${LN} -sf ${JAVALIBDIR}/mysql-connector-java.jar ${STAGEDIR}${DATADIR}/lib/ext/mysql-connector-java.jar

.include <bsd.port.mk>
