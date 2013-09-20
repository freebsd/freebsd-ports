# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	helma
PORTVERSION=	1.7.0
CATEGORIES=	www java
MASTER_SITES=	http://adele.helma.org/download/helma/${PORTVERSION}/ \
		LOCAL/decke
DISTFILES=	helma-${PORTVERSION}.tar.gz helma-${PORTVERSION}-src.tar.gz

MAINTAINER=	decke@FreeBSD.org
COMMENT=	A Web application framework for fast and efficient scripting

WRKBASE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKBASE}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

USE_RC_SUBR=	helma
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
ALL_TARGET=	clean jar

DBDIR?=		/var/db/${PORTNAME}
LOGDIR?=	/var/log/${PORTNAME}
HELMA_USER=	${WWWOWN}
HELMA_GROUP=	${WWWGRP}
HELMA_CONFIG=	${WRKBASE}/scripts/helma.conf

PLIST_SUB=	DBDIR="${DBDIR}" \
		LOGDIR="${LOGDIR}" \
		HELMA_USER="${HELMA_USER}" \
		HELMA_GROUP="${HELMA_GROUP}"

OPTIONS_DEFINE=	MYSQL
OPTIONS_DESC=	"Install MySQL Connector for Java"

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${JAVALIBDIR}/mysql-connector-java.jar:${PORTSDIR}/databases/mysql-connector-java
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

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
	${INSTALL_SCRIPT} ${FILESDIR}/helma.sh.in ${PREFIX}/bin/helma

	${MKDIR} ${WWWDIR} && \
	(cd ${WRKBASE} && ${COPYTREE_SHARE} "apps modules" ${WWWDIR} \
		"! -name *.html ! -name helma-*.jar ! -name .jsdoc") && \
	${CHOWN} -R ${HELMA_USER}:${HELMA_GROUP} ${WWWDIR}

	${MKDIR} ${DATADIR} && \
	(cd ${WRKBASE} && ${COPYTREE_SHARE} "lib launcher.jar" ${DATADIR} \
		"! -name *.html ! -name helma-*.jar ! -name .jsdoc")

	${MKDIR} ${LOGDIR} && \
	${CHOWN} -R ${HELMA_USER}:${HELMA_GROUP} ${LOGDIR}

	${MKDIR} ${DBDIR} && \
	${CHOWN} -R ${HELMA_USER}:${HELMA_GROUP} ${DBDIR}

	${MKDIR} ${ETCDIR}; \
	for f in apps.properties db.properties server.properties scripts/helma.conf; do \
		${INSTALL_DATA} ${WRKBASE}/$$f ${ETCDIR}/$${f##*/}.sample; \
		if [ ! -f ${ETCDIR}/$${f##*/} ]; then \
		${CP} -p ${ETCDIR}/$${f##*/}.sample ${ETCDIR}/$${f##*/}; \
		fi; \
	done

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} && \
	(cd ${WRKBASE} && ${COPYTREE_SHARE} "licenses license.txt README.txt" ${DOCSDIR})

	${MKDIR} ${DOCSDIR}/docs/api/jala && \
	(cd ${WRKBASE}/modules/jala/docs && ${COPYTREE_SHARE} \* ${DOCSDIR}/docs/api/jala)
.endif

.if ${PORT_OPTIONS:MMYSQL}
	${LN} -sf ${JAVALIBDIR}/mysql-connector-java.jar ${DATADIR}/lib/ext/mysql-connector-java.jar
.endif

.include <bsd.port.post.mk>
